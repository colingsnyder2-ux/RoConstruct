// from server: 100% by nuck16
// roc 2009-12 009734b0  unit: seg_00970000  size: 57 bytes
//
// 009734b0  56                   push esi
// 009734b1  33f6                 xor esi, esi
// 009734b3  56                   push esi
// 009734b4  6a0f                 push 0xf
// 009734b6  33c9                 xor ecx, ecx
// 009734b8  51                   push ecx
// 009734b9  b820236800           mov eax, 0x682320
// 009734be  50                   push eax
// 009734bf  56                   push esi
// 009734c0  ba20d14600           mov edx, 0x46d120
// 009734c5  52                   push edx
// 009734c6  6884b09b00           push 0x9bb084
// 009734cb  68ec069d00           push 0x9d06ec
// 009734d0  b98c0eb900           mov ecx, 0xb90e8c
// 009734d5  e8c6e2d0ff           call 0x6817a0
// 009734da  68204e9800           push 0x984e20
// 009734df  e84514e8ff           call 0x7f4929
// 009734e4  83c404               add esp, 4
// 009734e7  5e                   pop esi
// 009734e8  c3                   ret 

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

static Desc desc("LinkedSource", "Data", &Owner::m0, &Owner::m1, 15, 0);
