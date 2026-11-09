// from server: 100% by nuck16
// roc 2009-12 0097b630  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b630
//
// 0097b630  6a01                 push 1
// 0097b632  689cb19b00           push 0x9bb19c
// 0097b637  33c9                 xor ecx, ecx
// 0097b639  68807b9e00           push 0x9e7b80
// 0097b63e  51                   push ecx
// 0097b63f  b8e0265100           mov eax, 0x5126e0
// 0097b644  50                   push eax
// 0097b645  b9d07bb900           mov ecx, 0xb97bd0
// 0097b64a  e8b185deff           call 0x763c00
// 0097b64f  6870999800           push 0x989970
// 0097b654  e8d092e7ff           call 0x7f4929
// 0097b659  59                   pop ecx
// 0097b65a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetIsBadgeDisabledUrl", "url", 1);
