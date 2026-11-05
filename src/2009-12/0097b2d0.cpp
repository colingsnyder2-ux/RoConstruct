// from server: 100% by nuck16
// roc 2009-12 0097b2d0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b2d0
//
// 0097b2d0  33c9                 xor ecx, ecx
// 0097b2d2  51                   push ecx
// 0097b2d3  51                   push ecx
// 0097b2d4  6890419e00           push 0x9e4190
// 0097b2d9  6814719e00           push 0x9e7114
// 0097b2de  51                   push ecx
// 0097b2df  b8f0dd7500           mov eax, 0x75ddf0
// 0097b2e4  50                   push eax
// 0097b2e5  b97079b900           mov ecx, 0xb97970
// 0097b2ea  e8a13cdeff           call 0x75ef90
// 0097b2ef  6830989800           push 0x989830
// 0097b2f4  e83096e7ff           call 0x7f4929
// 0097b2f9  59                   pop ecx
// 0097b2fa  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "AxisRotate", "axis", 0, 0);
