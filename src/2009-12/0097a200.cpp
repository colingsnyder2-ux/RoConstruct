// from server: 100% by nuck16
// roc 2009-12 0097a200  unit: seg_00970000  size: 57 bytes
//
// 0097a200  56                   push esi
// 0097a201  33f6                 xor esi, esi
// 0097a203  56                   push esi
// 0097a204  6a0f                 push 0xf
// 0097a206  33c9                 xor ecx, ecx
// 0097a208  51                   push ecx
// 0097a209  b8c0377400           mov eax, 0x7437c0
// 0097a20e  50                   push eax
// 0097a20f  56                   push esi
// 0097a210  ba201b7400           mov edx, 0x741b20
// 0097a215  52                   push edx
// 0097a216  6884b09b00           push 0x9bb084
// 0097a21b  68f42d9e00           push 0x9e2df4
// 0097a220  b98c6db900           mov ecx, 0xb96d8c
// 0097a225  e8069adcff           call 0x743c30
// 0097a22a  68d08d9800           push 0x988dd0
// 0097a22f  e8f5a6e7ff           call 0x7f4929
// 0097a234  83c404               add esp, 4
// 0097a237  5e                   pop esi
// 0097a238  c3                   ret 

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

static Desc desc("InOut", "Data", &Owner::m0, &Owner::m1, 15, 0);
