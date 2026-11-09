// from server: 100% by nuck16
// roc 2009-12 00973960  unit: seg_00970000  size: 57 bytes
//
// 00973960  56                   push esi
// 00973961  33f6                 xor esi, esi
// 00973963  56                   push esi
// 00973964  6a09                 push 9
// 00973966  33c9                 xor ecx, ecx
// 00973968  51                   push ecx
// 00973969  b840436900           mov eax, 0x694340
// 0097396e  50                   push eax
// 0097396f  56                   push esi
// 00973970  ba80246900           mov edx, 0x692480
// 00973975  52                   push edx
// 00973976  68dc1f9d00           push 0x9d1fdc
// 0097397b  68fc1f9d00           push 0x9d1ffc
// 00973980  b95813b900           mov ecx, 0xb91358
// 00973985  e8e6fed1ff           call 0x693870
// 0097398a  6820519800           push 0x985120
// 0097398f  e8950fe8ff           call 0x7f4929
// 00973994  83c404               add esp, 4
// 00973997  5e                   pop esi
// 00973998  c3                   ret 

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

static Desc desc("GripUp", "Appearance", &Owner::m0, &Owner::m1, 9, 0);
