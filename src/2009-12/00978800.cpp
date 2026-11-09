// from server: 100% by nuck16
// roc 2009-12 00978800  unit: seg_00970000  size: 57 bytes
//
// 00978800  56                   push esi
// 00978801  33f6                 xor esi, esi
// 00978803  56                   push esi
// 00978804  6a0f                 push 0xf
// 00978806  33c9                 xor ecx, ecx
// 00978808  51                   push ecx
// 00978809  b8206d7100           mov eax, 0x716d20
// 0097880e  50                   push eax
// 0097880f  56                   push esi
// 00978810  bad0587100           mov edx, 0x7158d0
// 00978815  52                   push edx
// 00978816  6884b09b00           push 0x9bb084
// 0097881b  68ecf49d00           push 0x9df4ec
// 00978820  b9bc57b900           mov ecx, 0xb957bc
// 00978825  e856ded9ff           call 0x716680
// 0097882a  68707c9800           push 0x987c70
// 0097882f  e8f5c0e7ff           call 0x7f4929
// 00978834  83c404               add esp, 4
// 00978837  5e                   pop esi
// 00978838  c3                   ret 

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

static Desc desc("F3", "Data", &Owner::m0, &Owner::m1, 15, 0);
