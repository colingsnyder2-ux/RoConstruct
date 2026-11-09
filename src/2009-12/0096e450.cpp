// from server: 100% by nuck16
// roc 2009-12 0096e450  unit: seg_00960000  size: 45 bytes
//
// 0096e450  33c9                 xor ecx, ecx
// 0096e452  51                   push ecx
// 0096e453  6a0f                 push 0xf
// 0096e455  51                   push ecx
// 0096e456  51                   push ecx
// 0096e457  b810be6200           mov eax, 0x62be10
// 0096e45c  50                   push eax
// 0096e45d  68a0b99c00           push 0x9cb9a0
// 0096e462  68a0ba9c00           push 0x9cbaa0
// 0096e467  b9f44bb800           mov ecx, 0xb84bf4
// 0096e46c  e88f11ccff           call 0x62f600
// 0096e471  6820139800           push 0x981320
// 0096e476  e8ae64e8ff           call 0x7f4929
// 0096e47b  59                   pop ecx
// 0096e47c  c3                   ret 

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

static Desc desc("LastCdnFailureTimeSpan", "PerfCounters", &Owner::m0, 0, 15, 0);
