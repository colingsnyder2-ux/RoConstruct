// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 0049ba60  unit: RBX::Network::Client::?$BoundFuncDesc  size: 487 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049ba60
//
// 0049ba60  6aff                 push -1
// 0049ba62  68608e7400           push 0x748e60
// 0049ba67  64a100000000         mov eax, dword ptr fs:[0]
// 0049ba6d  50                   push eax
// 0049ba6e  83ec2c               sub esp, 0x2c
// 0049ba71  56                   push esi
// 0049ba72  57                   push edi
// 0049ba73  a188518b00           mov eax, dword ptr [0x8b5188]
// 0049ba78  33c4                 xor eax, esp
// 0049ba7a  50                   push eax
// 0049ba7b  8d442438             lea eax, [esp + 0x38]
// 0049ba7f  64a300000000         mov dword ptr fs:[0], eax
// 0049ba85  8bf1                 mov esi, ecx
// 0049ba87  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0049ba8a  85c9                 test ecx, ecx
// 0049ba8c  8b4630               mov eax, dword ptr [esi + 0x30]
// 0049ba8f  89442424             mov dword ptr [esp + 0x24], eax
// 0049ba93  7409                 je 0x49ba9e
// 0049ba95  8b11                 mov edx, dword ptr [ecx]
// 0049ba97  8b4208               mov eax, dword ptr [edx + 8]
// 0049ba9a  ffd0                 call eax
// 0049ba9c  eb02                 jmp 0x49baa0
// 0049ba9e  33c0                 xor eax, eax
// 0049baa0  89442428             mov dword ptr [esp + 0x28], eax
// 0049baa4  8b7c244c             mov edi, dword ptr [esp + 0x4c]
// 0049baa8  8b17                 mov edx, dword ptr [edi]
// 0049baaa  8b5204               mov edx, dword ptr [edx + 4]
// 0049baad  8d442424             lea eax, [esp + 0x24]
// 0049bab1  50                   push eax
// 0049bab2  6a01                 push 1
// 0049bab4  8bcf                 mov ecx, edi
// 0049bab6  c744244800000000     mov dword ptr [esp + 0x48], 0
// 0049babe  ffd2                 call edx
// 0049bac0  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0049bac3  85c9                 test ecx, ecx
// 0049bac5  8b4638               mov eax, dword ptr [esi + 0x38]
// 0049bac8  8944241c             mov dword ptr [esp + 0x1c], eax
// 0049bacc  7409                 je 0x49bad7
// 0049bace  8b11                 mov edx, dword ptr [ecx]
// 0049bad0  8b4208               mov eax, dword ptr [edx + 8]
// 0049bad3  ffd0                 call eax
// 0049bad5  eb02                 jmp 0x49bad9
// 0049bad7  33c0                 xor eax, eax
// 0049bad9  89442420             mov dword ptr [esp + 0x20], eax
// 0049badd  8b17                 mov edx, dword ptr [edi]
// 0049badf  8b5204               mov edx, dword ptr [edx + 4]
// 0049bae2  8d44241c             lea eax, [esp + 0x1c]
// 0049bae6  50                   push eax
// 0049bae7  6a02                 push 2
// 0049bae9  8bcf                 mov ecx, edi
// 0049baeb  c644244801           mov byte ptr [esp + 0x48], 1
// 0049baf0  ffd2                 call edx
// 0049baf2  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 0049baf5  85c9                 test ecx, ecx
// 0049baf7  8b4640               mov eax, dword ptr [esi + 0x40]
// 0049bafa  89442414             mov dword ptr [esp + 0x14], eax
// 0049bafe  7409                 je 0x49bb09
// 0049bb00  8b11                 mov edx, dword ptr [ecx]
// 0049bb02  8b4208               mov eax, dword ptr [edx + 8]
// 0049bb05  ffd0                 call eax
// 0049bb07  eb02                 jmp 0x49bb0b
// 0049bb09  33c0                 xor eax, eax
// 0049bb0b  89442418             mov dword ptr [esp + 0x18], eax
// 0049bb0f  8b17                 mov edx, dword ptr [edi]
// 0049bb11  8b5204               mov edx, dword ptr [edx + 4]
// 0049bb14  8d442414             lea eax, [esp + 0x14]
// 0049bb18  50                   push eax
// 0049bb19  6a03                 push 3
// 0049bb1b  8bcf                 mov ecx, edi
// 0049bb1d  c644244802           mov byte ptr [esp + 0x48], 2
// 0049bb22  ffd2                 call edx
// 0049bb24  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 0049bb27  85c9                 test ecx, ecx
// 0049bb29  8b4648               mov eax, dword ptr [esi + 0x48]
// 0049bb2c  8944240c             mov dword ptr [esp + 0xc], eax
// 0049bb30  7409                 je 0x49bb3b
// 0049bb32  8b11                 mov edx, dword ptr [ecx]
// 0049bb34  8b4208               mov eax, dword ptr [edx + 8]
// 0049bb37  ffd0                 call eax
// 0049bb39  eb02                 jmp 0x49bb3d
// 0049bb3b  33c0                 xor eax, eax
// 0049bb3d  89442410             mov dword ptr [esp + 0x10], eax
// 0049bb41  8b17                 mov edx, dword ptr [edi]
// 0049bb43  8b5204               mov edx, dword ptr [edx + 4]
// 0049bb46  8d44240c             lea eax, [esp + 0xc]
// 0049bb4a  50                   push eax
// 0049bb4b  6a04                 push 4
// 0049bb4d  8bcf                 mov ecx, edi
// 0049bb4f  c644244803           mov byte ptr [esp + 0x48], 3
// 0049bb54  ffd2                 call edx
// 0049bb56  8b442448             mov eax, dword ptr [esp + 0x48]
// 0049bb5a  6a00                 push 0
// 0049bb5c  6868f98800           push 0x88f968
// 0049bb61  689c208800           push 0x88209c
// 0049bb66  6a00                 push 0
// 0049bb68  50                   push eax
// 0049bb69  e8c8511900           call 0x630d36
// 0049bb6e  8bf8                 mov edi, eax
// 0049bb70  83c414               add esp, 0x14
// 0049bb73  85ff                 test edi, edi
// 0049bb75  751e                 jne 0x49bb95
// 0049bb77  68046e7800           push 0x786e04
// 0049bb7c  8d4c2430             lea ecx, [esp + 0x30]
// 0049bb80  ff1510e77700         call dword ptr [0x77e710]
// 0049bb86  680c1e8400           push 0x841e0c
// 0049bb8b  8d4c2430             lea ecx, [esp + 0x30]
// 0049bb8f  51                   push ecx
// 0049bb90  e809501900           call 0x630b9e
// 0049bb95  8d4c240c             lea ecx, [esp + 0xc]
// 0049bb99  e812340d00           call 0x56efb0
// 0049bb9e  8b10                 mov edx, dword ptr [eax]
// 0049bba0  52                   push edx
// 0049bba1  8d4c2418             lea ecx, [esp + 0x18]
// 0049bba5  e806340d00           call 0x56efb0
// 0049bbaa  8b00                 mov eax, dword ptr [eax]
// 0049bbac  50                   push eax
// 0049bbad  8d4c2424             lea ecx, [esp + 0x24]
// 0049bbb1  e8fa330d00           call 0x56efb0
// 0049bbb6  8b08                 mov ecx, dword ptr [eax]
// 0049bbb8  51                   push ecx
// 0049bbb9  8d4c2430             lea ecx, [esp + 0x30]
// 0049bbbd  e84e380d00           call 0x56f410
// 0049bbc2  83ec1c               sub esp, 0x1c
// 0049bbc5  8bcc                 mov ecx, esp
// 0049bbc7  89642474             mov dword ptr [esp + 0x74], esp
// 0049bbcb  50                   push eax
// 0049bbcc  ff159ce67700         call dword ptr [0x77e69c]
// 0049bbd2  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 0049bbd5  8b5628               mov edx, dword ptr [esi + 0x28]
// 0049bbd8  03cf                 add ecx, edi
// 0049bbda  ffd2                 call edx
// 0049bbdc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0049bbe0  85c9                 test ecx, ecx
// 0049bbe2  c644244002           mov byte ptr [esp + 0x40], 2
// 0049bbe7  7408                 je 0x49bbf1
// 0049bbe9  8b01                 mov eax, dword ptr [ecx]
// 0049bbeb  8b10                 mov edx, dword ptr [eax]
// 0049bbed  6a01                 push 1
// 0049bbef  ffd2                 call edx
// 0049bbf1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0049bbf5  85c9                 test ecx, ecx
// 0049bbf7  c644244001           mov byte ptr [esp + 0x40], 1
// 0049bbfc  7408                 je 0x49bc06
// 0049bbfe  8b01                 mov eax, dword ptr [ecx]
// 0049bc00  8b10                 mov edx, dword ptr [eax]
// 0049bc02  6a01                 push 1
// 0049bc04  ffd2                 call edx
// 0049bc06  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0049bc0a  85c9                 test ecx, ecx
// 0049bc0c  c644244000           mov byte ptr [esp + 0x40], 0
// 0049bc11  7408                 je 0x49bc1b
// 0049bc13  8b01                 mov eax, dword ptr [ecx]
// 0049bc15  8b10                 mov edx, dword ptr [eax]
// 0049bc17  6a01                 push 1
// 0049bc19  ffd2                 call edx
// 0049bc1b  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0049bc1f  85c9                 test ecx, ecx
// 0049bc21  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 0049bc29  7408                 je 0x49bc33
// 0049bc2b  8b01                 mov eax, dword ptr [ecx]
// 0049bc2d  8b10                 mov edx, dword ptr [eax]
// 0049bc2f  6a01                 push 1
// 0049bc31  ffd2                 call edx
// 0049bc33  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0049bc37  64890d00000000       mov dword ptr fs:[0], ecx
// 0049bc3e  59                   pop ecx
// 0049bc3f  5f                   pop edi
// 0049bc40  5e                   pop esi
// 0049bc41  83c438               add esp, 0x38
// 0049bc44  c20800               ret 8

