// from server: 100% by nuck16
// roc 2009-12 009773d0  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009773d0
//
// 009773d0  6a0f                 push 0xf
// 009773d2  6820d37100           push 0x71d320
// 009773d7  68e0d17100           push 0x71d1e0
// 009773dc  6830a79b00           push 0x9ba730
// 009773e1  68b0c59d00           push 0x9dc5b0
// 009773e6  b9d042b900           mov ecx, 0xb942d0
// 009773eb  e800c2d7ff           call 0x6f35f0
// 009773f0  6820709800           push 0x987020
// 009773f5  e82fd5e7ff           call 0x7f4929
// 009773fa  59                   pop ecx
// 009773fb  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};

extern "C" void func_0071d1e0();
extern "C" void func_0071d320();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (*)(), int);
    ~Desc();
};

static Desc desc("BackSurface", "Surface", func_0071d1e0, func_0071d320, 15);
