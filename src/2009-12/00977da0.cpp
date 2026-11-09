// from server: 100% by nuck16
// roc 2009-12 00977da0  unit: seg_00970000  size: 57 bytes
//
// 00977da0  56                   push esi
// 00977da1  33f6                 xor esi, esi
// 00977da3  56                   push esi
// 00977da4  6a0f                 push 0xf
// 00977da6  33c9                 xor ecx, ecx
// 00977da8  51                   push ecx
// 00977da9  b8f0e56f00           mov eax, 0x6fe5f0
// 00977dae  50                   push eax
// 00977daf  56                   push esi
// 00977db0  ba402a6800           mov edx, 0x682a40
// 00977db5  52                   push edx
// 00977db6  68dc1f9d00           push 0x9d1fdc
// 00977dbb  688cdb9d00           push 0x9ddb8c
// 00977dc0  b94c4db900           mov ecx, 0xb94d4c
// 00977dc5  e87676d8ff           call 0x6ff440
// 00977dca  6860769800           push 0x987660
// 00977dcf  e855cbe7ff           call 0x7f4929
// 00977dd4  83c404               add esp, 4
// 00977dd7  5e                   pop esi
// 00977dd8  c3                   ret 

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

static Desc desc("ShirtTemplate", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
