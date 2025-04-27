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
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void TestPing ::
    TODO_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
