// from server: 100% by nuck16
// roc 2009-12 0096c4c0  unit: seg_00960000  size: 57 bytes
//
// 0096c4c0  56                   push esi
// 0096c4c1  33f6                 xor esi, esi
// 0096c4c3  56                   push esi
// 0096c4c4  6a0f                 push 0xf
// 0096c4c6  33c9                 xor ecx, ecx
// 0096c4c8  51                   push ecx
// 0096c4c9  b8c0de5100           mov eax, 0x51dec0
// 0096c4ce  50                   push eax
// 0096c4cf  56                   push esi
// 0096c4d0  bae0f38200           mov edx, 0x82f3e0
// 0096c4d5  52                   push edx
// 0096c4d6  6884b09b00           push 0x9bb084
// 0096c4db  6888b89b00           push 0x9bb888
// 0096c4e0  b988ebb700           mov ecx, 0xb7eb88
// 0096c4e5  e846e0baff           call 0x51a530
// 0096c4ea  68f0fa9700           push 0x97faf0
// 0096c4ef  e83584e8ff           call 0x7f4929
// 0096c4f4  83c404               add esp, 4
// 0096c4f7  5e                   pop esi
// 0096c4f8  c3                   ret 

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

static Desc desc("MaxPlayers", "Data", &Owner::m0, &Owner::m1, 15, 0);