struct RefCounted {
    void AddRef();
    void Release();
};

struct ArgValue {
    void* ptr;
    RefCounted* ref;
};

// Reflection BoundFuncDesc<Class, void(std::string, int, int, int), 4>::execute (2007-08 layout from the
// target: FuncDesc base 0x28, pmf at +0x28/+0x2c, default1..4 Values at +0x30/+0x38/+0x40/+0x48;
// Arguments::get is vtable slot 1; any placeholder clone is slot 2, deleting dtor slot 0).
#include <string>
#include <typeinfo>

namespace RBX {
namespace Reflection {

class DescribedBase { public: virtual ~DescribedBase(); };
class Type;

class placeholder {
public:
    virtual ~placeholder() {}
    virtual const std::type_info& type() const = 0;
    virtual placeholder* clone() const = 0;
};

class any {
    placeholder* content;
public:
    any(const any& other) : content(other.content ? other.content->clone() : 0) {}
    ~any() { delete content; }
};

class Value {
    const Type* _type;
    any value;
public:
    template<typename T> T& convert();
};

class Arguments {
public:
    virtual ~Arguments();
    virtual void get(int index, Value& value) const = 0;
};

template<class Class> class FuncDesc {
public:
    virtual ~FuncDesc();
    virtual void execute(DescribedBase* instance, Arguments& arguments) const = 0;
    char pad[0x28 - 4];
};

template<typename Class, typename Function, int N> class BoundFuncDesc;

template<typename Class>
class BoundFuncDesc<Class, void(std::string, int, int, int), 4> : public FuncDesc<Class> {
public:
    typedef void (Class::*FunctionSig)(std::string, int, int, int);
private:
    FunctionSig function;
    Value default1;
    Value default2;
    Value default3;
    Value default4;
public:
    virtual void execute(DescribedBase* instance, Arguments& arguments) const
    {
        Value arg1 = default1;
        arguments.get(1, arg1);
        Value arg2 = default2;
        arguments.get(2, arg2);
        Value arg3 = default3;
        arguments.get(3, arg3);
        Value arg4 = default4;
        arguments.get(4, arg4);

        Class* o = dynamic_cast<Class*>(instance);
        if (!o)
            throw std::bad_cast();

        (o->*function)(arg1.convert<std::string>(), arg2.convert<int>(), arg3.convert<int>(), arg4.convert<int>());
    }
};

} // namespace Reflection

class V0 { public: virtual ~V0(); };

namespace Network {
class Client : public RBX::V0, public RBX::Reflection::DescribedBase {
public:
    void method(std::string, int, int, int);
};
}
} // namespace RBX

template class RBX::Reflection::BoundFuncDesc<RBX::Network::Client, void(std::string, int, int, int), 4>;
