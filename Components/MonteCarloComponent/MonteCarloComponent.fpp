
module Components {

    @ Component for Monte Carlo
    passive component MonteCarloComponent {

        # Input: Amount of samples to generate
        sync input port AmountIn: Components.AmountInPort

        # param NODE_ID: U8

        # Output: PI estimate result
        output port PositiveHits: Components.PositiveHits

        event ReceivedTask(total_points: U32) severity activity high id 0 format "Received Task to Monte Carlo {} points"

        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut
    }

}

