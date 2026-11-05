// from server: 100% by nuck16
// roc 2009-12 00977220  unit: seg_00970000  size: 46 bytes
//
// 00977220  6a00                 push 0
// 00977222  6a0f                 push 0xf
// 00977224  6860d47100           push 0x71d460
// 00977229  68c0d27100           push 0x71d2c0
// 0097722e  6894c49d00           push 0x9dc494
// 00977233  682cc59d00           push 0x9dc52c
// 00977238  b92045b900           mov ecx, 0xb94520
// 0097723d  e8aeb5d7ff           call 0x6f27f0
// 00977242  68406e9800           push 0x986e40
// 00977247  e8ddd6e7ff           call 0x7f4929
// 0097724c  59                   pop ecx
// 0097724d  c3                   ret 

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

static Desc desc("LeftParamB", "Surface Inputs", func_0071d2c0, func_0071d460, 15, 0);
