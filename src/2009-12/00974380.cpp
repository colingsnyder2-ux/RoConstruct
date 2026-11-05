// from server: 100% by nuck16
// roc 2009-12 00974380  unit: seg_00970000  size: 57 bytes
//
// 00974380  56                   push esi
// 00974381  33f6                 xor esi, esi
// 00974383  56                   push esi
// 00974384  6a0f                 push 0xf
// 00974386  33c9                 xor ecx, ecx
// 00974388  51                   push ecx
// 00974389  b8c0956b00           mov eax, 0x6b95c0
// 0097438e  50                   push eax
// 0097438f  56                   push esi
// 00974390  ba003a6b00           mov edx, 0x6b3a00
// 00974395  52                   push edx
// 00974396  6898bf9c00           push 0x9cbf98
// 0097439b  685c669d00           push 0x9d665c
// 009743a0  b9cc1bb900           mov ecx, 0xb91bcc
// 009743a5  e8f627d4ff           call 0x6b6ba0
// 009743aa  6850579800           push 0x985750
// 009743af  e87505e8ff           call 0x7f4929
// 009743b4  83c404               add esp, 4
// 009743b7  5e                   pop esi
// 009743b8  c3                   ret 

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

static Desc desc("Looped", "Behavior", &Owner::m0, &Owner::m1, 15, 0);
