// from server: 100% by nuck16
// roc 2009-12 0096e1e0  unit: seg_00960000  size: 45 bytes
//
// 0096e1e0  33c9                 xor ecx, ecx
// 0096e1e2  51                   push ecx
// 0096e1e3  6a0f                 push 0xf
// 0096e1e5  51                   push ecx
// 0096e1e6  51                   push ecx
// 0096e1e7  b8a0d16200           mov eax, 0x62d1a0
// 0096e1ec  50                   push eax
// 0096e1ed  68a0b99c00           push 0x9cb9a0
// 0096e1f2  68d4b99c00           push 0x9cb9d4
// 0096e1f7  b9544bb800           mov ecx, 0xb84b54
// 0096e1fc  e85f13ccff           call 0x62f560
// 0096e201  6880119800           push 0x981180
// 0096e206  e81e67e8ff           call 0x7f4929
// 0096e20b  59                   pop ecx
// 0096e20c  c3                   ret 

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

static Desc desc("ProcessorTime", "PerfCounters", &Owner::m0, 0, 15, 0);
