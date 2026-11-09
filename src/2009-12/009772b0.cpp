// from server: 100% by nuck16
// roc 2009-12 009772b0  unit: seg_00970000  size: 46 bytes
//
// 009772b0  6a00                 push 0
// 009772b2  6a0f                 push 0xf
// 009772b4  68e0d37100           push 0x71d3e0
// 009772b9  6860d27100           push 0x71d260
// 009772be  6894c49d00           push 0x9dc494
// 009772c3  685cc59d00           push 0x9dc55c
// 009772c8  b9a845b900           mov ecx, 0xb945a8
// 009772cd  e8ceb5d7ff           call 0x6f28a0
// 009772d2  68e06e9800           push 0x986ee0
// 009772d7  e84dd6e7ff           call 0x7f4929
// 009772dc  59                   pop ecx
// 009772dd  c3                   ret 

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

static Desc desc("RightParamA", "Surface Inputs", func_0071d260, func_0071d3e0, 15, 0);
