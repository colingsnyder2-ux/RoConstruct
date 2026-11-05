// from server: 100% by nuck16
// roc 2009-12 0096e090  unit: seg_00960000  size: 45 bytes
//
// 0096e090  33c9                 xor ecx, ecx
// 0096e092  51                   push ecx
// 0096e093  6a0f                 push 0xf
// 0096e095  51                   push ecx
// 0096e096  51                   push ecx
// 0096e097  b8f0c56200           mov eax, 0x62c5f0
// 0096e09c  50                   push eax
// 0096e09d  6864b79a00           push 0x9ab764
// 0096e0a2  6864b99c00           push 0x9cb964
// 0096e0a7  b9cc49b800           mov ecx, 0xb849cc
// 0096e0ac  e8af14ccff           call 0x62f560
// 0096e0b1  68e0109800           push 0x9810e0
// 0096e0b6  e86e68e8ff           call 0x7f4929
// 0096e0bb  59                   pop ecx
// 0096e0bc  c3                   ret 

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

static Desc desc("RAM", "Profile", &Owner::m0, 0, 15, 0);
