// from server: 100% by nuck16
// roc 2009-12 0096d080  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d080
//
// 0096d080  6a00                 push 0
// 0096d082  6a0f                 push 0xf
// 0096d084  68c9000000           push 0xc9
// 0096d089  68b8c39b00           push 0x9bc3b8
// 0096d08e  6894c59b00           push 0x9bc594
// 0096d093  b9d400b800           mov ecx, 0xb800d4
// 0096d098  e853c4bbff           call 0x5294f0
// 0096d09d  6870039800           push 0x980370
// 0096d0a2  e88278e8ff           call 0x7f4929
// 0096d0a7  59                   pop ecx
// 0096d0a8  c3                   ret 

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

static Desc desc("ServerLocalScripts", "Network", 201, 15, 0);
