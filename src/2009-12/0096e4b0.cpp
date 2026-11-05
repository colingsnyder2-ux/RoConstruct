// from server: 100% by nuck16
// roc 2009-12 0096e4b0  unit: seg_00960000  size: 45 bytes
//
// 0096e4b0  33c9                 xor ecx, ecx
// 0096e4b2  51                   push ecx
// 0096e4b3  6a0f                 push 0xf
// 0096e4b5  51                   push ecx
// 0096e4b6  51                   push ecx
// 0096e4b7  b800c76200           mov eax, 0x62c700
// 0096e4bc  50                   push eax
// 0096e4bd  68b8c59b00           push 0x9bc5b8
// 0096e4c2  68d0ba9c00           push 0x9cbad0
// 0096e4c7  b9944bb800           mov ecx, 0xb84b94
// 0096e4cc  e81f09ccff           call 0x62edf0
// 0096e4d1  6880139800           push 0x981380
// 0096e4d6  e84e64e8ff           call 0x7f4929
// 0096e4db  59                   pop ecx
// 0096e4dc  c3                   ret 

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

static Desc desc("ThreadPoolSize", "Diagnostics", &Owner::m0, 0, 15, 0);
