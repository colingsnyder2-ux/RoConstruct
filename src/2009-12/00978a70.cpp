// from server: 100% by nuck16
// roc 2009-12 00978a70  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978a70
//
// 00978a70  6a00                 push 0
// 00978a72  6a0f                 push 0xf
// 00978a74  68f4000000           push 0xf4
// 00978a79  68dc1f9d00           push 0x9d1fdc
// 00978a7e  68ecf89d00           push 0x9df8ec
// 00978a83  b90059b900           mov ecx, 0xb95900
// 00978a88  e89336daff           call 0x71c120
// 00978a8d  68607e9800           push 0x987e60
// 00978a92  e892bee7ff           call 0x7f4929
// 00978a97  59                   pop ecx
// 00978a98  c3                   ret 

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

static Desc desc("SkyboxBk", "Appearance", 244, 15, 0);
