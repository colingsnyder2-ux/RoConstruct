// from server: 100% by nuck16
// roc 2009-12 0097ab70  unit: seg_00970000  size: 57 bytes
//
// 0097ab70  56                   push esi
// 0097ab71  33f6                 xor esi, esi
// 0097ab73  56                   push esi
// 0097ab74  6a02                 push 2
// 0097ab76  33c9                 xor ecx, ecx
// 0097ab78  51                   push ecx
// 0097ab79  b8606b7500           mov eax, 0x756b60
// 0097ab7e  50                   push eax
// 0097ab7f  56                   push esi
// 0097ab80  baf06a7500           mov edx, 0x756af0
// 0097ab85  52                   push edx
// 0097ab86  6884b09b00           push 0x9bb084
// 0097ab8b  6898539e00           push 0x9e5398
// 0097ab90  b96874b900           mov ecx, 0xb97468
// 0097ab95  e846c3ddff           call 0x756ee0
// 0097ab9a  6850949800           push 0x989450
// 0097ab9f  e8859de7ff           call 0x7f4929
// 0097aba4  83c404               add esp, 4
// 0097aba7  5e                   pop esi
// 0097aba8  c3                   ret 

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

static Desc desc("ReplicatingAbsolutePosition", "Data", &Owner::m0, &Owner::m1, 2, 0);
