// ======================================================================
// \title  MonteCarloComponent.hpp
// \author jeroldmanansala
// \brief  hpp file for MonteCarlo component implementation class
// ======================================================================

#ifndef Components_MonteCarloComponent_HPP
#define Components_MonteCarloComponent_HPP

#include "Components/MonteCarloComponent/MonteCarloComponentComponentAc.hpp"

namespace Components {

  class MonteCarloComponent :
    public MonteCarloComponentComponentBase
  {

    public:          
     //! Construct MonteCarloComponent object
     MonteCarloComponent(
          const char* const compName //!< The component name
      );

      //! Destroy MonteCarloComponent object
      ~MonteCarloComponent();

      PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for AmountIn
      void AmountIn_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          U32 amount //!< The amount of random samples
      ) override;

  };

}

#endif
