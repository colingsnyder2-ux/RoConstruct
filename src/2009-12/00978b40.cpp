// from server: 100% by nuck16
// roc 2009-12 00978b40  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978b40
//
// 00978b40  6a00                 push 0
// 00978b42  6a0f                 push 0xf
// 00978b44  6854010000           push 0x154
// 00978b49  68dc1f9d00           push 0x9d1fdc
// 00978b4e  681cf99d00           push 0x9df91c
// 00978b53  b9c058b900           mov ecx, 0xb958c0
// 00978b58  e84337daff           call 0x71c2a0
// 00978b5d  68007f9800           push 0x987f00
// 00978b62  e8c2bde7ff           call 0x7f4929
// 00978b67  59                   pop ecx
// 00978b68  c3                   ret 

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

static Desc desc("CelestialBodiesShown", "Appearance", 340, 15, 0);
