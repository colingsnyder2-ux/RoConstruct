// from server: 100% by nuck16
// roc 2009-12 00977250  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977250
//
// 00977250  6a0f                 push 0xf
// 00977252  6820d37100           push 0x71d320
// 00977257  68e0d17100           push 0x71d1e0
// 0097725c  6830a79b00           push 0x9ba730
// 00977261  6838c59d00           push 0x9dc538
// 00977266  b90846b900           mov ecx, 0xb94608
// 0097726b  e860c0d7ff           call 0x6f32d0
// 00977270  68206f9800           push 0x986f20
// 00977275  e8afd6e7ff           call 0x7f4929
// 0097727a  59                   pop ecx
// 0097727b  c3                   ret 

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

static Desc desc("RightSurface", "Surface", func_0071d1e0, func_0071d320, 15);
