// from server: 100% by nuck16
// roc 2009-12 00979ba0  unit: seg_00970000  size: 57 bytes
//
// 00979ba0  56                   push esi
// 00979ba1  33f6                 xor esi, esi
// 00979ba3  56                   push esi
// 00979ba4  6a0f                 push 0xf
// 00979ba6  33c9                 xor ecx, ecx
// 00979ba8  51                   push ecx
// 00979ba9  b8b0d37300           mov eax, 0x73d3b0
// 00979bae  50                   push eax
// 00979baf  56                   push esi
// 00979bb0  baf0b67300           mov edx, 0x73b6f0
// 00979bb5  52                   push edx
// 00979bb6  6884b09b00           push 0x9bb084
// 00979bbb  6898229e00           push 0x9e2298
// 00979bc0  b9c067b900           mov ecx, 0xb967c0
// 00979bc5  e8c634dcff           call 0x73d090
// 00979bca  68408b9800           push 0x988b40
// 00979bcf  e855ade7ff           call 0x7f4929
// 00979bd4  83c404               add esp, 4
// 00979bd7  5e                   pop esi
// 00979bd8  c3                   ret 

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

static Desc desc("StudsOffset", "Data", &Owner::m0, &Owner::m1, 15, 0);
