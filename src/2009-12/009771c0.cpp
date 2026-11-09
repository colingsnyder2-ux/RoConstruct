// from server: 100% by nuck16
// roc 2009-12 009771c0  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009771c0
//
// 009771c0  6a0f                 push 0xf
// 009771c2  6870d37100           push 0x71d370
// 009771c7  6800d27100           push 0x71d200
// 009771cc  6894c49d00           push 0x9dc494
// 009771d1  680cc59d00           push 0x9dc50c
// 009771d6  b98c46b900           mov ecx, 0xb9468c
// 009771db  e810c0d7ff           call 0x6f31f0
// 009771e0  68806e9800           push 0x986e80
// 009771e5  e83fd7e7ff           call 0x7f4929
// 009771ea  59                   pop ecx
// 009771eb  c3                   ret 

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

static Desc desc("LeftSurfaceInput", "Surface Inputs", func_0071d200, func_0071d370, 15);
