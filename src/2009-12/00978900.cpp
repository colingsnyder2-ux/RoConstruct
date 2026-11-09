// from server: 100% by nuck16
// roc 2009-12 00978900  unit: seg_00970000  size: 57 bytes
//
// 00978900  56                   push esi
// 00978901  33f6                 xor esi, esi
// 00978903  56                   push esi
// 00978904  6a09                 push 9
// 00978906  33c9                 xor ecx, ecx
// 00978908  51                   push ecx
// 00978909  b8106e7100           mov eax, 0x716e10
// 0097890e  50                   push eax
// 0097890f  56                   push esi
// 00978910  ba40597100           mov edx, 0x715940
// 00978915  52                   push edx
// 00978916  6884b09b00           push 0x9bb084
// 0097891b  6818f59d00           push 0x9df518
// 00978920  b95056b900           mov ecx, 0xb95650
// 00978925  e806ded9ff           call 0x716730
// 0097892a  68907c9800           push 0x987c90
// 0097892f  e8f5bfe7ff           call 0x7f4929
// 00978934  83c404               add esp, 4
// 00978937  5e                   pop esi
// 00978938  c3                   ret 

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

static Desc desc("CurrentAngle", "Data", &Owner::m0, &Owner::m1, 9, 0);
