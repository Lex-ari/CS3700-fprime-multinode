// ======================================================================
// \title  TestPing.cpp
// \author oreomilkshake
// \brief  cpp file for TestPing component implementation class
// ======================================================================

#include "Components/TestPing/TestPing.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  TestPing ::
    TestPing(const char* const compName) :
      TestPingComponentBase(compName)
  {

  }

  TestPing ::
    ~TestPing()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for typed input ports
  // ----------------------------------------------------------------------

  void TestPing ::
    pong_handler(
        FwIndexType portNum,
        U16 nodeID
    )
  {
    this->log_ACTIVITY_HI_Pong(nodeID);
  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void TestPing ::
    PingNodes_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    this->ping0_out(0, 0);
    this->log_ACTIVITY_HI_Ping(0);
    this->ping1_out(0, 1);
    this->log_ACTIVITY_HI_Ping(1);
    this->ping2_out(0, 2);
    this->log_ACTIVITY_HI_Ping(2);
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
