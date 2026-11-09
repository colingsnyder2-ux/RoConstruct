// from server: 100% by nuck16
// roc 2009-12 0097bb00  unit: seg_00970000  size: 57 bytes
//
// 0097bb00  56                   push esi
// 0097bb01  33f6                 xor esi, esi
// 0097bb03  56                   push esi
// 0097bb04  6a0f                 push 0xf
// 0097bb06  33c9                 xor ecx, ecx
// 0097bb08  51                   push ecx
// 0097bb09  b8a0b77600           mov eax, 0x76b7a0
// 0097bb0e  50                   push eax
// 0097bb0f  56                   push esi
// 0097bb10  ba70b77600           mov edx, 0x76b770
// 0097bb15  52                   push edx
// 0097bb16  6884b09b00           push 0x9bb084
// 0097bb1b  6814ce9d00           push 0x9dce14
// 0097bb20  b90080b900           mov ecx, 0xb98000
// 0097bb25  e8f603dfff           call 0x76bf20
// 0097bb2a  68309b9800           push 0x989b30
// 0097bb2f  e8f58de7ff           call 0x7f4929
// 0097bb34  83c404               add esp, 4
// 0097bb37  5e                   pop esi
// 0097bb38  c3                   ret 

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

static Desc desc("Icon", "Data", &Owner::m0, &Owner::m1, 15, 0);
