// from server: 100% by Yeetserama
// roc 2010-06 004db890  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004db890
//
// 004db890  6aff                 push -1
// 004db892  6880409a00           push 0x9a4080
// 004db897  64a100000000         mov eax, dword ptr fs:[0]
// 004db89d  50                   push eax
// 004db89e  64892500000000       mov dword ptr fs:[0], esp
// 004db8a5  83ec1c               sub esp, 0x1c
// 004db8a8  56                   push esi
// 004db8a9  8bf1                 mov esi, ecx
// 004db8ab  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 004db8ae  8b4640               mov eax, dword ptr [esi + 0x40]
// 004db8b1  57                   push edi
// 004db8b2  89442410             mov dword ptr [esp + 0x10], eax
// 004db8b6  85c9                 test ecx, ecx
// 004db8b8  7409                 je 0x4db8c3
// 004db8ba  8b11                 mov edx, dword ptr [ecx]
// 004db8bc  8b4208               mov eax, dword ptr [edx + 8]
// 004db8bf  ffd0                 call eax
// 004db8c1  eb02                 jmp 0x4db8c5
// 004db8c3  33c0                 xor eax, eax
// 004db8c5  89442414             mov dword ptr [esp + 0x14], eax
// 004db8c9  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 004db8cd  8b17                 mov edx, dword ptr [edi]
// 004db8cf  8b5204               mov edx, dword ptr [edx + 4]
// 004db8d2  8d442410             lea eax, [esp + 0x10]
// 004db8d6  50                   push eax
// 004db8d7  6a01                 push 1
// 004db8d9  8bcf                 mov ecx, edi
// 004db8db  c744243400000000     mov dword ptr [esp + 0x34], 0
// 004db8e3  ffd2                 call edx
// 004db8e5  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 004db8e8  8b4648               mov eax, dword ptr [esi + 0x48]
// 004db8eb  89442408             mov dword ptr [esp + 8], eax
// 004db8ef  85c9                 test ecx, ecx
// 004db8f1  7409                 je 0x4db8fc
// 004db8f3  8b11                 mov edx, dword ptr [ecx]
// 004db8f5  8b4208               mov eax, dword ptr [edx + 8]
// 004db8f8  ffd0                 call eax
// 004db8fa  eb02                 jmp 0x4db8fe
// 004db8fc  33c0                 xor eax, eax
// 004db8fe  8944240c             mov dword ptr [esp + 0xc], eax
// 004db902  8b17                 mov edx, dword ptr [edi]
// 004db904  8b5204               mov edx, dword ptr [edx + 4]
// 004db907  8d442408             lea eax, [esp + 8]
// 004db90b  50                   push eax
// 004db90c  6a02                 push 2
// 004db90e  8bcf                 mov ecx, edi
// 004db910  c644243401           mov byte ptr [esp + 0x34], 1
// 004db915  ffd2                 call edx
// 004db917  8b442434             mov eax, dword ptr [esp + 0x34]
// 004db91b  6a00                 push 0
// 004db91d  68c815b900           push 0xb915c8
// 004db922  684090b700           push 0xb79040
// 004db927  6a00                 push 0
// 004db929  50                   push eax
// 004db92a  e8bbd22c00           call 0x7a8bea
// 004db92f  8bf8                 mov edi, eax
// 004db931  83c414               add esp, 0x14
// 004db934  85ff                 test edi, edi
// 004db936  751e                 jne 0x4db956
// 004db938  68540aa000           push 0xa00a54
// 004db93d  8d4c241c             lea ecx, [esp + 0x1c]
// 004db941  ff159ca89e00         call dword ptr [0x9ea89c]
// 004db947  689022b100           push 0xb12290
// 004db94c  8d4c241c             lea ecx, [esp + 0x1c]
// 004db950  51                   push ecx
// 004db951  e85cd02c00           call 0x7a89b2
// 004db956  55                   push ebp
// 004db957  8d4c240c             lea ecx, [esp + 0xc]
// 004db95b  e810d10c00           call 0x5a8a70
// 004db960  8d4c2414             lea ecx, [esp + 0x14]
// 004db964  8be8                 mov ebp, eax
// 004db966  e805d10c00           call 0x5a8a70
// 004db96b  8b5500               mov edx, dword ptr [ebp]
// 004db96e  8b00                 mov eax, dword ptr [eax]
// 004db970  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 004db973  52                   push edx
// 004db974  8b5638               mov edx, dword ptr [esi + 0x38]
// 004db977  50                   push eax
// 004db978  03cf                 add ecx, edi
// 004db97a  ffd2                 call edx
// 004db97c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004db980  c644243000           mov byte ptr [esp + 0x30], 0
// 004db985  5d                   pop ebp
// 004db986  85c9                 test ecx, ecx
// 004db988  7408                 je 0x4db992
// 004db98a  8b01                 mov eax, dword ptr [ecx]
// 004db98c  8b10                 mov edx, dword ptr [eax]
// 004db98e  6a01                 push 1
// 004db990  ffd2                 call edx
// 004db992  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004db996  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004db99e  85c9                 test ecx, ecx
// 004db9a0  7408                 je 0x4db9aa
// 004db9a2  8b01                 mov eax, dword ptr [ecx]
// 004db9a4  8b10                 mov edx, dword ptr [eax]
// 004db9a6  6a01                 push 1
// 004db9a8  ffd2                 call edx
// 004db9aa  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004db9ae  5f                   pop edi
// 004db9af  5e                   pop esi
// 004db9b0  64890d00000000       mov dword ptr fs:[0], ecx
// 004db9b7  83c428               add esp, 0x28
// 004db9ba  c20800               ret 8
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