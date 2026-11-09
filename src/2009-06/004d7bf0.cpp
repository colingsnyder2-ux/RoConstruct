// from server: 100% by EspClaude
// roc 2009-06 004d7bf0  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d7bf0
//
// 004d7bf0  6aff                 push -1
// 004d7bf2  68c0a48500           push 0x85a4c0
// 004d7bf7  64a100000000         mov eax, dword ptr fs:[0]
// 004d7bfd  50                   push eax
// 004d7bfe  64892500000000       mov dword ptr fs:[0], esp
// 004d7c05  83ec1c               sub esp, 0x1c
// 004d7c08  56                   push esi
// 004d7c09  8bf1                 mov esi, ecx
// 004d7c0b  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 004d7c0e  8b4640               mov eax, dword ptr [esi + 0x40]
// 004d7c11  57                   push edi
// 004d7c12  89442410             mov dword ptr [esp + 0x10], eax
// 004d7c16  85c9                 test ecx, ecx
// 004d7c18  7409                 je 0x4d7c23
// 004d7c1a  8b11                 mov edx, dword ptr [ecx]
// 004d7c1c  8b4208               mov eax, dword ptr [edx + 8]
// 004d7c1f  ffd0                 call eax
// 004d7c21  eb02                 jmp 0x4d7c25
// 004d7c23  33c0                 xor eax, eax
// 004d7c25  89442414             mov dword ptr [esp + 0x14], eax
// 004d7c29  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 004d7c2d  8b17                 mov edx, dword ptr [edi]
// 004d7c2f  8b5204               mov edx, dword ptr [edx + 4]
// 004d7c32  8d442410             lea eax, [esp + 0x10]
// 004d7c36  50                   push eax
// 004d7c37  6a01                 push 1
// 004d7c39  8bcf                 mov ecx, edi
// 004d7c3b  c744243400000000     mov dword ptr [esp + 0x34], 0
// 004d7c43  ffd2                 call edx
// 004d7c45  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 004d7c48  8b4648               mov eax, dword ptr [esi + 0x48]
// 004d7c4b  89442408             mov dword ptr [esp + 8], eax
// 004d7c4f  85c9                 test ecx, ecx
// 004d7c51  7409                 je 0x4d7c5c
// 004d7c53  8b11                 mov edx, dword ptr [ecx]
// 004d7c55  8b4208               mov eax, dword ptr [edx + 8]
// 004d7c58  ffd0                 call eax
// 004d7c5a  eb02                 jmp 0x4d7c5e
// 004d7c5c  33c0                 xor eax, eax
// 004d7c5e  8944240c             mov dword ptr [esp + 0xc], eax
// 004d7c62  8b17                 mov edx, dword ptr [edi]
// 004d7c64  8b5204               mov edx, dword ptr [edx + 4]
// 004d7c67  8d442408             lea eax, [esp + 8]
// 004d7c6b  50                   push eax
// 004d7c6c  6a02                 push 2
// 004d7c6e  8bcf                 mov ecx, edi
// 004d7c70  c644243401           mov byte ptr [esp + 0x34], 1
// 004d7c75  ffd2                 call edx
// 004d7c77  8b442434             mov eax, dword ptr [esp + 0x34]
// 004d7c7b  6a00                 push 0
// 004d7c7d  68002e9f00           push 0x9f2e00
// 004d7c82  68c4bf9d00           push 0x9dbfc4
// 004d7c87  6a00                 push 0
// 004d7c89  50                   push eax
// 004d7c8a  e8eb1f2400           call 0x719c7a
// 004d7c8f  8bf8                 mov edi, eax
// 004d7c91  83c414               add esp, 0x14
// 004d7c94  85ff                 test edi, edi
// 004d7c96  751e                 jne 0x4d7cb6
// 004d7c98  6850d38a00           push 0x8ad350
// 004d7c9d  8d4c241c             lea ecx, [esp + 0x1c]
// 004d7ca1  ff1570e98900         call dword ptr [0x89e970]
// 004d7ca7  68b04b9800           push 0x984bb0
// 004d7cac  8d4c241c             lea ecx, [esp + 0x1c]
// 004d7cb0  51                   push ecx
// 004d7cb1  e8941d2400           call 0x719a4a
// 004d7cb6  55                   push ebp
// 004d7cb7  8d4c240c             lea ecx, [esp + 0xc]
// 004d7cbb  e830011100           call 0x5e7df0
// 004d7cc0  8d4c2414             lea ecx, [esp + 0x14]
// 004d7cc4  8be8                 mov ebp, eax
// 004d7cc6  e825011100           call 0x5e7df0
// 004d7ccb  8b5500               mov edx, dword ptr [ebp]
// 004d7cce  8b00                 mov eax, dword ptr [eax]
// 004d7cd0  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 004d7cd3  52                   push edx
// 004d7cd4  8b5638               mov edx, dword ptr [esi + 0x38]
// 004d7cd7  50                   push eax
// 004d7cd8  03cf                 add ecx, edi
// 004d7cda  ffd2                 call edx
// 004d7cdc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004d7ce0  c644243000           mov byte ptr [esp + 0x30], 0
// 004d7ce5  5d                   pop ebp
// 004d7ce6  85c9                 test ecx, ecx
// 004d7ce8  7408                 je 0x4d7cf2
// 004d7cea  8b01                 mov eax, dword ptr [ecx]
// 004d7cec  8b10                 mov edx, dword ptr [eax]
// 004d7cee  6a01                 push 1
// 004d7cf0  ffd2                 call edx
// 004d7cf2  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004d7cf6  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004d7cfe  85c9                 test ecx, ecx
// 004d7d00  7408                 je 0x4d7d0a
// 004d7d02  8b01                 mov eax, dword ptr [ecx]
// 004d7d04  8b10                 mov edx, dword ptr [eax]
// 004d7d06  6a01                 push 1
// 004d7d08  ffd2                 call edx
// 004d7d0a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004d7d0e  5f                   pop edi
// 004d7d0f  5e                   pop esi
// 004d7d10  64890d00000000       mov dword ptr fs:[0], ecx
// 004d7d17  83c428               add esp, 0x28
// 004d7d1a  c20800               ret 8
// copied from an identical function in another client (function ?invoke@BoundFuncDesc@@QAEXPAVDescribedBase@Reflection@RBX@@PAUArguments@@@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <typeinfo>


