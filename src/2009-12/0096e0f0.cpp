// from server: 100% by nuck16
// roc 2009-12 0096e0f0  unit: seg_00960000  size: 45 bytes
//
// 0096e0f0  33c9                 xor ecx, ecx
// 0096e0f2  51                   push ecx
// 0096e0f3  6a0f                 push 0xf
// 0096e0f5  51                   push ecx
// 0096e0f6  51                   push ecx
// 0096e0f7  b850c66200           mov eax, 0x62c650
// 0096e0fc  50                   push eax
// 0096e0fd  6864b79a00           push 0x9ab764
// 0096e102  687cb99c00           push 0x9cb97c
// 0096e107  b99c4cb800           mov ecx, 0xb84c9c
// 0096e10c  e80f13ccff           call 0x62f420
// 0096e111  6820119800           push 0x981120
// 0096e116  e80e68e8ff           call 0x7f4929
// 0096e11b  59                   pop ecx
// 0096e11c  c3                   ret 

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

static Desc desc("Resolution", "Profile", &Owner::m0, 0, 15, 0);
