// from server: 100% by nuck16
// roc 2009-12 00977040  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977040
//
// 00977040  6a0f                 push 0xf
// 00977042  6870d37100           push 0x71d370
// 00977047  6800d27100           push 0x71d200
// 0097704c  6894c49d00           push 0x9dc494
// 00977051  6884c49d00           push 0x9dc484
// 00977056  b91443b900           mov ecx, 0xb94314
// 0097705b  e8f0bdd7ff           call 0x6f2e50
// 00977060  68806d9800           push 0x986d80
// 00977065  e8bfd8e7ff           call 0x7f4929
// 0097706a  59                   pop ecx
// 0097706b  c3                   ret 

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

static Desc desc("TopSurfaceInput", "Surface Inputs", func_0071d200, func_0071d370, 15);
