// from server: 100% by nuck16
// roc 2009-12 00978700  unit: seg_00970000  size: 57 bytes
//
// 00978700  56                   push esi
// 00978701  33f6                 xor esi, esi
// 00978703  56                   push esi
// 00978704  6a0f                 push 0xf
// 00978706  33c9                 xor ecx, ecx
// 00978708  51                   push ecx
// 00978709  b8306c7100           mov eax, 0x716c30
// 0097870e  50                   push eax
// 0097870f  56                   push esi
// 00978710  bab0577100           mov edx, 0x7157b0
// 00978715  52                   push edx
// 00978716  6884b09b00           push 0x9bb084
// 0097871b  68dcf49d00           push 0x9df4dc
// 00978720  b99c57b900           mov ecx, 0xb9579c
// 00978725  e886ddd9ff           call 0x7164b0
// 0097872a  68b07c9800           push 0x987cb0
// 0097872f  e8f5c1e7ff           call 0x7f4929
// 00978734  83c404               add esp, 4
// 00978737  5e                   pop esi
// 00978738  c3                   ret 

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

static Desc desc("C1", "Data", &Owner::m0, &Owner::m1, 15, 0);
