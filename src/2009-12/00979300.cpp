// from server: 100% by nuck16
// roc 2009-12 00979300  unit: seg_00970000  size: 57 bytes
//
// 00979300  56                   push esi
// 00979301  33f6                 xor esi, esi
// 00979303  56                   push esi
// 00979304  6a0f                 push 0xf
// 00979306  33c9                 xor ecx, ecx
// 00979308  51                   push ecx
// 00979309  b800367300           mov eax, 0x733600
// 0097930e  50                   push eax
// 0097930f  56                   push esi
// 00979310  ba00da7200           mov edx, 0x72da00
// 00979315  52                   push edx
// 00979316  6884b09b00           push 0x9bb084
// 0097931b  68040a9e00           push 0x9e0a04
// 00979320  b9805db900           mov ecx, 0xb95d80
// 00979325  e87655dbff           call 0x72e8a0
// 0097932a  6810819800           push 0x988110
// 0097932f  e8f5b5e7ff           call 0x7f4929
// 00979334  83c404               add esp, 4
// 00979337  5e                   pop esi
// 00979338  c3                   ret 

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

static Desc desc("ConstrainedValue", "Data", &Owner::m0, &Owner::m1, 15, 0);
