// from server: 100% by nuck16
// roc 2009-12 0097bb40  unit: seg_00970000  size: 57 bytes
//
// 0097bb40  56                   push esi
// 0097bb41  33f6                 xor esi, esi
// 0097bb43  56                   push esi
// 0097bb44  6a0f                 push 0xf
// 0097bb46  33c9                 xor ecx, ecx
// 0097bb48  51                   push ecx
// 0097bb49  b840fb7600           mov eax, 0x76fb40
// 0097bb4e  50                   push eax
// 0097bb4f  56                   push esi
// 0097bb50  ba60ce7600           mov edx, 0x76ce60
// 0097bb55  52                   push edx
// 0097bb56  6884b09b00           push 0x9bb084
// 0097bb5b  6840e09b00           push 0x9be040
// 0097bb60  b95883b900           mov ecx, 0xb98358
// 0097bb65  e8162bdfff           call 0x76e680
// 0097bb6a  68909f9800           push 0x989f90
// 0097bb6f  e8b58de7ff           call 0x7f4929
// 0097bb74  83c404               add esp, 4
// 0097bb77  5e                   pop esi
// 0097bb78  c3                   ret 

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

static Desc desc("Size", "Data", &Owner::m0, &Owner::m1, 15, 0);
