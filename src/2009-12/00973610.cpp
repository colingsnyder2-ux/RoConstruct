// from server: 100% by nuck16
// roc 2009-12 00973610  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973610
//
// 00973610  6a01                 push 1
// 00973612  33c9                 xor ecx, ecx
// 00973614  681c099d00           push 0x9d091c
// 00973619  51                   push ecx
// 0097361a  b8905f6800           mov eax, 0x685f90
// 0097361f  50                   push eax
// 00973620  b9900fb900           mov ecx, 0xb90f90
// 00973625  e8a623d1ff           call 0x6859d0
// 0097362a  68304f9800           push 0x984f30
// 0097362f  e8f512e8ff           call 0x7f4929
// 00973634  59                   pop ecx
// 00973635  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "GetCanUndo", 1);
