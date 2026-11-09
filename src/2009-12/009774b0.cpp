// from server: 100% by nuck16
// roc 2009-12 009774b0  unit: seg_00970000  size: 57 bytes
//
// 009774b0  56                   push esi
// 009774b1  33f6                 xor esi, esi
// 009774b3  56                   push esi
// 009774b4  6a0f                 push 0xf
// 009774b6  33c9                 xor ecx, ecx
// 009774b8  51                   push ecx
// 009774b9  b870416f00           mov eax, 0x6f4170
// 009774be  50                   push eax
// 009774bf  56                   push esi
// 009774c0  ba10478100           mov edx, 0x814710
// 009774c5  52                   push edx
// 009774c6  6884b09b00           push 0x9bb084
// 009774cb  68f0c69d00           push 0x9dc6f0
// 009774d0  b9bc46b900           mov ecx, 0xb946bc
// 009774d5  e8c6ccd7ff           call 0x6f41a0
// 009774da  6880709800           push 0x987080
// 009774df  e845d4e7ff           call 0x7f4929
// 009774e4  83c404               add esp, 4
// 009774e7  5e                   pop esi
// 009774e8  c3                   ret 

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

static Desc desc("Face", "Data", &Owner::m0, &Owner::m1, 15, 0);
