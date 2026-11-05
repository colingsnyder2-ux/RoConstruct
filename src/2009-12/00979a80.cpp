// from server: 100% by nuck16
// roc 2009-12 00979a80  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979a80
//
// 00979a80  6a00                 push 0
// 00979a82  6a0f                 push 0xf
// 00979a84  6858010000           push 0x158
// 00979a89  68141c9e00           push 0x9e1c14
// 00979a8e  681c1d9e00           push 0x9e1d1c
// 00979a93  b95862b900           mov ecx, 0xb96258
// 00979a98  e893f4dbff           call 0x738f30
// 00979a9d  6810889800           push 0x988810
// 00979aa2  e882aee7ff           call 0x7f4929
// 00979aa7  59                   pop ecx
// 00979aa8  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};


struct Desc
{
    Desc(const char *, const char *, int, int, int);
    ~Desc();
};

static Desc desc("force", "Goals", 344, 15, 0);
