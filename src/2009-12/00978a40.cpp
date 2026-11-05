// from server: 100% by nuck16
// roc 2009-12 00978a40  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978a40
//
// 00978a40  6a00                 push 0
// 00978a42  6a0f                 push 0xf
// 00978a44  68d4000000           push 0xd4
// 00978a49  68dc1f9d00           push 0x9d1fdc
// 00978a4e  68e0f89d00           push 0x9df8e0
// 00978a53  b98059b900           mov ecx, 0xb95980
// 00978a58  e8c336daff           call 0x71c120
// 00978a5d  68407e9800           push 0x987e40
// 00978a62  e8c2bee7ff           call 0x7f4929
// 00978a67  59                   pop ecx
// 00978a68  c3                   ret 

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

static Desc desc("SkyboxRt", "Appearance", 212, 15, 0);
