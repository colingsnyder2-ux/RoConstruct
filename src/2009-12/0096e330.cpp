// from server: 100% by nuck16
// roc 2009-12 0096e330  unit: seg_00960000  size: 45 bytes
//
// 0096e330  33c9                 xor ecx, ecx
// 0096e332  51                   push ecx
// 0096e333  6a0f                 push 0xf
// 0096e335  51                   push ecx
// 0096e336  51                   push ecx
// 0096e337  b870c76200           mov eax, 0x62c770
// 0096e33c  50                   push eax
// 0096e33d  68a0b99c00           push 0x9cb9a0
// 0096e342  6850ba9c00           push 0x9cba50
// 0096e347  b9184fb800           mov ecx, 0xb84f18
// 0096e34c  e84f13ccff           call 0x62f6a0
// 0096e351  6840129800           push 0x981240
// 0096e356  e8ce65e8ff           call 0x7f4929
// 0096e35b  59                   pop ecx
// 0096e35c  c3                   ret 

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

static Desc desc("PlayerCount", "PerfCounters", &Owner::m0, 0, 15, 0);
