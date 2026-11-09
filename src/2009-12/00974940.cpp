// from server: 100% by nuck16
// roc 2009-12 00974940  unit: seg_00970000  size: 57 bytes
//
// 00974940  56                   push esi
// 00974941  33f6                 xor esi, esi
// 00974943  56                   push esi
// 00974944  6a0f                 push 0xf
// 00974946  33c9                 xor ecx, ecx
// 00974948  51                   push ecx
// 00974949  b8b0606c00           mov eax, 0x6c60b0
// 0097494e  50                   push eax
// 0097494f  56                   push esi
// 00974950  ba905c6c00           mov edx, 0x6c5c90
// 00974955  52                   push edx
// 00974956  6810719d00           push 0x9d7110
// 0097495b  686c719d00           push 0x9d716c
// 00974960  b97c24b900           mov ecx, 0xb9247c
// 00974965  e83615d5ff           call 0x6c5ea0
// 0097496a  68405a9800           push 0x985a40
// 0097496f  e8b5ffe7ff           call 0x7f4929
// 00974974  83c404               add esp, 4
// 00974977  5e                   pop esi
// 00974978  c3                   ret 

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

static Desc desc("AreOwnersShown", "Display", &Owner::m0, &Owner::m1, 15, 0);
