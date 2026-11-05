// from server: 100% by nuck16
// roc 2009-12 0097bd00  unit: seg_00970000  size: 57 bytes
//
// 0097bd00  56                   push esi
// 0097bd01  33f6                 xor esi, esi
// 0097bd03  56                   push esi
// 0097bd04  6a08                 push 8
// 0097bd06  33c9                 xor ecx, ecx
// 0097bd08  51                   push ecx
// 0097bd09  b870097700           mov eax, 0x770970
// 0097bd0e  50                   push eax
// 0097bd0f  56                   push esi
// 0097bd10  ba50887500           mov edx, 0x758850
// 0097bd15  52                   push edx
// 0097bd16  6884b09b00           push 0x9bb084
// 0097bd1b  6874899e00           push 0x9e8974
// 0097bd20  b9f086b900           mov ecx, 0xb986f0
// 0097bd25  e8b62adfff           call 0x76e7e0
// 0097bd2a  68f09f9800           push 0x989ff0
// 0097bd2f  e8f58be7ff           call 0x7f4929
// 0097bd34  83c404               add esp, 4
// 0097bd37  5e                   pop esi
// 0097bd38  c3                   ret 

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

static Desc desc("BackgroundColor", "Data", &Owner::m0, &Owner::m1, 8, 0);
