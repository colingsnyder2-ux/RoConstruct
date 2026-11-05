// from server: 100% by nuck16
// roc 2009-12 0096dfd0  unit: seg_00960000  size: 45 bytes
//
// 0096dfd0  33c9                 xor ecx, ecx
// 0096dfd2  51                   push ecx
// 0096dfd3  6a0f                 push 0xf
// 0096dfd5  51                   push ecx
// 0096dfd6  51                   push ecx
// 0096dfd7  b820c06200           mov eax, 0x62c020
// 0096dfdc  50                   push eax
// 0096dfdd  6864b79a00           push 0x9ab764
// 0096dfe2  683cb99c00           push 0x9cb93c
// 0096dfe7  b9b04eb800           mov ecx, 0xb84eb0
// 0096dfec  e82f14ccff           call 0x62f420
// 0096dff1  6860109800           push 0x981060
// 0096dff6  e82e69e8ff           call 0x7f4929
// 0096dffb  59                   pop ecx
// 0096dffc  c3                   ret 

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

static Desc desc("SystemProductName", "Profile", &Owner::m0, 0, 15, 0);
