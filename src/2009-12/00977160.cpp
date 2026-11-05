// from server: 100% by nuck16
// roc 2009-12 00977160  unit: seg_00970000  size: 46 bytes
//
// 00977160  6a00                 push 0
// 00977162  6a0f                 push 0xf
// 00977164  6860d47100           push 0x71d460
// 00977169  68c0d27100           push 0x71d2c0
// 0097716e  6894c49d00           push 0x9dc494
// 00977173  68f0c49d00           push 0x9dc4f0
// 00977178  b92c46b900           mov ecx, 0xb9462c
// 0097717d  e8beb5d7ff           call 0x6f2740
// 00977182  68c06d9800           push 0x986dc0
// 00977187  e89dd7e7ff           call 0x7f4929
// 0097718c  59                   pop ecx
// 0097718d  c3                   ret 

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

static Desc desc("BottomParamB", "Surface Inputs", func_0071d2c0, func_0071d460, 15, 0);
