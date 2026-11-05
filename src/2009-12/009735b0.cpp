// from server: 100% by nuck16
// roc 2009-12 009735b0  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009735b0
//
// 009735b0  6a01                 push 1
// 009735b2  33c9                 xor ecx, ecx
// 009735b4  680c099d00           push 0x9d090c
// 009735b9  51                   push ecx
// 009735ba  b8703c6800           mov eax, 0x683c70
// 009735bf  50                   push eax
// 009735c0  b96010b900           mov ecx, 0xb91060
// 009735c5  e82623d1ff           call 0x6858f0
// 009735ca  68f04e9800           push 0x984ef0
// 009735cf  e85513e8ff           call 0x7f4929
// 009735d4  59                   pop ecx
// 009735d5  c3                   ret 

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

static Desc desc(&Owner::m0, "Redo", 1);
