// from server: 100% by nuck16
// roc 2009-12 009787c0  unit: seg_00970000  size: 57 bytes
//
// 009787c0  56                   push esi
// 009787c1  33f6                 xor esi, esi
// 009787c3  56                   push esi
// 009787c4  6a0f                 push 0xf
// 009787c6  33c9                 xor ecx, ecx
// 009787c8  51                   push ecx
// 009787c9  b8e06c7100           mov eax, 0x716ce0
// 009787ce  50                   push eax
// 009787cf  56                   push esi
// 009787d0  bab0587100           mov edx, 0x7158b0
// 009787d5  52                   push edx
// 009787d6  6884b09b00           push 0x9bb084
// 009787db  68e8f49d00           push 0x9df4e8
// 009787e0  b91c57b900           mov ecx, 0xb9571c
// 009787e5  e896ded9ff           call 0x716680
// 009787ea  68507c9800           push 0x987c50
// 009787ef  e835c1e7ff           call 0x7f4929
// 009787f4  83c404               add esp, 4
// 009787f7  5e                   pop esi
// 009787f8  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
    void m1();
};


struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("F2", "Data", &Owner::m0, &Owner::m1, 15, 0);
