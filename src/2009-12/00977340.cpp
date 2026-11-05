// from server: 100% by nuck16
// roc 2009-12 00977340  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977340
//
// 00977340  6a0f                 push 0xf
// 00977342  6870d37100           push 0x71d370
// 00977347  6800d27100           push 0x71d200
// 0097734c  6894c49d00           push 0x9dc494
// 00977351  6884c59d00           push 0x9dc584
// 00977356  b96846b900           mov ecx, 0xb94668
// 0097735b  e8e0c1d7ff           call 0x6f3540
// 00977360  68806f9800           push 0x986f80
// 00977365  e8bfd5e7ff           call 0x7f4929
// 0097736a  59                   pop ecx
// 0097736b  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};

extern "C" void func_0071d200();
extern "C" void func_0071d370();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (*)(), int);
    ~Desc();
};

static Desc desc("FrontSurfaceInput", "Surface Inputs", func_0071d200, func_0071d370, 15);
