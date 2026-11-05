// from server: 100% by nuck16
// roc 2009-12 00976890  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00976890
//
// 00976890  6a01                 push 1
// 00976892  688cb39d00           push 0x9db38c
// 00976897  33c9                 xor ecx, ecx
// 00976899  6894b39d00           push 0x9db394
// 0097689e  51                   push ecx
// 0097689f  b828010000           mov eax, 0x128
// 009768a4  50                   push eax
// 009768a5  b9403eb900           mov ecx, 0xb93e40
// 009768aa  e86119d7ff           call 0x6e8210
// 009768af  6800689800           push 0x986800
// 009768b4  e870e0e7ff           call 0x7f4929
// 009768b9  59                   pop ecx
// 009768ba  c3                   ret 

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

static Desc desc(&Owner::m0, "FreeFalling", "active", 1);
