// from server: 100% by nuck16
// roc 2009-12 009780f0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009780f0
//
// 009780f0  6a01                 push 1
// 009780f2  6820e29d00           push 0x9de220
// 009780f7  33c9                 xor ecx, ecx
// 009780f9  680ce29d00           push 0x9de20c
// 009780fe  51                   push ecx
// 009780ff  b8c0297000           mov eax, 0x7029c0
// 00978104  50                   push eax
// 00978105  b9e84fb900           mov ecx, 0xb94fe8
// 0097810a  e8e12dd9ff           call 0x70aef0
// 0097810f  6870789800           push 0x987870
// 00978114  e810c8e7ff           call 0x7f4929
// 00978119  59                   pop ecx
// 0097811a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetUserCategoryUrl", "userCategoryUrl", 1);
