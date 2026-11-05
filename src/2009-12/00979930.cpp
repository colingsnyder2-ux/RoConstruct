// from server: 100% by nuck16
// roc 2009-12 00979930  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979930
//
// 00979930  6a00                 push 0
// 00979932  6a0f                 push 0xf
// 00979934  685c010000           push 0x15c
// 00979939  68141c9e00           push 0x9e1c14
// 0097993e  68d81c9e00           push 0x9e1cd8
// 00979943  b9b865b900           mov ecx, 0xb965b8
// 00979948  e873f3dbff           call 0x738cc0
// 0097994d  6870879800           push 0x988770
// 00979952  e8d2afe7ff           call 0x7f4929
// 00979957  59                   pop ecx
// 00979958  c3                   ret 

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

static Desc desc("maxForce", "Goals", 348, 15, 0);
