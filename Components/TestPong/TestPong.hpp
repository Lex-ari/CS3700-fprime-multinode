// ======================================================================
// \title  TestPong.hpp
// \author oreomilkshake
// \brief  hpp file for TestPong component implementation class
// ======================================================================

#ifndef Components_TestPong_HPP
#define Components_TestPong_HPP

#include "Components/TestPong/TestPongComponentAc.hpp"

namespace Components {

  class TestPong :
    public TestPongComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct TestPong object
      TestPong(
          const char* const compName //!< The component name
      );

      //! Destroy TestPong object
      ~TestPong();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for pong
      void pong_handler(
          FwIndexType portNum, //!< The port number
          U8 nodeID
      ) override;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command TODO
      //!
      //! TODO
      void TODO_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq //!< The command sequence number
      ) override;

  };

}

#endif
