// from server: 100% by nuck16
// roc 2009-12 00974980  unit: seg_00970000  size: 57 bytes
//
// 00974980  56                   push esi
// 00974981  33f6                 xor esi, esi
// 00974983  56                   push esi
// 00974984  6a0f                 push 0xf
// 00974986  33c9                 xor ecx, ecx
// 00974988  51                   push ecx
// 00974989  b8e0606c00           mov eax, 0x6c60e0
// 0097498e  50                   push eax
// 0097498f  56                   push esi
// 00974990  baa05c6c00           mov edx, 0x6c5ca0
// 00974995  52                   push edx
// 00974996  6810719d00           push 0x9d7110
// 0097499b  687c719d00           push 0x9d717c
// 009749a0  b95c24b900           mov ecx, 0xb9245c
// 009749a5  e8f614d5ff           call 0x6c5ea0
// 009749aa  68605a9800           push 0x985a60
// 009749af  e875ffe7ff           call 0x7f4929
// 009749b4  83c404               add esp, 4
// 009749b7  5e                   pop esi
// 009749b8  c3                   ret 

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

static Desc desc("AreRegionsShown", "Display", &Owner::m0, &Owner::m1, 15, 0);
