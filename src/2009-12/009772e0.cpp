// from server: 100% by nuck16
// roc 2009-12 009772e0  unit: seg_00970000  size: 46 bytes
//
// 009772e0  6a00                 push 0
// 009772e2  6a0f                 push 0xf
// 009772e4  6860d47100           push 0x71d460
// 009772e9  68c0d27100           push 0x71d2c0
// 009772ee  6894c49d00           push 0x9dc494
// 009772f3  6868c59d00           push 0x9dc568
// 009772f8  b9f442b900           mov ecx, 0xb942f4
// 009772fd  e89eb5d7ff           call 0x6f28a0
// 00977302  68c06e9800           push 0x986ec0
// 00977307  e81dd6e7ff           call 0x7f4929
// 0097730c  59                   pop ecx
// 0097730d  c3                   ret 

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

static Desc desc("RightParamB", "Surface Inputs", func_0071d2c0, func_0071d460, 15, 0);
