// from server: 100% by nuck16
// roc 2009-12 009789e0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009789e0
//
// 009789e0  6a00                 push 0
// 009789e2  6a0f                 push 0xf
// 009789e4  6894000000           push 0x94
// 009789e9  68dc1f9d00           push 0x9d1fdc
// 009789ee  68c8f89d00           push 0x9df8c8
// 009789f3  b96059b900           mov ecx, 0xb95960
// 009789f8  e82337daff           call 0x71c120
// 009789fd  68e07e9800           push 0x987ee0
// 00978a02  e822bfe7ff           call 0x7f4929
// 00978a07  59                   pop ecx
// 00978a08  c3                   ret 

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

static Desc desc("SkyboxUp", "Appearance", 148, 15, 0);
