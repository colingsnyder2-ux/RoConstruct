// from server: 100% by nuck16
// roc 2009-12 009771f0  unit: seg_00970000  size: 46 bytes
//
// 009771f0  6a00                 push 0
// 009771f2  6a0f                 push 0xf
// 009771f4  68e0d37100           push 0x71d3e0
// 009771f9  6860d27100           push 0x71d260
// 009771fe  6894c49d00           push 0x9dc494
// 00977203  6820c59d00           push 0x9dc520
// 00977208  b98044b900           mov ecx, 0xb94480
// 0097720d  e8deb5d7ff           call 0x6f27f0
// 00977212  68606e9800           push 0x986e60
// 00977217  e80dd7e7ff           call 0x7f4929
// 0097721c  59                   pop ecx
// 0097721d  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};

extern "C" void func_0071d260();
extern "C" void func_0071d3e0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (*)(), int, int);
    ~Desc();
};

static Desc desc("LeftParamA", "Surface Inputs", func_0071d260, func_0071d3e0, 15, 0);
