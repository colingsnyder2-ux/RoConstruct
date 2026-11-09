// from server: 100% by nuck16
// roc 2009-12 009736f0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009736f0
//
// 009736f0  33c9                 xor ecx, ecx
// 009736f2  51                   push ecx
// 009736f3  6a0f                 push 0xf
// 009736f5  51                   push ecx
// 009736f6  b850ed6800           mov eax, 0x68ed50
// 009736fb  50                   push eax
// 009736fc  6814010000           push 0x114
// 00973701  6884b09b00           push 0x9bb084
// 00973706  68201b9d00           push 0x9d1b20
// 0097370b  b93411b900           mov ecx, 0xb91134
// 00973710  e80bc2d1ff           call 0x68f920
// 00973715  68c04f9800           push 0x984fc0
// 0097371a  e80a12e8ff           call 0x7f4929
// 0097371f  59                   pop ecx
// 00973720  c3                   ret 

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
    Desc(const char *, const char *, int, void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Active", "Data", 276, &Owner::m0, 15, 0);
