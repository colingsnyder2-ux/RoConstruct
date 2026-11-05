// from server: 100% by nuck16
// roc 2009-12 00978ad0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978ad0
//
// 00978ad0  6a00                 push 0
// 00978ad2  6a0f                 push 0xf
// 00978ad4  6834010000           push 0x134
// 00978ad9  68dc1f9d00           push 0x9d1fdc
// 00978ade  6804f99d00           push 0x9df904
// 00978ae3  b94059b900           mov ecx, 0xb95940
// 00978ae8  e83336daff           call 0x71c120
// 00978aed  68a07e9800           push 0x987ea0
// 00978af2  e832bee7ff           call 0x7f4929
// 00978af7  59                   pop ecx
// 00978af8  c3                   ret 

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

static Desc desc("SkyboxDn", "Appearance", 308, 15, 0);
