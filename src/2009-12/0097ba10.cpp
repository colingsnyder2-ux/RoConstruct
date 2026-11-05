// from server: 100% by nuck16
// roc 2009-12 0097ba10  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097ba10
//
// 0097ba10  33c9                 xor ecx, ecx
// 0097ba12  51                   push ecx
// 0097ba13  6a0f                 push 0xf
// 0097ba15  51                   push ecx
// 0097ba16  51                   push ecx
// 0097ba17  b800b77600           mov eax, 0x76b700
// 0097ba1c  50                   push eax
// 0097ba1d  6884b09b00           push 0x9bb084
// 0097ba22  681c479e00           push 0x9e471c
// 0097ba27  b90c81b900           mov ecx, 0xb9810c
// 0097ba2c  e84f0cdfff           call 0x76c680
// 0097ba31  68109a9800           push 0x989a10
// 0097ba36  e8ee8ee7ff           call 0x7f4929
// 0097ba3b  59                   pop ecx
// 0097ba3c  c3                   ret 

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

static Desc desc("TargetSurface", "Data", &Owner::m0, 0, 15, 0);
