// from server: 100% by nuck16
// roc 2009-12 0097be00  unit: seg_00970000  size: 57 bytes
//
// 0097be00  56                   push esi
// 0097be01  33f6                 xor esi, esi
// 0097be03  56                   push esi
// 0097be04  6a0f                 push 0xf
// 0097be06  33c9                 xor ecx, ecx
// 0097be08  51                   push ecx
// 0097be09  b8e0fe7600           mov eax, 0x76fee0
// 0097be0e  50                   push eax
// 0097be0f  56                   push esi
// 0097be10  ba80cf7600           mov edx, 0x76cf80
// 0097be15  52                   push edx
// 0097be16  6884b09b00           push 0x9bb084
// 0097be1b  68201b9d00           push 0x9d1b20
// 0097be20  b9f083b900           mov ecx, 0xb983f0
// 0097be25  e8c62bdfff           call 0x76e9f0
// 0097be2a  6850a09800           push 0x98a050
// 0097be2f  e8f58ae7ff           call 0x7f4929
// 0097be34  83c404               add esp, 4
// 0097be37  5e                   pop esi
// 0097be38  c3                   ret 

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

static Desc desc("Active", "Data", &Owner::m0, &Owner::m1, 15, 0);
