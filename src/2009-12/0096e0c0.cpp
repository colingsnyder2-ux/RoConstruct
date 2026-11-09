// from server: 100% by nuck16
// roc 2009-12 0096e0c0  unit: seg_00960000  size: 45 bytes
//
// 0096e0c0  33c9                 xor ecx, ecx
// 0096e0c2  51                   push ecx
// 0096e0c3  6a0f                 push 0xf
// 0096e0c5  51                   push ecx
// 0096e0c6  51                   push ecx
// 0096e0c7  b8f0c56200           mov eax, 0x62c5f0
// 0096e0cc  50                   push eax
// 0096e0cd  6864b79a00           push 0x9ab764
// 0096e0d2  6868b99c00           push 0x9cb968
// 0096e0d7  b9384fb800           mov ecx, 0xb84f38
// 0096e0dc  e87f14ccff           call 0x62f560
// 0096e0e1  6800119800           push 0x981100
// 0096e0e6  e83e68e8ff           call 0x7f4929
// 0096e0eb  59                   pop ecx
// 0096e0ec  c3                   ret 

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

static Desc desc("TotalPhysicalMemory", "Profile", &Owner::m0, 0, 15, 0);
