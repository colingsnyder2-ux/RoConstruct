// from server: 100% by nuck16
// roc 2009-12 0097bc40  unit: seg_00970000  size: 57 bytes
//
// 0097bc40  56                   push esi
// 0097bc41  33f6                 xor esi, esi
// 0097bc43  56                   push esi
// 0097bc44  6a0f                 push 0xf
// 0097bc46  33c9                 xor ecx, ecx
// 0097bc48  51                   push ecx
// 0097bc49  b800fc7600           mov eax, 0x76fc00
// 0097bc4e  50                   push eax
// 0097bc4f  56                   push esi
// 0097bc50  ba90ce7600           mov edx, 0x76ce90
// 0097bc55  52                   push edx
// 0097bc56  6884b09b00           push 0x9bb084
// 0097bc5b  6848899e00           push 0x9e8948
// 0097bc60  b93086b900           mov ecx, 0xb98630
// 0097bc65  e8d649dfff           call 0x770640
// 0097bc6a  68d09e9800           push 0x989ed0
// 0097bc6f  e8b58ce7ff           call 0x7f4929
// 0097bc74  83c404               add esp, 4
// 0097bc77  5e                   pop esi
// 0097bc78  c3                   ret 

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

static Desc desc("SizeConstraint", "Data", &Owner::m0, &Owner::m1, 15, 0);
