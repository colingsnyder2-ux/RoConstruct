// from server: 100% by nuck16
// roc 2009-12 00977ad0  unit: seg_00970000  size: 57 bytes
//
// 00977ad0  56                   push esi
// 00977ad1  33f6                 xor esi, esi
// 00977ad3  56                   push esi
// 00977ad4  6a02                 push 2
// 00977ad6  33c9                 xor ecx, ecx
// 00977ad8  51                   push ecx
// 00977ad9  b840946f00           mov eax, 0x6f9440
// 00977ade  50                   push eax
// 00977adf  56                   push esi
// 00977ae0  bac04a6f00           mov edx, 0x6f4ac0
// 00977ae5  52                   push edx
// 00977ae6  6884b09b00           push 0x9bb084
// 00977aeb  68e4cd9d00           push 0x9dcde4
// 00977af0  b90848b900           mov ecx, 0xb94808
// 00977af5  e86606d8ff           call 0x6f8160
// 00977afa  6800739800           push 0x987300
// 00977aff  e825cee7ff           call 0x7f4929
// 00977b04  83c404               add esp, 4
// 00977b07  5e                   pop esi
// 00977b08  c3                   ret 

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

static Desc desc("MouseUnitRay", "Data", &Owner::m0, &Owner::m1, 2, 0);
