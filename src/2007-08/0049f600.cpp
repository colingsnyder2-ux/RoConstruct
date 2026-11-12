// from server: 91% by EspClaude
// from server: 55% by colin
// roc 2007-08 0049f600  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049f600
//
// 0049f600  8b442404             mov eax, dword ptr [esp + 4]
// 0049f604  83ec0c               sub esp, 0xc
// 0049f607  56                   push esi
// 0049f608  6a00                 push 0
// 0049f60a  68bc048900           push 0x8904bc
// 0049f60f  689c208800           push 0x88209c
// 0049f614  6a00                 push 0
// 0049f616  50                   push eax
// 0049f617  8bf1                 mov esi, ecx
// 0049f619  e818171900           call 0x630d36
// 0049f61e  83c414               add esp, 0x14
// 0049f621  85c0                 test eax, eax
// 0049f623  751e                 jne 0x49f643
// 0049f625  68046e7800           push 0x786e04
// 0049f62a  8d4c2408             lea ecx, [esp + 8]
// 0049f62e  ff1510e77700         call dword ptr [0x77e710]
// 0049f634  680c1e8400           push 0x841e0c
// 0049f639  8d4c2408             lea ecx, [esp + 8]
// 0049f63d  51                   push ecx
// 0049f63e  e85b151900           call 0x630b9e
// 0049f643  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 0049f646  8b5628               mov edx, dword ptr [esi + 0x28]
// 0049f649  57                   push edi
// 0049f64a  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0049f64e  03c8                 add ecx, eax
// 0049f650  ffd2                 call edx
// 0049f652  8bf0                 mov esi, eax
// 0049f654  e877e10c00           call 0x56d7d0
// 0049f659  6a08                 push 8
// 0049f65b  894704               mov dword ptr [edi + 4], eax
// 0049f65e  e893081900           call 0x62fef6
// 0049f663  83c404               add esp, 4
// 0049f666  85c0                 test eax, eax
// 0049f668  740b                 je 0x49f675
// 0049f66a  c70098717800         mov dword ptr [eax], 0x787198
// 0049f670  897004               mov dword ptr [eax + 4], esi
// 0049f673  eb02                 jmp 0x49f677
// 0049f675  33c0                 xor eax, eax
// 0049f677  8b4f08               mov ecx, dword ptr [edi + 8]
// 0049f67a  85c9                 test ecx, ecx
// 0049f67c  894708               mov dword ptr [edi + 8], eax
// 0049f67f  5f                   pop edi
// 0049f680  7408                 je 0x49f68a
// 0049f682  8b01                 mov eax, dword ptr [ecx]
// 0049f684  8b10                 mov edx, dword ptr [eax]
// 0049f686  6a01                 push 1
// 0049f688  ffd2                 call edx
// 0049f68a  5e                   pop esi
// 0049f68b  83c40c               add esp, 0xc
// 0049f68e  c20800               ret 8
#include <typeinfo>
namespace RBX {
namespace Reflection {
class Type { public: template<class T> static const Type& singleton(); };
class DescribedBase { public: virtual ~DescribedBase(); };
class Variant {
    struct HolderBase { virtual ~HolderBase() {} };
    template<class T> struct Holder : HolderBase { T value; Holder(const T& v) : value(v) {} };
public:
    void* reserved;
    const Type* type;
    HolderBase* holder;
    template<class T> void set(const T& v)
    {
        type = &Type::singleton<T>();
        HolderBase* p = new Holder<T>(v);
        HolderBase* old = holder;
        holder = p;
        delete old;
    }
};
template<class Class, class R> class BoundFuncDesc {
public:
    char pad[0x28];
    R (Class::*getter)() const;
    void getValue(const DescribedBase* object, Variant& value) const;
};
template<class Class, class R>
void BoundFuncDesc<Class, R>::getValue(const DescribedBase* object, Variant& value) const
{
    const Class* c = dynamic_cast<const Class*>(object);
    if (!c)
        throw std::bad_cast();
    value.set((c->*getter)());
}
}
namespace Network {
class Base1 { public: virtual ~Base1(); };
class VServer : public Reflection::DescribedBase, public Base1 { };
}
template class Reflection::BoundFuncDesc<Network::VServer, int>;
}
