// from server: 100% by nuck16
// roc 2009-12 00973470  unit: seg_00970000  size: 58 bytes
//
// 00973470  56                   push esi
// 00973471  6a01                 push 1
// 00973473  6a0f                 push 0xf
// 00973475  33c9                 xor ecx, ecx
// 00973477  51                   push ecx
// 00973478  b800226800           mov eax, 0x682200
// 0097347d  50                   push eax
// 0097347e  33f6                 xor esi, esi
// 00973480  56                   push esi
// 00973481  bad0df4600           mov edx, 0x46dfd0
// 00973486  52                   push edx
// 00973487  6884b09b00           push 0x9bb084
// 0097348c  68e4069d00           push 0x9d06e4
// 00973491  b9ac0eb900           mov ecx, 0xb90eac
// 00973496  e855e2d0ff           call 0x6816f0
// 0097349b  68404e9800           push 0x984e40
// 009734a0  e88414e8ff           call 0x7f4929
// 009734a5  83c404               add esp, 4
// 009734a8  5e                   pop esi
// 009734a9  c3                   ret 

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

static Desc desc("Source", "Data", &Owner::m0, &Owner::m1, 15, 1);
