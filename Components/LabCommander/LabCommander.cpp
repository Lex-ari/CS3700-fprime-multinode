// ======================================================================
// \title  LabCommander.cpp
// \author oreomilkshake
// \brief  cpp file for LabCommander component implementation class
// ======================================================================

#include "Components/LabCommander/LabCommander.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  LabCommander ::
    LabCommander(const char* const compName) :
      LabCommanderComponentBase(compName)
  {

  }

  LabCommander ::
    ~LabCommander()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for typed input ports
  // ----------------------------------------------------------------------

  void LabCommander ::
    monteCarloInPort_handler(
        FwIndexType portNum,
        U32 positive_hits,
        U8 nodeID
    )
  {
    // TODO
    this->log_ACTIVITY_HI_ReceivedPositivePoints(positive_hits, portNum);
    this->m_totalPositiveHits += positive_hits;
    this->m_totalNodeHits++;

    Fw::ParamValid isValid = Fw::ParamValid::INVALID;
    const U32 numNodes = this->paramGet_NUMBER_NODES(isValid);
    FW_ASSERT(isValid == Fw::ParamValid::VALID, static_cast<FwAssertArgType>(isValid));

    if (this->m_totalNodeHits != numNodes)
    {
      this->log_ACTIVITY_HI_WaitingForAllNodesToFinish();
      return;
    }

    F32 piEstimate = 4.0f * this->m_totalPositiveHits / this->m_numberTotalPoints;
    this->log_ACTIVITY_HI_Result(this->m_numberTotalPoints, this->m_totalPositiveHits, piEstimate);


  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void LabCommander ::
    SET_MONTE_CARLO_POINTS_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        U32 total_points
    )
  {
    this->m_numberTotalPoints = total_points;
    this->tlmWrite_TotalPoints(this->m_numberTotalPoints);
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

  void LabCommander ::
    START_MONTE_CARLO_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    Fw::ParamValid isValid = Fw::ParamValid::INVALID;
    const U32 numNodes = this->paramGet_NUMBER_NODES(isValid);
    FW_ASSERT(isValid == Fw::ParamValid::VALID, static_cast<FwAssertArgType>(isValid));
    
    U32 pointsPerNode = this->m_numberTotalPoints / numNodes;
    U32 remainder = this->m_numberTotalPoints % numNodes;
    this->m_totalPositiveHits = 0;
    this->m_totalNodeHits = 0;

    for (int i = 0; i < numNodes; i++)
    {
      U32 points = pointsPerNode;
      if (i == 0)
      {
        points += remainder;
      }
      this->monteCarloOutPort_out(i, points, i);
      this->log_ACTIVITY_HI_SendTask(points, i);

    }
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
