
module Components {
    @ Component for Monte Carlo

    passive component MonteCarloComponent {

        # Input: Amount of samples to generate
        sync input port AmountIn: Components.AmountInPort

        # Output: PI estimate result
        output port ResultOut: Components.ResultOutPort
   }

}

