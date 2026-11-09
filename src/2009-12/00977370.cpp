// from server: 100% by nuck16
// roc 2009-12 00977370  unit: seg_00970000  size: 46 bytes
//
// 00977370  6a00                 push 0
// 00977372  6a0f                 push 0xf
// 00977374  68e0d37100           push 0x71d3e0
// 00977379  6860d27100           push 0x71d260
// 0097737e  6894c49d00           push 0x9dc494
// 00977383  6898c59d00           push 0x9dc598
// 00977388  b91844b900           mov ecx, 0xb94418
// 0097738d  e8beb5d7ff           call 0x6f2950
// 00977392  68606f9800           push 0x986f60
// 00977397  e88dd5e7ff           call 0x7f4929
// 0097739c  59                   pop ecx
// 0097739d  c3                   ret 

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

static Desc desc("FrontParamA", "Surface Inputs", func_0071d260, func_0071d3e0, 15, 0);
