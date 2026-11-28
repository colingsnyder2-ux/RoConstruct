// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <boost/shared_ptr.hpp>

namespace RBX {
class Instance;
namespace Reflection {
template<class C, class Sig> class SignalDesc;
template<>
class SignalDesc<Instance, void(boost::shared_ptr<Instance>)> {
public:
    SignalDesc(const char* name, const char* arg0);
    ~SignalDesc();
    char storage[0x40];
};
}
class Instance {
public:
    static Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)> event_childRemoved;
};

// INFERRED: constructor and destructor are defined elsewhere

Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)> Instance::event_childRemoved("ChildRemoved", "child");
}
