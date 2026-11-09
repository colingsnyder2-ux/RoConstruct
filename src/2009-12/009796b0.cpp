// from server: 100% by nuck16
// roc 2009-12 009796b0  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009796b0
//
// 009796b0  33c9                 xor ecx, ecx
// 009796b2  51                   push ecx
// 009796b3  68a81c9e00           push 0x9e1ca8
// 009796b8  51                   push ecx
// 009796b9  b8e0567300           mov eax, 0x7356e0
// 009796be  50                   push eax
// 009796bf  b97866b900           mov ecx, 0xb96678
// 009796c4  e83708dcff           call 0x739f00
// 009796c9  6870899800           push 0x988970
// 009796ce  e856b2e7ff           call 0x7f4929
// 009796d3  59                   pop ecx
// 009796d4  c3                   ret 

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

static Desc desc(&Owner::m0, "Abort", 0);
