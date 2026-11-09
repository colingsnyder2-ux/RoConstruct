// from server: 100% by nuck16
// roc 2009-12 009729c0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009729c0
//
// 009729c0  6a01                 push 1
// 009729c2  6804b19b00           push 0x9bb104
// 009729c7  33c9                 xor ecx, ecx
// 009729c9  6864f39c00           push 0x9cf364
// 009729ce  51                   push ecx
// 009729cf  b8f0576600           mov eax, 0x6657f0
// 009729d4  50                   push eax
// 009729d5  b9e007b900           mov ecx, 0xb907e0
// 009729da  e821becfff           call 0x66e800
// 009729df  68b0499800           push 0x9849b0
// 009729e4  e8401fe8ff           call 0x7f4929
// 009729e9  59                   pop ecx
// 009729ea  c3                   ret 

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

static Desc desc(&Owner::m0, "SetMessage", "message", 1);
