// from server: 100% by nuck16
// roc 2009-12 00977310  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977310
//
// 00977310  6a0f                 push 0xf
// 00977312  6820d37100           push 0x71d320
// 00977317  68e0d17100           push 0x71d1e0
// 0097731c  6830a79b00           push 0x9ba730
// 00977321  6874c59d00           push 0x9dc574
// 00977326  b99043b900           mov ecx, 0xb94390
// 0097732b  e860c1d7ff           call 0x6f3490
// 00977330  68a06f9800           push 0x986fa0
// 00977335  e8efd5e7ff           call 0x7f4929
// 0097733a  59                   pop ecx
// 0097733b  c3                   ret 

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

static Desc desc("FrontSurface", "Surface", func_0071d1e0, func_0071d320, 15);
