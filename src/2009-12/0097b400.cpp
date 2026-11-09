// from server: 100% by nuck16
// roc 2009-12 0097b400  unit: seg_00970000  size: 57 bytes
//
// 0097b400  56                   push esi
// 0097b401  33f6                 xor esi, esi
// 0097b403  56                   push esi
// 0097b404  6a0f                 push 0xf
// 0097b406  33c9                 xor ecx, ecx
// 0097b408  51                   push ecx
// 0097b409  b8f0fe7500           mov eax, 0x75fef0
// 0097b40e  50                   push eax
// 0097b40f  56                   push esi
// 0097b410  ba50bf7500           mov edx, 0x75bf50
// 0097b415  52                   push edx
// 0097b416  6884b09b00           push 0x9bb084
// 0097b41b  6890229e00           push 0x9e2290
// 0097b420  b9647ab900           mov ecx, 0xb97a64
// 0097b425  e8d647deff           call 0x75fc00
// 0097b42a  68e0989800           push 0x9898e0
// 0097b42f  e8f594e7ff           call 0x7f4929
// 0097b434  83c404               add esp, 4
// 0097b437  5e                   pop esi
// 0097b438  c3                   ret 

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

static Desc desc("Adornee", "Data", &Owner::m0, &Owner::m1, 15, 0);
