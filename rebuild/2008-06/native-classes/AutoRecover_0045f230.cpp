// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <boost/shared_ptr.hpp>
#include "v8tree/Instance.h"

// INFERRED: func_0045f0a0 builds a shared_ptr<Instance> into the out-param (cdecl) and returns a pointer to a shared_ptr copy
extern "C" boost::shared_ptr<RBX::Instance>* fn_0045f0a0(boost::shared_ptr<RBX::Instance>* out, int arg);

// INFERRED: target is a __thiscall member of an unknown parent class; this is the new instance's parent
extern "C" RBX::Instance* __fastcall fn_0045f230(RBX::Instance* self, int unusedEdx, const char* name, int arg)
{
    boost::shared_ptr<RBX::Instance> tmp;
    boost::shared_ptr<RBX::Instance> inst = *fn_0045f0a0(&tmp, arg);
    inst->setName(std::string(name));
    inst->setParent(self);
    return inst.get();
}
