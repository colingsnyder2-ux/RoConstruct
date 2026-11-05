// from server: 100% by nuck16
// roc 2009-12 00978aa0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978aa0
//
// 00978aa0  6a00                 push 0
// 00978aa2  6a0f                 push 0xf
// 00978aa4  6814010000           push 0x114
// 00978aa9  68dc1f9d00           push 0x9d1fdc
// 00978aae  68f8f89d00           push 0x9df8f8
// 00978ab3  b9ac59b900           mov ecx, 0xb959ac
// 00978ab8  e86336daff           call 0x71c120
// 00978abd  68807e9800           push 0x987e80
// 00978ac2  e862bee7ff           call 0x7f4929
// 00978ac7  59                   pop ecx
// 00978ac8  c3                   ret 

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

static Desc desc("SkyboxFt", "Appearance", 276, 15, 0);
