// from server: 100% by nuck16
// roc 2009-12 00977010  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977010
//
// 00977010  6a0f                 push 0xf
// 00977012  6820d37100           push 0x71d320
// 00977017  68e0d17100           push 0x71d1e0
// 0097701c  6830a79b00           push 0x9ba730
// 00977021  6878c49d00           push 0x9dc478
// 00977026  b94045b900           mov ecx, 0xb94540
// 0097702b  e890bcd7ff           call 0x6f2cc0
// 00977030  68a06d9800           push 0x986da0
// 00977035  e8efd8e7ff           call 0x7f4929
// 0097703a  59                   pop ecx
// 0097703b  c3                   ret 

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

static Desc desc("TopSurface", "Surface", func_0071d1e0, func_0071d320, 15);
