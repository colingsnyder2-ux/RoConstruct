// from server: 100% by nuck16
// roc 2009-12 00974610  unit: seg_00970000  size: 57 bytes
//
// 00974610  56                   push esi
// 00974611  33f6                 xor esi, esi
// 00974613  56                   push esi
// 00974614  6a0f                 push 0xf
// 00974616  33c9                 xor ecx, ecx
// 00974618  51                   push ecx
// 00974619  b8d0ba6b00           mov eax, 0x6bbad0
// 0097461e  50                   push eax
// 0097461f  56                   push esi
// 00974620  ba60294b00           mov edx, 0x4b2960
// 00974625  52                   push edx
// 00974626  68dc1f9d00           push 0x9d1fdc
// 0097462b  68ac2a9b00           push 0x9b2aac
// 00974630  b9dc20b900           mov ecx, 0xb920dc
// 00974635  e81672d4ff           call 0x6bb850
// 0097463a  6850599800           push 0x985950
// 0097463f  e8e502e8ff           call 0x7f4929
// 00974644  83c404               add esp, 4
// 00974647  5e                   pop esi
// 00974648  c3                   ret 

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

static Desc desc("Texture", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
