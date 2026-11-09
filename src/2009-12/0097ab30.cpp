// from server: 100% by nuck16
// roc 2009-12 0097ab30  unit: seg_00970000  size: 57 bytes
//
// 0097ab30  56                   push esi
// 0097ab31  33f6                 xor esi, esi
// 0097ab33  56                   push esi
// 0097ab34  6a02                 push 2
// 0097ab36  33c9                 xor ecx, ecx
// 0097ab38  51                   push ecx
// 0097ab39  b8006b7500           mov eax, 0x756b00
// 0097ab3e  50                   push eax
// 0097ab3f  56                   push esi
// 0097ab40  baf06a7500           mov edx, 0x756af0
// 0097ab45  52                   push edx
// 0097ab46  6884b09b00           push 0x9bb084
// 0097ab4b  6880539e00           push 0x9e5380
// 0097ab50  b94874b900           mov ecx, 0xb97448
// 0097ab55  e886c3ddff           call 0x756ee0
// 0097ab5a  6870949800           push 0x989470
// 0097ab5f  e8c59de7ff           call 0x7f4929
// 0097ab64  83c404               add esp, 4
// 0097ab67  5e                   pop esi
// 0097ab68  c3                   ret 

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

static Desc desc("ReplicatingAbsoluteSize", "Data", &Owner::m0, &Owner::m1, 2, 0);
