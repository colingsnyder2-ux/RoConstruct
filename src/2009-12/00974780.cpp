// from server: 100% by nuck16
// roc 2009-12 00974780  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974780
//
// 00974780  6a01                 push 1
// 00974782  68a86e9d00           push 0x9d6ea8
// 00974787  33c9                 xor ecx, ecx
// 00974789  68b06e9d00           push 0x9d6eb0
// 0097478e  51                   push ecx
// 0097478f  b830326c00           mov eax, 0x6c3230
// 00974794  50                   push eax
// 00974795  b93022b900           mov ecx, 0xb92230
// 0097479a  e831e2d4ff           call 0x6c29d0
// 0097479f  68b0599800           push 0x9859b0
// 009747a4  e88001e8ff           call 0x7f4929
// 009747a9  59                   pop ecx
// 009747aa  c3                   ret 

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

static Desc desc(&Owner::m0, "SetCacheSize", "count", 1);
