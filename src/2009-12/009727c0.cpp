// from server: 100% by nuck16
// roc 2009-12 009727c0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009727c0
//
// 009727c0  6a04                 push 4
// 009727c2  689cb19b00           push 0x9bb19c
// 009727c7  33c9                 xor ecx, ecx
// 009727c9  68c4f29c00           push 0x9cf2c4
// 009727ce  51                   push ecx
// 009727cf  b830126700           mov eax, 0x671230
// 009727d4  50                   push eax
// 009727d5  b9d008b900           mov ecx, 0xb908d0
// 009727da  e801bccfff           call 0x66e3e0
// 009727df  6820499800           push 0x984920
// 009727e4  e84021e8ff           call 0x7f4929
// 009727e9  59                   pop ecx
// 009727ea  c3                   ret 

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

static Desc desc(&Owner::m0, "Save", "url", 4);
