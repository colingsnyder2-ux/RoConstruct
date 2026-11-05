// from server: 100% by nuck16
// roc 2009-12 009799c0  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009799c0
//
// 009799c0  33c9                 xor ecx, ecx
// 009799c2  51                   push ecx
// 009799c3  68f01c9e00           push 0x9e1cf0
// 009799c8  51                   push ecx
// 009799c9  b820547300           mov eax, 0x735420
// 009799ce  50                   push eax
// 009799cf  b9d864b900           mov ecx, 0xb964d8
// 009799d4  e80707dcff           call 0x73a0e0
// 009799d9  6830899800           push 0x988930
// 009799de  e846afe7ff           call 0x7f4929
// 009799e3  59                   pop ecx
// 009799e4  c3                   ret 

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

static Desc desc(&Owner::m0, "GetLastForce", 0);
