// from server: 100% by nuck16
// roc 2009-12 00977430  unit: seg_00970000  size: 46 bytes
//
// 00977430  6a00                 push 0
// 00977432  6a0f                 push 0xf
// 00977434  68e0d37100           push 0x71d3e0
// 00977439  6860d27100           push 0x71d260
// 0097743e  6894c49d00           push 0x9dc494
// 00977443  68d0c59d00           push 0x9dc5d0
// 00977448  b9f443b900           mov ecx, 0xb943f4
// 0097744d  e8aeb5d7ff           call 0x6f2a00
// 00977452  68e06f9800           push 0x986fe0
// 00977457  e8cdd4e7ff           call 0x7f4929
// 0097745c  59                   pop ecx
// 0097745d  c3                   ret 

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

static Desc desc("BackParamA", "Surface Inputs", func_0071d260, func_0071d3e0, 15, 0);
