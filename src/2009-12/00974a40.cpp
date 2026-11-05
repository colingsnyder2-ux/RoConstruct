// from server: 100% by nuck16
// roc 2009-12 00974a40  unit: seg_00970000  size: 57 bytes
//
// 00974a40  56                   push esi
// 00974a41  33f6                 xor esi, esi
// 00974a43  56                   push esi
// 00974a44  6a0f                 push 0xf
// 00974a46  33c9                 xor ecx, ecx
// 00974a48  51                   push ecx
// 00974a49  b870616c00           mov eax, 0x6c6170
// 00974a4e  50                   push eax
// 00974a4f  56                   push esi
// 00974a50  bad05c6c00           mov edx, 0x6c5cd0
// 00974a55  52                   push edx
// 00974a56  6858aa9a00           push 0x9aaa58
// 00974a5b  68bc719d00           push 0x9d71bc
// 00974a60  b95823b900           mov ecx, 0xb92358
// 00974a65  e83614d5ff           call 0x6c5ea0
// 00974a6a  68c05a9800           push 0x985ac0
// 00974a6f  e8b5fee7ff           call 0x7f4929
// 00974a74  83c404               add esp, 4
// 00974a77  5e                   pop esi
// 00974a78  c3                   ret 

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

static Desc desc("AllowSleep", "Performance", &Owner::m0, &Owner::m1, 15, 0);
