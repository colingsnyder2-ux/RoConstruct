// from server: 100% by nuck16
// roc 2009-12 00979870  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979870
//
// 00979870  6a00                 push 0
// 00979872  6a0f                 push 0xf
// 00979874  686c010000           push 0x16c
// 00979879  68141c9e00           push 0x9e1c14
// 0097987e  68a0b19b00           push 0x9bb1a0
// 00979883  b97862b900           mov ecx, 0xb96278
// 00979888  e893f2dbff           call 0x738b20
// 0097988d  6810879800           push 0x988710
// 00979892  e892b0e7ff           call 0x7f4929
// 00979897  59                   pop ecx
// 00979898  c3                   ret 

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

static Desc desc("position", "Goals", 364, 15, 0);
