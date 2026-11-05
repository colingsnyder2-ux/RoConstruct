// from server: 100% by nuck16
// roc 2009-12 009780c0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009780c0
//
// 009780c0  6a01                 push 1
// 009780c2  68fce19d00           push 0x9de1fc
// 009780c7  33c9                 xor ecx, ecx
// 009780c9  68e8e19d00           push 0x9de1e8
// 009780ce  51                   push ecx
// 009780cf  b870297000           mov eax, 0x702970
// 009780d4  50                   push eax
// 009780d5  b93050b900           mov ecx, 0xb95030
// 009780da  e8112ed9ff           call 0x70aef0
// 009780df  68f0789800           push 0x9878f0
// 009780e4  e840c8e7ff           call 0x7f4929
// 009780e9  59                   pop ecx
// 009780ea  c3                   ret 

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

static Desc desc(&Owner::m0, "SetBaseCategoryUrl", "baseCategoryUrl", 1);
