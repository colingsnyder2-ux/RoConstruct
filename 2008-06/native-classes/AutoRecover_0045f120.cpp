// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <boost/shared_ptr.hpp>
#include "v8tree/Instance.h"

// INFERRED: func_0045f020 is cdecl(out shared_ptr*, arg), returns pointer to a shared_ptr.
extern "C" boost::shared_ptr<RBX::Instance>* fn_0045f020(boost::shared_ptr<RBX::Instance>* out, int arg);

// INFERRED: vtable slot 1 takes const std::string& (name setter); declared locally.
struct NameSlotObj {
    virtual void slot0();
    virtual void setNameSlot(const std::string& name);
};

// INFERRED: __thiscall member helper (ecx = parent); stack args: name, factory arg.
extern "C" RBX::Instance* __fastcall fn_0045f120(RBX::Instance* parent, int unusedEdx, const char* name, int arg)
{
    boost::shared_ptr<RBX::Instance> inst;
    {
        boost::shared_ptr<RBX::Instance> tmp;
        inst = *fn_0045f020(&tmp, arg);
    }
    reinterpret_cast<NameSlotObj*>(inst.get())->setNameSlot(std::string(name));
    inst->setParent(parent);
    return inst.get();
}
