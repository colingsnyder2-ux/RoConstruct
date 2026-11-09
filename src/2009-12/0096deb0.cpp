// from server: 100% by nuck16
// roc 2009-12 0096deb0  unit: seg_00960000  size: 45 bytes
//
// 0096deb0  33c9                 xor ecx, ecx
// 0096deb2  51                   push ecx
// 0096deb3  6a0f                 push 0xf
// 0096deb5  51                   push ecx
// 0096deb6  51                   push ecx
// 0096deb7  b840be6200           mov eax, 0x62be40
// 0096debc  50                   push eax
// 0096debd  6864b79a00           push 0x9ab764
// 0096dec2  68ecb89c00           push 0x9cb8ec
// 0096dec7  b9f84eb800           mov ecx, 0xb84ef8
// 0096decc  e8ef15ccff           call 0x62f4c0
// 0096ded1  6820159800           push 0x981520
// 0096ded6  e84e6ae8ff           call 0x7f4929
// 0096dedb  59                   pop ecx
// 0096dedc  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};


struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("PixelShaderModel", "Profile", &Owner::m0, 0, 15, 0);
