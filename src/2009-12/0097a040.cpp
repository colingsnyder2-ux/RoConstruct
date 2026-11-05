// from server: 100% by nuck16
// roc 2009-12 0097a040  unit: seg_00970000  size: 57 bytes
//
// 0097a040  56                   push esi
// 0097a041  33f6                 xor esi, esi
// 0097a043  56                   push esi
// 0097a044  6a0f                 push 0xf
// 0097a046  33c9                 xor ecx, ecx
// 0097a048  51                   push ecx
// 0097a049  b8803f7400           mov eax, 0x743f80
// 0097a04e  50                   push eax
// 0097a04f  56                   push esi
// 0097a050  ba60725700           mov edx, 0x577260
// 0097a055  52                   push edx
// 0097a056  6884b09b00           push 0x9bb084
// 0097a05b  685c309e00           push 0x9e305c
// 0097a060  b9446db900           mov ecx, 0xb96d44
// 0097a065  e8b691dcff           call 0x743220
// 0097a06a  68908d9800           push 0x988d90
// 0097a06f  e8b5a8e7ff           call 0x7f4929
// 0097a074  83c404               add esp, 4
// 0097a077  5e                   pop esi
// 0097a078  c3                   ret 

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

static Desc desc("Hole", "Data", &Owner::m0, &Owner::m1, 15, 0);
