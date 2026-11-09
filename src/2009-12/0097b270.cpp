// from server: 100% by nuck16
// roc 2009-12 0097b270  unit: seg_00970000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b270
//
// 0097b270  33c9                 xor ecx, ecx
// 0097b272  51                   push ecx
// 0097b273  6800719e00           push 0x9e7100
// 0097b278  68f4709e00           push 0x9e70f4
// 0097b27d  51                   push ecx
// 0097b27e  b8f0db7500           mov eax, 0x75dbf0
// 0097b283  50                   push eax
// 0097b284  b9c878b900           mov ecx, 0xb978c8
// 0097b289  e8623adeff           call 0x75ecf0
// 0097b28e  68e0979800           push 0x9897e0
// 0097b293  e89196e7ff           call 0x7f4929
// 0097b298  59                   pop ecx
// 0097b299  c3                   ret 

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

static Desc desc(&Owner::m0, "MouseMove", "MouseRay", 0);
