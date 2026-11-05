// from server: 100% by nuck16
// roc 2009-12 0097b9b0  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b9b0
//
// 0097b9b0  33c9                 xor ecx, ecx
// 0097b9b2  51                   push ecx
// 0097b9b3  6a0f                 push 0xf
// 0097b9b5  51                   push ecx
// 0097b9b6  51                   push ecx
// 0097b9b7  b810b47600           mov eax, 0x76b410
// 0097b9bc  50                   push eax
// 0097b9bd  6884b09b00           push 0x9bb084
// 0097b9c2  6890819e00           push 0x9e8190
// 0097b9c7  b9ac81b900           mov ecx, 0xb981ac
// 0097b9cc  e85f03dfff           call 0x76bd30
// 0097b9d1  68109b9800           push 0x989b10
// 0097b9d6  e84e8fe7ff           call 0x7f4929
// 0097b9db  59                   pop ecx
// 0097b9dc  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("UnitRay", "Data", &Owner::m0, 0, 15, 0);
