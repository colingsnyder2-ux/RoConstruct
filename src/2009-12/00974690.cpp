// from server: 100% by nuck16
// roc 2009-12 00974690  unit: seg_00970000  size: 57 bytes
//
// 00974690  56                   push esi
// 00974691  33f6                 xor esi, esi
// 00974693  56                   push esi
// 00974694  6a0f                 push 0xf
// 00974696  33c9                 xor ecx, ecx
// 00974698  51                   push ecx
// 00974699  b890bb6b00           mov eax, 0x6bbb90
// 0097469e  50                   push eax
// 0097469f  56                   push esi
// 009746a0  baa0294b00           mov edx, 0x4b29a0
// 009746a5  52                   push edx
// 009746a6  68dc1f9d00           push 0x9d1fdc
// 009746ab  68c4699d00           push 0x9d69c4
// 009746b0  b9fc20b900           mov ecx, 0xb920fc
// 009746b5  e84672d4ff           call 0x6bb900
// 009746ba  6810599800           push 0x985910
// 009746bf  e86502e8ff           call 0x7f4929
// 009746c4  83c404               add esp, 4
// 009746c7  5e                   pop esi
// 009746c8  c3                   ret 

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

static Desc desc("Shiny", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
