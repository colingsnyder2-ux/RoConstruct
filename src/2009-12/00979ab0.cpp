// from server: 100% by nuck16
// roc 2009-12 00979ab0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979ab0
//
// 00979ab0  6a00                 push 0
// 00979ab2  6a0f                 push 0xf
// 00979ab4  6858010000           push 0x158
// 00979ab9  68141c9e00           push 0x9e1c14
// 00979abe  681c1d9e00           push 0x9e1d1c
// 00979ac3  b99865b900           mov ecx, 0xb96598
// 00979ac8  e833f5dbff           call 0x739000
// 00979acd  6850889800           push 0x988850
// 00979ad2  e852aee7ff           call 0x7f4929
// 00979ad7  59                   pop ecx
// 00979ad8  c3                   ret 

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
