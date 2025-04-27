// ======================================================================
// \title  TestPong.cpp
// \author oreomilkshake
// \brief  cpp file for TestPong component implementation class
// ======================================================================

#include "Components/TestPong/TestPong.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  TestPong ::
    TestPong(const char* const compName) :
      TestPongComponentBase(compName)
  {

  }

  TestPong ::
    ~TestPong()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void TestPong ::
    TODO_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
