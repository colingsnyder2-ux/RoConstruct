// from server: 100% by nuck16
// roc 2009-12 0097b660  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b660
//
// 0097b660  6a01                 push 1
// 0097b662  689cb19b00           push 0x9bb19c
// 0097b667  33c9                 xor ecx, ecx
// 0097b669  68987b9e00           push 0x9e7b98
// 0097b66e  51                   push ecx
// 0097b66f  b8400e7600           mov eax, 0x760e40
// 0097b674  50                   push eax
// 0097b675  b9b07cb900           mov ecx, 0xb97cb0
// 0097b67a  e88185deff           call 0x763c00
// 0097b67f  6880999800           push 0x989980
// 0097b684  e8a092e7ff           call 0x7f4929
// 0097b689  59                   pop ecx
// 0097b68a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetIsBadgeLegalUrl", "url", 1);
