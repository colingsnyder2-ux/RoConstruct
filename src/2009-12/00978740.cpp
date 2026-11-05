// from server: 100% by nuck16
// roc 2009-12 00978740  unit: seg_00970000  size: 57 bytes
//
// 00978740  56                   push esi
// 00978741  33f6                 xor esi, esi
// 00978743  56                   push esi
// 00978744  6a0f                 push 0xf
// 00978746  33c9                 xor ecx, ecx
// 00978748  51                   push ecx
// 00978749  b8606c7100           mov eax, 0x716c60
// 0097874e  50                   push eax
// 0097874f  56                   push esi
// 00978750  ba70587100           mov edx, 0x715870
// 00978755  52                   push edx
// 00978756  6884b09b00           push 0x9bb084
// 0097875b  68e0f49d00           push 0x9df4e0
// 00978760  b93c57b900           mov ecx, 0xb9573c
// 00978765  e816dfd9ff           call 0x716680
// 0097876a  68107d9800           push 0x987d10
// 0097876f  e8b5c1e7ff           call 0x7f4929
// 00978774  83c404               add esp, 4
// 00978777  5e                   pop esi
// 00978778  c3                   ret 

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

static Desc desc("F0", "Data", &Owner::m0, &Owner::m1, 15, 0);
