// from server: 100% by nuck16
// roc 2009-12 009768c0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009768c0
//
// 009768c0  6a01                 push 1
// 009768c2  688cb39d00           push 0x9db38c
// 009768c7  33c9                 xor ecx, ecx
// 009768c9  68a0b39d00           push 0x9db3a0
// 009768ce  51                   push ecx
// 009768cf  b830010000           mov eax, 0x130
// 009768d4  50                   push eax
// 009768d5  b9a037b900           mov ecx, 0xb937a0
// 009768da  e83119d7ff           call 0x6e8210
// 009768df  6840689800           push 0x986840
// 009768e4  e840e0e7ff           call 0x7f4929
// 009768e9  59                   pop ecx
// 009768ea  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(void (Owner::*)(), const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "GettingUp", "active", 1);
