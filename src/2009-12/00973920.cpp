// from server: 100% by nuck16
// roc 2009-12 00973920  unit: seg_00970000  size: 57 bytes
//
// 00973920  56                   push esi
// 00973921  33f6                 xor esi, esi
// 00973923  56                   push esi
// 00973924  6a09                 push 9
// 00973926  33c9                 xor ecx, ecx
// 00973928  51                   push ecx
// 00973929  b870416900           mov eax, 0x694170
// 0097392e  50                   push eax
// 0097392f  56                   push esi
// 00973930  ba20246900           mov edx, 0x692420
// 00973935  52                   push edx
// 00973936  68dc1f9d00           push 0x9d1fdc
// 0097393b  68f01f9d00           push 0x9d1ff0
// 00973940  b97012b900           mov ecx, 0xb91270
// 00973945  e826ffd1ff           call 0x693870
// 0097394a  6860519800           push 0x985160
// 0097394f  e8d50fe8ff           call 0x7f4929
// 00973954  83c404               add esp, 4
// 00973957  5e                   pop esi
// 00973958  c3                   ret 

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

static Desc desc("GripForward", "Appearance", &Owner::m0, &Owner::m1, 9, 0);
