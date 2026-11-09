// from server: 100% by nuck16
// roc 2009-12 00978b70  unit: seg_00970000  size: 57 bytes
//
// 00978b70  56                   push esi
// 00978b71  33f6                 xor esi, esi
// 00978b73  56                   push esi
// 00978b74  6a06                 push 6
// 00978b76  33c9                 xor ecx, ecx
// 00978b78  51                   push ecx
// 00978b79  b8a0d07100           mov eax, 0x71d0a0
// 00978b7e  50                   push eax
// 00978b7f  56                   push esi
// 00978b80  bae0396b00           mov edx, 0x6b39e0
// 00978b85  52                   push edx
// 00978b86  6884b09b00           push 0x9bb084
// 00978b8b  6880fa9d00           push 0x9dfa80
// 00978b90  b9385ab900           mov ecx, 0xb95a38
// 00978b95  e8e643daff           call 0x71cf80
// 00978b9a  68807f9800           push 0x987f80
// 00978b9f  e885bde7ff           call 0x7f4929
// 00978ba4  83c404               add esp, 4
// 00978ba7  5e                   pop esi
// 00978ba8  c3                   ret 

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

static Desc desc("Bevel", "Data", &Owner::m0, &Owner::m1, 6, 0);
