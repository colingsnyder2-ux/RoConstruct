// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers were provided, so minimal local declarations stand in for them.
#include <vector>
#include <cstddef>
#include <boost/shared_ptr.hpp>

namespace RBX {

class ServiceProvider;

class Instance {
public:
    void setParent(Instance* parent);
};

class RunService : public Instance {
};

template<class T>
class Creatable {
public:
    template<class U>
    static boost::shared_ptr<U> create();
};

class ServiceProvider : public Instance {
public:
    // INFERRED: vector of shared_ptr<Instance> at +0x19c, filled by create<>
    mutable std::vector< boost::shared_ptr<Instance> > services;

    template<class T> static unsigned int doGetClassIndex();
    template<class T> T* create() const;
};

} // namespace RBX

// INFERRED: callee 0x452c80 is a thiscall lookup (ServiceProvider::find<RunService>) taking this in ecx
extern "C" RBX::RunService* __fastcall fn_00452c80(const RBX::ServiceProvider* self, int unusedEdx);
// INFERRED: once-init routine and flag used with boost::call_once
extern "C" void fn_00450860();
extern long g_runServiceClassIndexFlag;

namespace boost {
void call_once(void (*f)(), long& flag);
}

template<>
RBX::RunService* RBX::ServiceProvider::create<RBX::RunService>() const
{
    RBX::RunService* existing = fn_00452c80(this, 0);
    if (existing)
        return existing;

    boost::shared_ptr<RBX::RunService> result = RBX::Creatable<RBX::Instance>::create<RBX::RunService>();

    boost::call_once(&fn_00450860, g_runServiceClassIndexFlag);
    unsigned int index = doGetClassIndex<RBX::RunService>();

    services[index] = result;

    result->setParent(const_cast<RBX::ServiceProvider*>(this));
    return result.get();
}
