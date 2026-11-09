// from server: 100% by nuck16
// roc 2009-12 0097a830  unit: seg_00970000  size: 57 bytes
//
// 0097a830  56                   push esi
// 0097a831  33f6                 xor esi, esi
// 0097a833  56                   push esi
// 0097a834  6a0f                 push 0xf
// 0097a836  33c9                 xor ecx, ecx
// 0097a838  51                   push ecx
// 0097a839  b8602f7500           mov eax, 0x752f60
// 0097a83e  50                   push eax
// 0097a83f  56                   push esi
// 0097a840  ba70725700           mov edx, 0x577270
// 0097a845  52                   push edx
// 0097a846  6884b09b00           push 0x9bb084
// 0097a84b  681c479e00           push 0x9e471c
// 0097a850  b9f072b900           mov ecx, 0xb972f0
// 0097a855  e83687ddff           call 0x752f90
// 0097a85a  6830939800           push 0x989330
// 0097a85f  e8c5a0e7ff           call 0x7f4929
// 0097a864  83c404               add esp, 4
// 0097a867  5e                   pop esi
// 0097a868  c3                   ret 

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

static Desc desc("TargetSurface", "Data", &Owner::m0, &Owner::m1, 15, 0);
