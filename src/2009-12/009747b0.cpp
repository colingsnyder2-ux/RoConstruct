// from server: 100% by nuck16
// roc 2009-12 009747b0  unit: seg_00970000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009747b0
//
// 009747b0  33c9                 xor ecx, ecx
// 009747b2  51                   push ecx
// 009747b3  68c86e9d00           push 0x9d6ec8
// 009747b8  68c06e9d00           push 0x9d6ec0
// 009747bd  51                   push ecx
// 009747be  b8104c6c00           mov eax, 0x6c4c10
// 009747c3  50                   push eax
// 009747c4  b9e821b900           mov ecx, 0xb921e8
// 009747c9  e892e3d4ff           call 0x6c2b60
// 009747ce  68c0599800           push 0x9859c0
// 009747d3  e85101e8ff           call 0x7f4929
// 009747d8  59                   pop ecx
// 009747d9  c3                   ret 

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

static Desc desc(&Owner::m0, "Preload", "ContentId", 0);
