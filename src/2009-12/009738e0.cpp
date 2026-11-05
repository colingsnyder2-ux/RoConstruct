// from server: 100% by nuck16
// roc 2009-12 009738e0  unit: seg_00970000  size: 57 bytes
//
// 009738e0  56                   push esi
// 009738e1  33f6                 xor esi, esi
// 009738e3  56                   push esi
// 009738e4  6a09                 push 9
// 009738e6  33c9                 xor ecx, ecx
// 009738e8  51                   push ecx
// 009738e9  b820416900           mov eax, 0x694120
// 009738ee  50                   push eax
// 009738ef  56                   push esi
// 009738f0  baf0236900           mov edx, 0x6923f0
// 009738f5  52                   push edx
// 009738f6  68dc1f9d00           push 0x9d1fdc
// 009738fb  68e81f9d00           push 0x9d1fe8
// 00973900  b9d813b900           mov ecx, 0xb913d8
// 00973905  e866ffd1ff           call 0x693870
// 0097390a  6880519800           push 0x985180
// 0097390f  e81510e8ff           call 0x7f4929
// 00973914  83c404               add esp, 4
// 00973917  5e                   pop esi
// 00973918  c3                   ret 

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

static Desc desc("GripPos", "Appearance", &Owner::m0, &Owner::m1, 9, 0);
