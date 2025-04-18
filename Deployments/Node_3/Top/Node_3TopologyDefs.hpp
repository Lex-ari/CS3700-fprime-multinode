// ======================================================================
// \title  Node_3TopologyDefs.hpp
// \brief required header file containing the required definitions for the topology autocoder
//
// ======================================================================
#ifndef NODE_3_NODE_3TOPOLOGYDEFS_HPP
#define NODE_3_NODE_3TOPOLOGYDEFS_HPP

#include "Drv/BlockDriver/BlockDriver.hpp"
#include "Fw/Types/MallocAllocator.hpp"
#include "Node_3/Top/FppConstantsAc.hpp"
#include "Svc/FramingProtocol/FprimeProtocol.hpp"
#include "Svc/Health/Health.hpp"

// Definitions are placed within a namespace named after the deployment
namespace Node_3 {

/**
 * \brief required type definition to carry state
 *
 * The topology autocoder requires an object that carries state with the name `Node_3::TopologyState`. Only the type
 * definition is required by the autocoder and the contents of this object are otherwise opaque to the autocoder. The contents are entirely up
 * to the definition of the project. Here, they are derived from command line inputs.
 */
struct TopologyState {
    const CHAR* hostname;
    U16 port;
};

/**
 * \brief required ping constants
 *
 * The topology autocoder requires a WARN and FATAL constant definition for each component that supports the health-ping
 * interface. These are expressed as enum constants placed in a namespace named for the component instance. These
 * are all placed in the PingEntries namespace.
 *
 * Each constant specifies how many missed pings are allowed before a WARNING_HI/FATAL event is triggered. In the
 * following example, the health component will emit a WARNING_HI event if the component instance cmdDisp does not
 * respond for 3 pings and will FATAL if responses are not received after a total of 5 pings.
 *
 * ```c++
 * namespace PingEntries {
 * namespace cmdDisp {
 *     enum { WARN = 3, FATAL = 5 };
 * }
 * }
 * ```
 */
namespace PingEntries {
namespace Node_3_blockDrv {
enum { WARN = 3, FATAL = 5 };
}
namespace Node_3_tlmSend {
enum { WARN = 3, FATAL = 5 };
}
namespace Node_3_cmdDisp {
enum { WARN = 3, FATAL = 5 };
}
namespace Node_3_cmdSeq {
enum { WARN = 3, FATAL = 5 };
}
namespace Node_3_eventLogger {
enum { WARN = 3, FATAL = 5 };
}
namespace Node_3_fileDownlink {
enum { WARN = 3, FATAL = 5 };
}
namespace Node_3_fileManager {
enum { WARN = 3, FATAL = 5 };
}
namespace Node_3_fileUplink {
enum { WARN = 3, FATAL = 5 };
}
namespace Node_3_prmDb {
enum { WARN = 3, FATAL = 5 };
}
namespace Node_3_rateGroup1 {
enum { WARN = 3, FATAL = 5 };
}
namespace Node_3_rateGroup2 {
enum { WARN = 3, FATAL = 5 };
}
namespace Node_3_rateGroup3 {
enum { WARN = 3, FATAL = 5 };
}
}  // namespace PingEntries
}  // namespace Node_3
#endif
