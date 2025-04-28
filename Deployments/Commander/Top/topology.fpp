module Commander {

  # ----------------------------------------------------------------------
  # Symbolic constants for port numbers
  # ----------------------------------------------------------------------

  enum Ports_RateGroups {
    rateGroup1
    rateGroup2
    rateGroup3
  }

  topology Commander {

    # ----------------------------------------------------------------------
    # Instances used in the topology
    # ----------------------------------------------------------------------

    instance $health
    instance blockDrv
    instance tlmSend
    instance cmdDisp
    instance cmdSeq
    instance comDriver
    instance comQueue
    instance comStub
    instance deframer
    instance eventLogger
    instance fatalAdapter
    instance fatalHandler
    instance fileDownlink
    instance fileManager
    instance fileUplink
    instance bufferManager
    instance framer
    instance chronoTime
    instance prmDb
    instance rateGroup1
    instance rateGroup2
    instance rateGroup3
    instance rateGroupDriver
    instance textLogger
    instance systemResources

    instance ping
    instance labCommander
    # instance monteCarloComponent

    # Hub Communication 
    instance hub_0
    instance hubComDriver_0
    instance hubComQueue_0
    instance hubDeframer_0
    instance hubFramer_0
    instance hub_1
    instance hubComDriver_1
    instance hubComQueue_1
    instance hubDeframer_1
    instance hubFramer_1
    instance hub_2
    instance hubComDriver_2
    instance hubComQueue_2
    instance hubDeframer_2
    instance hubFramer_2



    # ----------------------------------------------------------------------
    # Pattern graph specifiers
    # ----------------------------------------------------------------------

    command connections instance cmdDisp

    event connections instance eventLogger

    param connections instance prmDb

    telemetry connections instance tlmSend

    text event connections instance textLogger

    time connections instance chronoTime

    health connections instance $health

    # ----------------------------------------------------------------------
    # Direct graph specifiers
    # ----------------------------------------------------------------------

    connections Downlink {

      eventLogger.PktSend -> comQueue.comQueueIn[0]
      tlmSend.PktSend -> comQueue.comQueueIn[1]
      fileDownlink.bufferSendOut -> comQueue.buffQueueIn[0]

      comQueue.comQueueSend -> framer.comIn
      comQueue.buffQueueSend -> framer.bufferIn

      framer.framedAllocate -> bufferManager.bufferGetCallee
      framer.framedOut -> comStub.comDataIn
      framer.bufferDeallocate -> fileDownlink.bufferReturn

      comDriver.deallocate -> bufferManager.bufferSendIn
      comDriver.ready -> comStub.drvConnected

      comStub.comStatus -> framer.comStatusIn
      framer.comStatusOut -> comQueue.comStatusIn
      comStub.drvDataOut -> comDriver.$send

    }

    connections FaultProtection {
      eventLogger.FatalAnnounce -> fatalHandler.FatalReceive
    }

    connections RateGroups {
      # Block driver
      blockDrv.CycleOut -> rateGroupDriver.CycleIn

      # Rate group 1
      rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup1] -> rateGroup1.CycleIn
      rateGroup1.RateGroupMemberOut[0] -> tlmSend.Run
      rateGroup1.RateGroupMemberOut[1] -> fileDownlink.Run
      rateGroup1.RateGroupMemberOut[2] -> systemResources.run

      # Rate group 2
      rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup2] -> rateGroup2.CycleIn
      rateGroup2.RateGroupMemberOut[0] -> cmdSeq.schedIn

      # Rate group 3
      rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup3] -> rateGroup3.CycleIn
      rateGroup3.RateGroupMemberOut[0] -> $health.Run
      rateGroup3.RateGroupMemberOut[1] -> blockDrv.Sched
      rateGroup3.RateGroupMemberOut[2] -> bufferManager.schedIn
    }

    connections Sequencer {
      cmdSeq.comCmdOut -> cmdDisp.seqCmdBuff
      cmdDisp.seqCmdStatus -> cmdSeq.cmdResponseIn
    }

    connections Uplink {

      comDriver.allocate -> bufferManager.bufferGetCallee
      comDriver.$recv -> comStub.drvDataIn
      comStub.comDataOut -> deframer.framedIn

      deframer.framedDeallocate -> bufferManager.bufferSendIn
      deframer.comOut -> cmdDisp.seqCmdBuff

      cmdDisp.seqCmdStatus -> deframer.cmdResponseIn

      deframer.bufferAllocate -> bufferManager.bufferGetCallee
      deframer.bufferOut -> fileUplink.bufferSendIn
      deframer.bufferDeallocate -> bufferManager.bufferSendIn
      fileUplink.bufferSendOut -> bufferManager.bufferSendIn
    }

    connections send_hub_0 {
      hub_0.dataOut -> hubFramer_0.bufferIn
      hub_0.dataOutAllocate -> bufferManager.bufferGetCallee

      hubFramer_0.framedOut -> hubComDriver_0.$send
      hubFramer_0.bufferDeallocate -> bufferManager.bufferSendIn
      hubFramer_0.framedAllocate -> bufferManager.bufferGetCallee

      hubComDriver_0.deallocate -> bufferManager.bufferSendIn
    }

    connections recv_hub_0 {
      hubComDriver_0.$recv -> hubDeframer_0.framedIn
      hubComDriver_0.allocate -> bufferManager.bufferGetCallee
      
      hubDeframer_0.bufferOut -> hub_0.dataIn 
      hubDeframer_0.framedDeallocate -> bufferManager.bufferSendIn
      hubDeframer_0.bufferAllocate -> bufferManager.bufferGetCallee

      hub_0.dataInDeallocate -> bufferManager.bufferSendIn
    }

    connections send_hub_1 {
      hub_1.dataOut -> hubFramer_1.bufferIn
      hub_1.dataOutAllocate -> bufferManager.bufferGetCallee

      hubFramer_1.framedOut -> hubComDriver_1.$send
      hubFramer_1.bufferDeallocate -> bufferManager.bufferSendIn
      hubFramer_1.framedAllocate -> bufferManager.bufferGetCallee

      hubComDriver_1.deallocate -> bufferManager.bufferSendIn
    }

    connections recv_hub_1 {
      hubComDriver_1.$recv -> hubDeframer_1.framedIn
      hubComDriver_1.allocate -> bufferManager.bufferGetCallee
      
      hubDeframer_1.bufferOut -> hub_1.dataIn 
      hubDeframer_1.framedDeallocate -> bufferManager.bufferSendIn
      hubDeframer_1.bufferAllocate -> bufferManager.bufferGetCallee

      hub_1.dataInDeallocate -> bufferManager.bufferSendIn
    }

    connections send_hub_2 {
      hub_2.dataOut -> hubFramer_2.bufferIn
      hub_2.dataOutAllocate -> bufferManager.bufferGetCallee

      hubFramer_2.framedOut -> hubComDriver_2.$send
      hubFramer_2.bufferDeallocate -> bufferManager.bufferSendIn
      hubFramer_2.framedAllocate -> bufferManager.bufferGetCallee

      hubComDriver_2.deallocate -> bufferManager.bufferSendIn
    }

    connections recv_hub_2 {
      hubComDriver_2.$recv -> hubDeframer_2.framedIn
      hubComDriver_2.allocate -> bufferManager.bufferGetCallee
      
      hubDeframer_2.bufferOut -> hub_2.dataIn 
      hubDeframer_2.framedDeallocate -> bufferManager.bufferSendIn
      hubDeframer_2.bufferAllocate -> bufferManager.bufferGetCallee

      hub_2.dataInDeallocate -> bufferManager.bufferSendIn
    }

    connections Commander {
      # Add here connections to user-defined components
      ping.ping0 -> hub_0.portIn[0]
      ping.ping1 -> hub_1.portIn[0]
      ping.ping2 -> hub_2.portIn[0]
      hub_0.portOut[0] -> ping.pong
      hub_1.portOut[0] -> ping.pong
      hub_2.portOut[0] -> ping.pong

      # labCommander.monteCarloOutPort -> monteCarloComponent.AmountIn
      # monteCarloComponent.PositiveHits -> labCommander.monteCarloInPort
      labCommander.monteCarloOutPort[0] -> hub_0.portIn[1]
      labCommander.monteCarloOutPort[1] -> hub_1.portIn[1]
      labCommander.monteCarloOutPort[2] -> hub_2.portIn[1]

      hub_0.portOut[1] -> labCommander.monteCarloInPort
      hub_1.portOut[1] -> labCommander.monteCarloInPort
      hub_2.portOut[1] -> labCommander.monteCarloInPort
    }

  }

}
