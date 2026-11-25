// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#include "Network/Server2008.h"
#include "reflection/reflection.h"
#include <typeinfo>

// INFERRED: mirrors BoundFuncDesc<RBX::Network::Server, void(int), 1>::execute (004a0780 analog);
// function (+0x38) and default1 (+0x40) are private in reflection/reflection.h.
extern "C" void __fastcall fn_004a4830(
    const char* self,
    int unusedEdx,
    RBX::Reflection::DescribedBase* instance,
    RBX::Reflection::FunctionDescriptor::Arguments& arguments)
{
    typedef void (RBX::Network::Server::*FnSig)(int);
    RBX::Reflection::Value arg1 = *reinterpret_cast<const RBX::Reflection::Value*>(self + 0x40);
    arguments.get(1, arg1);

    RBX::Network::Server* o = dynamic_cast<RBX::Network::Server*>(instance);
    if (!o)
        throw std::bad_cast();

    (o->*(*reinterpret_cast<const FnSig*>(self + 0x38)))(arg1.convert<int>());
}
