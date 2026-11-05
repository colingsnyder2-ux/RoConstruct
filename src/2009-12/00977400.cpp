// from server: 100% by nuck16
// roc 2009-12 00977400  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977400
//
// 00977400  6a0f                 push 0xf
// 00977402  6870d37100           push 0x71d370
// 00977407  6800d27100           push 0x71d200
// 0097740c  6894c49d00           push 0x9dc494
// 00977411  68bcc59d00           push 0x9dc5bc
// 00977416  b95c44b900           mov ecx, 0xb9445c
// 0097741b  e880c2d7ff           call 0x6f36a0
// 00977420  6800709800           push 0x987000
// 00977425  e8ffd4e7ff           call 0x7f4929
// 0097742a  59                   pop ecx
// 0097742b  c3                   ret 

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

static Desc desc("BackSurfaceInput", "Surface Inputs", func_0071d200, func_0071d370, 15);
