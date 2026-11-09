// from server: 100% by nuck16
// roc 2009-12 00979990  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979990
//
// 00979990  33c9                 xor ecx, ecx
// 00979992  51                   push ecx
// 00979993  68e41c9e00           push 0x9e1ce4
// 00979998  51                   push ecx
// 00979999  b820547300           mov eax, 0x735420
// 0097999e  50                   push eax
// 0097999f  b9d865b900           mov ecx, 0xb965d8
// 009799a4  e83707dcff           call 0x73a0e0
// 009799a9  68f0899800           push 0x9889f0
// 009799ae  e876afe7ff           call 0x7f4929
// 009799b3  59                   pop ecx
// 009799b4  c3                   ret 

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

static Desc desc(&Owner::m0, "lastForce", 0);
