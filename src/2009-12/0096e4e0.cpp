// from server: 100% by nuck16
// roc 2009-12 0096e4e0  unit: seg_00960000  size: 45 bytes
//
// 0096e4e0  33c9                 xor ecx, ecx
// 0096e4e2  51                   push ecx
// 0096e4e3  6a0f                 push 0xf
// 0096e4e5  51                   push ecx
// 0096e4e6  51                   push ecx
// 0096e4e7  b820c76200           mov eax, 0x62c720
// 0096e4ec  50                   push eax
// 0096e4ed  68b8c59b00           push 0x9bc5b8
// 0096e4f2  68e0ba9c00           push 0x9cbae0
// 0096e4f7  b9e050b800           mov ecx, 0xb850e0
// 0096e4fc  e88f09ccff           call 0x62ee90
// 0096e501  6860139800           push 0x981360
// 0096e506  e81e64e8ff           call 0x7f4929
// 0096e50b  59                   pop ecx
// 0096e50c  c3                   ret 

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

static Desc desc("ThreadAffinity", "Diagnostics", &Owner::m0, 0, 15, 0);
