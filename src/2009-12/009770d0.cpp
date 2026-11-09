// from server: 100% by nuck16
// roc 2009-12 009770d0  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009770d0
//
// 009770d0  6a0f                 push 0xf
// 009770d2  6820d37100           push 0x71d320
// 009770d7  68e0d17100           push 0x71d1e0
// 009770dc  6830a79b00           push 0x9ba730
// 009770e1  68bcc49d00           push 0x9dc4bc
// 009770e6  b9b443b900           mov ecx, 0xb943b4
// 009770eb  e8c0bed7ff           call 0x6f2fb0
// 009770f0  68206e9800           push 0x986e20
// 009770f5  e82fd8e7ff           call 0x7f4929
// 009770fa  59                   pop ecx
// 009770fb  c3                   ret 

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

static Desc desc("BottomSurface", "Surface", func_0071d1e0, func_0071d320, 15);
