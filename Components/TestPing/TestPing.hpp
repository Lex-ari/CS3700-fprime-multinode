// ======================================================================
// \title  TestPing.hpp
// \author oreomilkshake
// \brief  hpp file for TestPing component implementation class
// ======================================================================

#ifndef Components_TestPing_HPP
#define Components_TestPing_HPP

#include "Components/TestPing/TestPingComponentAc.hpp"

namespace Components {

  class TestPing :
    public TestPingComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct TestPing object
      TestPing(
          const char* const compName //!< The component name
      );

      //! Destroy TestPing object
      ~TestPing();

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
