// from server: 100% by EspClaude
// from server: 100% by Espeon
// roc 2008-06 005c50e0  unit: RBX::VVisit::?$BoundFuncDesc  size: 309 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c50e0
//
// 005c50e0  6aff                 push -1
// 005c50e2  6840e17b00           push 0x7be140
// 005c50e7  64a100000000         mov eax, dword ptr fs:[0]
// 005c50ed  50                   push eax
// 005c50ee  64892500000000       mov dword ptr fs:[0], esp
// 005c50f5  83ec1c               sub esp, 0x1c
// 005c50f8  56                   push esi
// 005c50f9  8bf1                 mov esi, ecx
// 005c50fb  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 005c50fe  8b4640               mov eax, dword ptr [esi + 0x40]
// 005c5101  57                   push edi
// 005c5102  89442410             mov dword ptr [esp + 0x10], eax
// 005c5106  85c9                 test ecx, ecx
// 005c5108  7409                 je 0x5c5113
// 005c510a  8b11                 mov edx, dword ptr [ecx]
// 005c510c  8b4208               mov eax, dword ptr [edx + 8]
// 005c510f  ffd0                 call eax
// 005c5111  eb02                 jmp 0x5c5115
// 005c5113  33c0                 xor eax, eax
// 005c5115  89442414             mov dword ptr [esp + 0x14], eax
// 005c5119  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 005c511d  8b17                 mov edx, dword ptr [edi]
// 005c511f  8b5204               mov edx, dword ptr [edx + 4]
// 005c5122  8d442410             lea eax, [esp + 0x10]
// 005c5126  50                   push eax
// 005c5127  6a01                 push 1
// 005c5129  8bcf                 mov ecx, edi
// 005c512b  c744243400000000     mov dword ptr [esp + 0x34], 0
// 005c5133  ffd2                 call edx
// 005c5135  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 005c5138  8b4648               mov eax, dword ptr [esi + 0x48]
// 005c513b  89442408             mov dword ptr [esp + 8], eax
// 005c513f  85c9                 test ecx, ecx
// 005c5141  7409                 je 0x5c514c
// 005c5143  8b11                 mov edx, dword ptr [ecx]
// 005c5145  8b4208               mov eax, dword ptr [edx + 8]
// 005c5148  ffd0                 call eax
// 005c514a  eb02                 jmp 0x5c514e
// 005c514c  33c0                 xor eax, eax
// 005c514e  8944240c             mov dword ptr [esp + 0xc], eax
// 005c5152  8b17                 mov edx, dword ptr [edi]
// 005c5154  8b5204               mov edx, dword ptr [edx + 4]
// 005c5157  8d442408             lea eax, [esp + 8]
// 005c515b  50                   push eax
// 005c515c  6a02                 push 2
// 005c515e  8bcf                 mov ecx, edi
// 005c5160  c644243401           mov byte ptr [esp + 0x34], 1
// 005c5165  ffd2                 call edx
// 005c5167  8b442434             mov eax, dword ptr [esp + 0x34]
// 005c516b  6a00                 push 0
// 005c516d  6828f79400           push 0x94f728
// 005c5172  68fc919200           push 0x9291fc
// 005c5177  6a00                 push 0
// 005c5179  50                   push eax
// 005c517a  e847c60d00           call 0x6a17c6
// 005c517f  8bf8                 mov edi, eax
// 005c5181  83c414               add esp, 0x14
// 005c5184  85ff                 test edi, edi
// 005c5186  751e                 jne 0x5c51a6
// 005c5188  6834ba8000           push 0x80ba34
// 005c518d  8d4c241c             lea ecx, [esp + 0x1c]
// 005c5191  ff1564288000         call dword ptr [0x802864]
// 005c5197  682c368d00           push 0x8d362c
// 005c519c  8d4c241c             lea ecx, [esp + 0x1c]
// 005c51a0  51                   push ecx
// 005c51a1  e8e6c30d00           call 0x6a158c
// 005c51a6  8d4c2408             lea ecx, [esp + 8]
// 005c51aa  e8b198faff           call 0x56ea60
// 005c51af  8b10                 mov edx, dword ptr [eax]
// 005c51b1  52                   push edx
// 005c51b2  8d4c2414             lea ecx, [esp + 0x14]
// 005c51b6  e8f59efaff           call 0x56f0b0
// 005c51bb  83ec1c               sub esp, 0x1c
// 005c51be  8bcc                 mov ecx, esp
// 005c51c0  89642458             mov dword ptr [esp + 0x58], esp
// 005c51c4  50                   push eax
// 005c51c5  ff155c248000         call dword ptr [0x80245c]
// 005c51cb  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 005c51ce  8b4638               mov eax, dword ptr [esi + 0x38]
// 005c51d1  03cf                 add ecx, edi
// 005c51d3  ffd0                 call eax
// 005c51d5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c51d9  c644242c00           mov byte ptr [esp + 0x2c], 0
// 005c51de  85c9                 test ecx, ecx
// 005c51e0  7408                 je 0x5c51ea
// 005c51e2  8b11                 mov edx, dword ptr [ecx]
// 005c51e4  8b02                 mov eax, dword ptr [edx]
// 005c51e6  6a01                 push 1
// 005c51e8  ffd0                 call eax
// 005c51ea  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005c51ee  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 005c51f6  85c9                 test ecx, ecx
// 005c51f8  7408                 je 0x5c5202
// 005c51fa  8b11                 mov edx, dword ptr [ecx]
// 005c51fc  8b02                 mov eax, dword ptr [edx]
// 005c51fe  6a01                 push 1
// 005c5200  ffd0                 call eax
// 005c5202  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005c5206  5f                   pop edi
// 005c5207  64890d00000000       mov dword ptr fs:[0], ecx
// 005c520e  5e                   pop esi
// 005c520f  83c428               add esp, 0x28
// 005c5212  c20800               ret 8

// from server: 88% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <typeinfo>


namespace RBX {
    namespace Reflection {
        class DescribedBase { public:
            virtual ~DescribedBase();
        };
    }
}

namespace RBX { class Visit : public Reflection::DescribedBase {
}; }

struct Content {
    virtual ~Content();
    virtual void type() const;
    virtual Content* clone() const;
};

struct String { char bytes[28]; __declspec(dllimport) String(const String&); __declspec(dllimport) ~String(); };

struct Value {
    int value;
    Content* content;

    static Content* copyContent(Content*);
    Value(const Value&);
    ~Value();
    int* get();
    String* getString();
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
    void (__thiscall* function)(void*, String, int);
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

    RBX::Visit* server =
        dynamic_cast<RBX::Visit*>(source);

    if (!server)
        throw std::bad_cast("bad cast");

    function(reinterpret_cast<char*>(server) + adjustment,
             *a.getString(), *b.get());
}
