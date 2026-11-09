// from server: 100% by nuck16
// roc 2009-12 0097a100  unit: seg_00970000  size: 57 bytes
//
// 0097a100  56                   push esi
// 0097a101  33f6                 xor esi, esi
// 0097a103  56                   push esi
// 0097a104  6a0f                 push 0xf
// 0097a106  33c9                 xor ecx, ecx
// 0097a108  51                   push ecx
// 0097a109  b870387400           mov eax, 0x743870
// 0097a10e  50                   push eax
// 0097a10f  56                   push esi
// 0097a110  ba40597100           mov edx, 0x715940
// 0097a115  52                   push edx
// 0097a116  6884b09b00           push 0x9bb084
// 0097a11b  6818f59d00           push 0x9df518
// 0097a120  b9dc6db900           mov ecx, 0xb96ddc
// 0097a125  e83692dcff           call 0x743360
// 0097a12a  68b08d9800           push 0x988db0
// 0097a12f  e8f5a7e7ff           call 0x7f4929
// 0097a134  83c404               add esp, 4
// 0097a137  5e                   pop esi
// 0097a138  c3                   ret 

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

static Desc desc("CurrentAngle", "Data", &Owner::m0, &Owner::m1, 15, 0);
