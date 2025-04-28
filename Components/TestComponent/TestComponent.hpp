// ======================================================================
// \title  TestComponent.hpp
// \author oreomilkshake
// \brief  hpp file for TestComponent component implementation class
// ======================================================================

#ifndef Components_TestComponent_HPP
#define Components_TestComponent_HPP

#include "Components/TestComponent/TestComponentComponentAc.hpp"

namespace Components {

  class TestComponent :
    public TestComponentComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct TestComponent object
      TestComponent(
          const char* const compName //!< The component name
      );

      //! Destroy TestComponent object
      ~TestComponent();

  };

}

#endif
