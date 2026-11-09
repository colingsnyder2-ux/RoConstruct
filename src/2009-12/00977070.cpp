// from server: 100% by nuck16
// roc 2009-12 00977070  unit: seg_00970000  size: 46 bytes
//
// 00977070  6a00                 push 0
// 00977072  6a0f                 push 0xf
// 00977074  68e0d37100           push 0x71d3e0
// 00977079  6860d27100           push 0x71d260
// 0097707e  6894c49d00           push 0x9dc494
// 00977083  68a4c49d00           push 0x9dc4a4
// 00977088  b97043b900           mov ecx, 0xb94370
// 0097708d  e8feb5d7ff           call 0x6f2690
// 00977092  6860709800           push 0x987060
// 00977097  e88dd8e7ff           call 0x7f4929
// 0097709c  59                   pop ecx
// 0097709d  c3                   ret 

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

static Desc desc("TopParamA", "Surface Inputs", func_0071d260, func_0071d3e0, 15, 0);
