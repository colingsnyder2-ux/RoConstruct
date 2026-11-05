// from server: 100% by nuck16
// roc 2009-12 0096e150  unit: seg_00960000  size: 45 bytes
//
// 0096e150  33c9                 xor ecx, ecx
// 0096e152  51                   push ecx
// 0096e153  6a0f                 push 0xf
// 0096e155  51                   push ecx
// 0096e156  51                   push ecx
// 0096e157  b880d06200           mov eax, 0x62d080
// 0096e15c  50                   push eax
// 0096e15d  68a0b99c00           push 0x9cb9a0
// 0096e162  6878df9b00           push 0x9bdf78
// 0096e167  b9984fb800           mov ecx, 0xb84f98
// 0096e16c  e88f14ccff           call 0x62f600
// 0096e171  68e0159800           push 0x9815e0
// 0096e176  e8ae67e8ff           call 0x7f4929
// 0096e17b  59                   pop ecx
// 0096e17c  c3                   ret 

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

static Desc desc("ElapsedTime", "PerfCounters", &Owner::m0, 0, 15, 0);
