module Components {
    @ Component for F Prime FSW framework.
    active component LabCommander {

        @ Setting the amount of points to divide between the active deployments
        async command SET_MONTE_CARLO_POINTS(total_points: U32) opcode 0

        @ Command to Start Monte Carlo on All Nodes
        async command START_MONTE_CARLO() opcode 1

        output port monteCarloOutPort: [10] AmountInPort
        # output port monteCarloOutPort_1: AmountInPort
        # output port monteCarloOutPort_2: AmountInPort

        async input port monteCarloInPort: [10] PositiveHits

        event SetMonteCarloPoints(total_points: U32) severity activity high id 0 format "Set total points to {}"

        event ReceivedPositivePoints(positive_points: U32, node_id: U8) severity activity high id 1 format "Received {} hits from node {}"

        event WaitingForAllNodesToFinish() severity activity high id 2 format "Waiting on other nodes to finish..."

        event Result(total_points:U32, positive_points: U32, estimated_pi: F32) severity activity high id 3 format "Total Points: {}, Positive Hits: {}, Estimated_Pi: {}"
        
        event SendTask(total_points: U32, node_id: U8) severity activity high id 4 format "Sent Task to compute {} points to node {}"
        
        param NUMBER_NODES: U32 default 3

        telemetry PositiveHits: U32
        
        telemetry TotalPoints: U32
        
        
        ##############################################################################
        #### Uncomment the following examples to start customizing your component ####
        ##############################################################################

        # @ Example async command
        # async command COMMAND_NAME(param_name: U32)

        # @ Example telemetry counter
        # telemetry ExampleCounter: U64

        # @ Example event
        # event ExampleStateEvent(example_state: Fw.On) severity activity high id 0 format "State set to {}"

        # @ Example port: receiving calls from the rate group
        # sync input port run: Svc.Sched

        # @ Example parameter
        # param PARAMETER_NAME: U32

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
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