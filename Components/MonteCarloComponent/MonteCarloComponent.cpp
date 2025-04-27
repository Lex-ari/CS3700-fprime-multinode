// ======================================================================
// \title  MonteCarloComponent.cpp
// \brief  Component for Monte Carlo placeholder. Use fprime-util impl
// ======================================================================

#include "MonteCarloComponent.hpp"
#include <chrono>
#include <cstdlib>

namespace Components {

void MonteCarloComponent :: AmountIn_handler(
    const NATIVE_INT_TYPE portNum,
    U32 amount
) {
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = now.time_since_epoch();
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
    srand(static_cast<unsigned int>(ns));

        U32 inner = 0;
        for (U32 i=0;i<amount;i++) {
            F32 x = static_cast<F32>(rand())/RAND_MAX;
            F32 y = static_cast<F32>(rand())/RAND_MAX;
            if (x * x + y * y <= 1.0f) {
                inner++;
            }
        }
        F32 piEstimate = 4.0f * inner/amount;
        this->ResultOut_out(0, piEstimate);
   }
}
