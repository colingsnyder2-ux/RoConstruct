// from server: 100% by nuck16
// roc 2009-12 0097a140  unit: seg_00970000  size: 57 bytes
//
// 0097a140  56                   push esi
// 0097a141  33f6                 xor esi, esi
// 0097a143  56                   push esi
// 0097a144  6a0f                 push 0xf
// 0097a146  33c9                 xor ecx, ecx
// 0097a148  51                   push ecx
// 0097a149  b830377400           mov eax, 0x743730
// 0097a14e  50                   push eax
// 0097a14f  56                   push esi
// 0097a150  ba10478100           mov edx, 0x814710
// 0097a155  52                   push edx
// 0097a156  6884b09b00           push 0x9bb084
// 0097a15b  68fc309e00           push 0x9e30fc
// 0097a160  b9b46db900           mov ecx, 0xb96db4
// 0097a165  e84697dcff           call 0x7438b0
// 0097a16a  68308e9800           push 0x988e30
// 0097a16f  e8b5a7e7ff           call 0x7f4929
// 0097a174  83c404               add esp, 4
// 0097a177  5e                   pop esi
// 0097a178  c3                   ret 

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

static Desc desc("FaceId", "Data", &Owner::m0, &Owner::m1, 15, 0);
