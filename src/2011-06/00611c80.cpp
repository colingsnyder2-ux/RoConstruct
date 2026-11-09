// from server: 100% by Yeetserama
// roc 2011-06 00611c80  unit: RBX::ChangeHistoryService  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00611c80
//
// 00611c80  64a100000000         mov eax, dword ptr fs:[0]
// 00611c86  6aff                 push -1
// 00611c88  68e9819e00           push 0x9e81e9
// 00611c8d  50                   push eax
// 00611c8e  64892500000000       mov dword ptr fs:[0], esp
// 00611c95  837c242810           cmp dword ptr [esp + 0x28], 0x10
// 00611c9a  8b442414             mov eax, dword ptr [esp + 0x14]
// 00611c9e  c744240800000000     mov dword ptr [esp + 8], 0
// 00611ca6  7304                 jae 0x611cac
// 00611ca8  8d442414             lea eax, [esp + 0x14]
// 00611cac  50                   push eax
// 00611cad  e8cefdffff           call 0x611a80
// 00611cb2  8d4c2410             lea ecx, [esp + 0x10]
// 00611cb6  c7442408ffffffff     mov dword ptr [esp + 8], 0xffffffff
// 00611cbe  ff15d004a400         call dword ptr [0xa404d0]
// 00611cc4  8b0c24               mov ecx, dword ptr [esp]
// 00611cc7  64890d00000000       mov dword ptr fs:[0], ecx
// 00611cce  83c40c               add esp, 0xc
// 00611cd1  c21c00               ret 0x1c
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
