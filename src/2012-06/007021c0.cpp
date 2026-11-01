// from server: 100% by Yeetserama
// roc 2012-06 007021c0  unit: RBX::ChangeHistoryService  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007021c0
//
// 007021c0  64a100000000         mov eax, dword ptr fs:[0]
// 007021c6  6aff                 push -1
// 007021c8  6819e7ab00           push 0xabe719
// 007021cd  50                   push eax
// 007021ce  64892500000000       mov dword ptr fs:[0], esp
// 007021d5  837c242810           cmp dword ptr [esp + 0x28], 0x10
// 007021da  8b442414             mov eax, dword ptr [esp + 0x14]
// 007021de  c744240800000000     mov dword ptr [esp + 8], 0
// 007021e6  7304                 jae 0x7021ec
// 007021e8  8d442414             lea eax, [esp + 0x14]
// 007021ec  50                   push eax
// 007021ed  e8defeffff           call 0x7020d0
// 007021f2  8d4c2410             lea ecx, [esp + 0x10]
// 007021f6  c7442408ffffffff     mov dword ptr [esp + 8], 0xffffffff
// 007021fe  ff153c26b200         call dword ptr [0xb2263c]
// 00702204  8b0c24               mov ecx, dword ptr [esp]
// 00702207  64890d00000000       mov dword ptr fs:[0], ecx
// 0070220e  83c40c               add esp, 0xc
// 00702211  c21c00               ret 0x1c
// copied from an identical function in another client (function ?f@S@ns_ROCX00001a@@QAEXUString@2@@Z)

namespace ns_ROCX00001a {
// from server: 100% by king_originala
struct String;
extern void (__thiscall *destroyString)(String *);

struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char *pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

    ~String();
    const char *c_str() const;
};

inline String::~String()
{
    destroyString(this);
}

inline const char *String::c_str() const
{
    const char *result = storage.pointer;
    if (capacity < 16)
        result = storage.buffer;
    return result;
}

struct S {
    void forward(const char *);
    void f(String);
};

void S::f(String text)
{
    forward(text.c_str());
}
}
