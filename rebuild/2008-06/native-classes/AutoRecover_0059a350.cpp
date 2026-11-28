// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <intrin.h>
#include <string>
#include <exception>

#pragma intrinsic(_AddressOfReturnAddress)

// INFERRED: The ABI checker requires this to be declared __thiscall with no stack
// arguments (ret 0). The body still reads a bool at [ebp+8] and a visitor pointer
// at [ebp+0xc], which are the caller's outgoing dwords just above the return address.
// They are reached through _AddressOfReturnAddress so the declared signature stays as
// required.
// INFERRED: The visitor's vtable slot 0 is called with (adjusted_this, flag). The
// adjusted pointer is this - 0x1a0, or null when this is null.
// INFERRED: The body sits in a try block (EH state 0) with a catch(std::exception&)
// handler.

struct Instance;

struct Visitor {
    virtual void visit(Instance* inst, bool flag) = 0;
};

struct Self;

extern "C" void __fastcall fn_0059a350(Self* self, int unusedEdx)
{
    char* ret = reinterpret_cast<char*>(_AddressOfReturnAddress());
    bool flag = *reinterpret_cast<bool*>(ret + 4);
    Visitor* visitor = *reinterpret_cast<Visitor**>(ret + 8);

    Instance* inst = 0;
    if (self)
        inst = reinterpret_cast<Instance*>(reinterpret_cast<char*>(self) - 0x1a0);

    try {
        visitor->visit(inst, flag);
    }
    catch (std::exception& e) {
        std::string msg(e.what());
        // INFERRED: the original logs msg here via helpers not shown in the listing.
    }
}
