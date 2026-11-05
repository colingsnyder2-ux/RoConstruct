// from server: 100% by nuck16
// roc 2009-12 0097b2a0  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b2a0
//
// 0097b2a0  33c9                 xor ecx, ecx
// 0097b2a2  51                   push ecx
// 0097b2a3  680c719e00           push 0x9e710c
// 0097b2a8  51                   push ecx
// 0097b2a9  b870d27500           mov eax, 0x75d270
// 0097b2ae  50                   push eax
// 0097b2af  b98878b900           mov ecx, 0xb97888
// 0097b2b4  e8f73bdeff           call 0x75eeb0
// 0097b2b9  68f0979800           push 0x9897f0
// 0097b2be  e86696e7ff           call 0x7f4929
// 0097b2c3  59                   pop ecx
// 0097b2c4  c3                   ret 

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

static Desc desc(&Owner::m0, "MouseUp", 0);
