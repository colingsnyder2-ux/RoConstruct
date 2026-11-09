// from server: 100% by nuck16
// roc 2009-12 009735e0  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009735e0
//
// 009735e0  6a01                 push 1
// 009735e2  33c9                 xor ecx, ecx
// 009735e4  6814099d00           push 0x9d0914
// 009735e9  51                   push ecx
// 009735ea  b8604d6800           mov eax, 0x684d60
// 009735ef  50                   push eax
// 009735f0  b9d00fb900           mov ecx, 0xb90fd0
// 009735f5  e8f622d1ff           call 0x6858f0
// 009735fa  68604e9800           push 0x984e60
// 009735ff  e82513e8ff           call 0x7f4929
// 00973604  59                   pop ecx
// 00973605  c3                   ret 

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

static Desc desc(&Owner::m0, "Undo", 1);
