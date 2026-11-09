// from server: 100% by nuck16
// roc 2009-12 0096dee0  unit: seg_00960000  size: 45 bytes
//
// 0096dee0  33c9                 xor ecx, ecx
// 0096dee2  51                   push ecx
// 0096dee3  6a0f                 push 0xf
// 0096dee5  51                   push ecx
// 0096dee6  51                   push ecx
// 0096dee7  b880c76200           mov eax, 0x62c780
// 0096deec  50                   push eax
// 0096deed  6864b79a00           push 0x9ab764
// 0096def2  6800b99c00           push 0x9cb900
// 0096def7  b90050b800           mov ecx, 0xb85000
// 0096defc  e85f16ccff           call 0x62f560
// 0096df01  68a0159800           push 0x9815a0
// 0096df06  e81e6ae8ff           call 0x7f4929
// 0096df0b  59                   pop ecx
// 0096df0c  c3                   ret 

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

static Desc desc("VideoMemory", "Profile", &Owner::m0, 0, 15, 0);
