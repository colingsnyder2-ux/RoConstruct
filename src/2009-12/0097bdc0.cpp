// from server: 100% by nuck16
// roc 2009-12 0097bdc0  unit: seg_00970000  size: 57 bytes
//
// 0097bdc0  56                   push esi
// 0097bdc1  33f6                 xor esi, esi
// 0097bdc3  56                   push esi
// 0097bdc4  6a0f                 push 0xf
// 0097bdc6  33c9                 xor ecx, ecx
// 0097bdc8  51                   push ecx
// 0097bdc9  b8a0fe7600           mov eax, 0x76fea0
// 0097bdce  50                   push eax
// 0097bdcf  56                   push esi
// 0097bdd0  ba40777500           mov edx, 0x757740
// 0097bdd5  52                   push edx
// 0097bdd6  6884b09b00           push 0x9bb084
// 0097bddb  68b0589b00           push 0x9b58b0
// 0097bde0  b95c85b900           mov ecx, 0xb9855c
// 0097bde5  e8062cdfff           call 0x76e9f0
// 0097bdea  6870a09800           push 0x98a070
// 0097bdef  e8358be7ff           call 0x7f4929
// 0097bdf4  83c404               add esp, 4
// 0097bdf7  5e                   pop esi
// 0097bdf8  c3                   ret 

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

static Desc desc("Visible", "Data", &Owner::m0, &Owner::m1, 15, 0);
