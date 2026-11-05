// from server: 100% by nuck16
// roc 2009-12 009770a0  unit: seg_00970000  size: 46 bytes
//
// 009770a0  6a00                 push 0
// 009770a2  6a0f                 push 0xf
// 009770a4  6860d47100           push 0x71d460
// 009770a9  68c0d27100           push 0x71d2c0
// 009770ae  6894c49d00           push 0x9dc494
// 009770b3  68b0c49d00           push 0x9dc4b0
// 009770b8  b9bc44b900           mov ecx, 0xb944bc
// 009770bd  e8ceb5d7ff           call 0x6f2690
// 009770c2  6840709800           push 0x987040
// 009770c7  e85dd8e7ff           call 0x7f4929
// 009770cc  59                   pop ecx
// 009770cd  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};

extern "C" void func_0071d2c0();
extern "C" void func_0071d460();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (*)(), int, int);
    ~Desc();
};

static Desc desc("TopParamB", "Surface Inputs", func_0071d2c0, func_0071d460, 15, 0);
