// ======================================================================
// \title  LabCommander.hpp
// \author oreomilkshake
// \brief  hpp file for LabCommander component implementation class
// ======================================================================

#ifndef Components_LabCommander_HPP
#define Components_LabCommander_HPP

#include "Components/LabCommander/LabCommanderComponentAc.hpp"

namespace Components {

  class LabCommander :
    public LabCommanderComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct LabCommander object
      LabCommander(
          const char* const compName //!< The component name
      );

      //! Destroy LabCommander object
      ~LabCommander();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for monteCarloInPort
      void monteCarloInPort_handler(
          FwIndexType portNum, //!< The port number
          U32 positive_hits,
          U8 nodeID
      ) override;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command SET_MONTE_CARLO_POINTS
      //!
      //! Setting the amount of points to divide between the active deployments
      void SET_MONTE_CARLO_POINTS_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          U32 total_points
      ) override;

      //! Handler implementation for command START_MONTE_CARLO
      //!
      //! Command to Start Monte Carlo on All Nodes
      void START_MONTE_CARLO_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq //!< The command sequence number
      ) override;

    PRIVATE:
      U32 m_totalPositiveHits = 0;
      U32 m_totalNodeHits = 0;
      U32 m_numberTotalPoints = 0;

  };

}

#endif
