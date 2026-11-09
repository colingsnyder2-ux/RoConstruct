// from server: 100% by nuck16
// roc 2009-12 0097ba70  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097ba70
//
// 0097ba70  33c9                 xor ecx, ecx
// 0097ba72  51                   push ecx
// 0097ba73  6a0f                 push 0xf
// 0097ba75  51                   push ecx
// 0097ba76  51                   push ecx
// 0097ba77  b8e0b77600           mov eax, 0x76b7e0
// 0097ba7c  50                   push eax
// 0097ba7d  6884b09b00           push 0x9bb084
// 0097ba82  686c839a00           push 0x9a836c
// 0097ba87  b95880b900           mov ecx, 0xb98058
// 0097ba8c  e8ef03dfff           call 0x76be80
// 0097ba91  68d09a9800           push 0x989ad0
// 0097ba96  e88e8ee7ff           call 0x7f4929
// 0097ba9b  59                   pop ecx
// 0097ba9c  c3                   ret 

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

static Desc desc("Y", "Data", &Owner::m0, 0, 15, 0);
