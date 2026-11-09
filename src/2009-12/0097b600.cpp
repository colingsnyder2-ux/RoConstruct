// from server: 100% by nuck16
// roc 2009-12 0097b600  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b600
//
// 0097b600  6a01                 push 1
// 0097b602  689cb19b00           push 0x9bb19c
// 0097b607  33c9                 xor ecx, ecx
// 0097b609  68707b9e00           push 0x9e7b70
// 0097b60e  51                   push ecx
// 0097b60f  b880275100           mov eax, 0x512780
// 0097b614  50                   push eax
// 0097b615  b9387bb900           mov ecx, 0xb97b38
// 0097b61a  e8e185deff           call 0x763c00
// 0097b61f  6860999800           push 0x989960
// 0097b624  e80093e7ff           call 0x7f4929
// 0097b629  59                   pop ecx
// 0097b62a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetHasBadgeUrl", "url", 1);
