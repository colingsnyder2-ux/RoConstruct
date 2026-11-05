// from server: 100% by nuck16
// roc 2009-12 00979480  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979480
//
// 00979480  33c9                 xor ecx, ecx
// 00979482  51                   push ecx
// 00979483  6a0f                 push 0xf
// 00979485  51                   push ecx
// 00979486  b850547300           mov eax, 0x735450
// 0097948b  50                   push eax
// 0097948c  6870010000           push 0x170
// 00979491  68141c9e00           push 0x9e1c14
// 00979496  681c1c9e00           push 0x9e1c1c
// 0097949b  b93863b900           mov ecx, 0xb96338
// 009794a0  e8dbefdbff           call 0x738480
// 009794a5  68b0889800           push 0x9888b0
// 009794aa  e87ab4e7ff           call 0x7f4929
// 009794af  59                   pop ecx
// 009794b0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(const char *, const char *, int, void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TargetOffset", "Goals", 368, &Owner::m0, 15, 0);
