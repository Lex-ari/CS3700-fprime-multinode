module Components {
    port Ping(
        nodeID: U8
    )

    port AmountInPort (
        samples: U32
        nodeID: U8
    )

    port PositiveHits (
        positive_hits: U32
        nodeID: U8
    )

    port ResultOutPort (
        result: F32
        nodeID:U8
    )
}