namespace RBX {
    namespace Reflection {
        class DescribedBase { public:
            virtual ~DescribedBase();
        };
    }

    namespace Network {
        class Server : public Reflection::DescribedBase {
        };
    }
}

struct Content {
    virtual ~Content();
    virtual void type() const;
    virtual Content* clone() const;
};

struct Value {
    int value;
    Content* content;

    static Content* copyContent(Content*);
    Value(const Value&);
    ~Value();
    int* get();
};

inline Content* Value::copyContent(Content* source)
{
    if (source)
        return source->clone();
    return 0;
}

inline Value::Value(const Value& other)
    : value(other.value), content(copyContent(other.content))
{
}

inline Value::~Value()
{
    if (content)
        delete content;
}

struct Arguments {
    virtual void unused();
    virtual void assign(int, Value*);
};

struct BoundFuncDesc {
    char padding[56];
    void (__thiscall* function)(void*, int, int);
    int adjustment;
    Value first;
    Value second;

    void invoke(RBX::Reflection::DescribedBase*, Arguments*);
};

void BoundFuncDesc::invoke(RBX::Reflection::DescribedBase* source,
                           Arguments* arguments)
{
    Value a(first);
    arguments->assign(1, &a);

    Value b(second);
    arguments->assign(2, &b);

    RBX::Network::Server* server =
        dynamic_cast<RBX::Network::Server*>(source);

    if (!server)
        throw std::bad_cast("bad cast");

    int* secondValue = b.get();
    int* firstValue = a.get();

    function(reinterpret_cast<char*>(server) + adjustment,
             *firstValue, *secondValue);
}