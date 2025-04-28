// ======================================================================
// \title  MonteCarloComponent.cpp
// \brief  Component for Monte Carlo placeholder. Use fprime-util impl
// ======================================================================

#include "Components/MonteCarloComponent/MonteCarloComponent.hpp"
#include <chrono>
#include <cstdlib>
#include <iostream>

namespace Components {

// Constructor
MonteCarloComponent::MonteCarloComponent(const char* compName) :
    MonteCarloComponentComponentBase(compName)
{
}

// Destructor
MonteCarloComponent::~MonteCarloComponent() {
}


void MonteCarloComponent ::
    AmountIn_handler(
        FwIndexType portNum,
        U32 samples,
        U8 nodeID
    )
    {

        this->log_ACTIVITY_HI_ReceivedTask(samples);

        // Fw::ParamValid isValid = Fw::ParamValid::INVALID;
        // U32 node_id = this->paramGet_NODE_ID(isValid);
        // FW_ASSERT(isValid == Fw::ParamValid::VALID, static_cast<FwAssertArgType>(isValid));
        // if (nodeID != node_id)
        // {
        //     return;
        // }


        auto now = std::chrono::high_resolution_clock::now();
        auto duration = now.time_since_epoch();
        auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
        srand(static_cast<unsigned int>(ns));

        U32 inner = 0;
        for (U32 i=0;i<samples;i++) {
            F32 x = static_cast<F32>(rand())/RAND_MAX;
            F32 y = static_cast<F32>(rand())/RAND_MAX;
            if (x * x + y * y <= 1.0f) {
                inner++;
            }
            std::cerr << x << std::endl;
            std::cerr << y << std::endl;
        }

        this->PositiveHits_out(portNum, inner, nodeID);

            // F32 piEstimate = 4.0f * inner/amount;
            // this->ResultOut_out(0, piEstimate);
    }
}
