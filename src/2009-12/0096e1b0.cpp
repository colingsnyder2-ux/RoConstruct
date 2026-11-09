// from server: 100% by nuck16
// roc 2009-12 0096e1b0  unit: seg_00960000  size: 45 bytes
//
// 0096e1b0  33c9                 xor ecx, ecx
// 0096e1b2  51                   push ecx
// 0096e1b3  6a0f                 push 0xf
// 0096e1b5  51                   push ecx
// 0096e1b6  51                   push ecx
// 0096e1b7  b810d16200           mov eax, 0x62d110
// 0096e1bc  50                   push eax
// 0096e1bd  68a0b99c00           push 0x9cb9a0
// 0096e1c2  68c0b99c00           push 0x9cb9c0
// 0096e1c7  b9644db800           mov ecx, 0xb84d64
// 0096e1cc  e88f13ccff           call 0x62f560
// 0096e1d1  6860119800           push 0x981160
// 0096e1d6  e84e67e8ff           call 0x7f4929
// 0096e1db  59                   pop ecx
// 0096e1dc  c3                   ret 

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

static Desc desc("TotalProcessorTime", "PerfCounters", &Owner::m0, 0, 15, 0);
