// from server: 100% by nuck16
// roc 2009-12 009773a0  unit: seg_00970000  size: 46 bytes
//
// 009773a0  6a00                 push 0
// 009773a2  6a0f                 push 0xf
// 009773a4  6860d47100           push 0x71d460
// 009773a9  68c0d27100           push 0x71d2c0
// 009773ae  6894c49d00           push 0x9dc494
// 009773b3  68a4c59d00           push 0x9dc5a4
// 009773b8  b9dc44b900           mov ecx, 0xb944dc
// 009773bd  e88eb5d7ff           call 0x6f2950
// 009773c2  68406f9800           push 0x986f40
// 009773c7  e85dd5e7ff           call 0x7f4929
// 009773cc  59                   pop ecx
// 009773cd  c3                   ret 

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

static Desc desc("FrontParamB", "Surface Inputs", func_0071d2c0, func_0071d460, 15, 0);
