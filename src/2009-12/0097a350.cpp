// from server: 100% by nuck16
// roc 2009-12 0097a350  unit: seg_00970000  size: 57 bytes
//
// 0097a350  56                   push esi
// 0097a351  33f6                 xor esi, esi
// 0097a353  56                   push esi
// 0097a354  6a0f                 push 0xf
// 0097a356  33c9                 xor ecx, ecx
// 0097a358  51                   push ecx
// 0097a359  b8f08c7400           mov eax, 0x748cf0
// 0097a35e  50                   push eax
// 0097a35f  56                   push esi
// 0097a360  ba90747400           mov edx, 0x747490
// 0097a365  52                   push edx
// 0097a366  6884b09b00           push 0x9bb084
// 0097a36b  6828ca9c00           push 0x9cca28
// 0097a370  b9d070b900           mov ecx, 0xb970d0
// 0097a375  e826ebdcff           call 0x748ea0
// 0097a37a  68b08f9800           push 0x988fb0
// 0097a37f  e8a5a5e7ff           call 0x7f4929
// 0097a384  83c404               add esp, 4
// 0097a387  5e                   pop esi
// 0097a388  c3                   ret 

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

static Desc desc("Faces", "Data", &Owner::m0, &Owner::m1, 15, 0);
