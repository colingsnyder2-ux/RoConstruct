// from server: 100% by nuck16
// roc 2009-12 00977130  unit: seg_00970000  size: 46 bytes
//
// 00977130  6a00                 push 0
// 00977132  6a0f                 push 0xf
// 00977134  68e0d37100           push 0x71d3e0
// 00977139  6860d27100           push 0x71d260
// 0097713e  6894c49d00           push 0x9dc494
// 00977143  68e0c49d00           push 0x9dc4e0
// 00977148  b96445b900           mov ecx, 0xb94564
// 0097714d  e8eeb5d7ff           call 0x6f2740
// 00977152  68e06d9800           push 0x986de0
// 00977157  e8cdd7e7ff           call 0x7f4929
// 0097715c  59                   pop ecx
// 0097715d  c3                   ret 

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

static Desc desc("BottomParamA", "Surface Inputs", func_0071d260, func_0071d3e0, 15, 0);
