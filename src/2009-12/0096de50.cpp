// from server: 100% by nuck16
// roc 2009-12 0096de50  unit: seg_00960000  size: 45 bytes
//
// 0096de50  33c9                 xor ecx, ecx
// 0096de52  51                   push ecx
// 0096de53  6a0f                 push 0xf
// 0096de55  51                   push ecx
// 0096de56  51                   push ecx
// 0096de57  b8e0bc6200           mov eax, 0x62bce0
// 0096de5c  50                   push eax
// 0096de5d  6864b79a00           push 0x9ab764
// 0096de62  68c8b89c00           push 0x9cb8c8
// 0096de67  b9484eb800           mov ecx, 0xb84e48
// 0096de6c  e8af15ccff           call 0x62f420
// 0096de71  6860159800           push 0x981560
// 0096de76  e8ae6ae8ff           call 0x7f4929
// 0096de7b  59                   pop ecx
// 0096de7c  c3                   ret 

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

static Desc desc("RobloxVersion", "Profile", &Owner::m0, 0, 15, 0);
