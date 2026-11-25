// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were provided, so the types are declared locally.
// INFERRED: the destructor is declared out-of-line so the compiler registers it via atexit.

namespace boost { template<class T> class shared_ptr; }

namespace RBX {
class Instance;
namespace Reflection {
template<class C, class Sig>
class SignalDesc {
public:
    SignalDesc(const char* name, const char* arg);
    ~SignalDesc();
};
}

class Instance {
public:
    static Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)> event_childAdded;
};

Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)> Instance::event_childAdded("ChildAdded", "child");
}
