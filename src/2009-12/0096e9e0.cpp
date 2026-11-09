// from server: 100% by nuck16
// roc 2009-12 0096e9e0  unit: seg_00960000  size: 57 bytes
//
// 0096e9e0  56                   push esi
// 0096e9e1  33f6                 xor esi, esi
// 0096e9e3  56                   push esi
// 0096e9e4  6a0f                 push 0xf
// 0096e9e6  33c9                 xor ecx, ecx
// 0096e9e8  51                   push ecx
// 0096e9e9  b8e0bd6200           mov eax, 0x62bde0
// 0096e9ee  50                   push eax
// 0096e9ef  56                   push esi
// 0096e9f0  bad0bd6200           mov edx, 0x62bdd0
// 0096e9f5  52                   push edx
// 0096e9f6  6868bc9c00           push 0x9cbc68
// 0096e9fb  6884bc9c00           push 0x9cbc84
// 0096ea00  b9ac4ab800           mov ecx, 0xb84aac
// 0096ea05  e8060eccff           call 0x62f810
// 0096ea0a  68e00f9800           push 0x980fe0
// 0096ea0f  e8155fe8ff           call 0x7f4929
// 0096ea14  83c404               add esp, 4
// 0096ea17  5e                   pop esi
// 0096ea18  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
    void m1();
};


struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("AreSignalErrorsSuppressed", "Limits", &Owner::m0, &Owner::m1, 15, 0);
