// from server: 100% by nuck16
// roc 2009-12 00977460  unit: seg_00970000  size: 46 bytes
//
// 00977460  6a00                 push 0
// 00977462  6a0f                 push 0xf
// 00977464  6860d47100           push 0x71d460
// 00977469  68c0d27100           push 0x71d2c0
// 0097746e  6894c49d00           push 0x9dc494
// 00977473  68dcc59d00           push 0x9dc5dc
// 00977478  b9c845b900           mov ecx, 0xb945c8
// 0097747d  e87eb5d7ff           call 0x6f2a00
// 00977482  68c06f9800           push 0x986fc0
// 00977487  e89dd4e7ff           call 0x7f4929
// 0097748c  59                   pop ecx
// 0097748d  c3                   ret 

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

static Desc desc("BackParamB", "Surface Inputs", func_0071d2c0, func_0071d460, 15, 0);
