// from server: 100% by nuck16
// roc 2009-12 0097b5d0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b5d0
//
// 0097b5d0  6a01                 push 1
// 0097b5d2  689cb19b00           push 0x9bb19c
// 0097b5d7  33c9                 xor ecx, ecx
// 0097b5d9  685c7b9e00           push 0x9e7b5c
// 0097b5de  51                   push ecx
// 0097b5df  b8d0245100           mov eax, 0x5124d0
// 0097b5e4  50                   push eax
// 0097b5e5  b9987db900           mov ecx, 0xb97d98
// 0097b5ea  e81186deff           call 0x763c00
// 0097b5ef  68a0999800           push 0x9899a0
// 0097b5f4  e83093e7ff           call 0x7f4929
// 0097b5f9  59                   pop ecx
// 0097b5fa  c3                   ret 

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

static Desc desc(&Owner::m0, "SetAwardBadgeUrl", "url", 1);
