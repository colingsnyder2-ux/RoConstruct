// from server: 100% by nuck16
// roc 2009-12 0096e120  unit: seg_00960000  size: 45 bytes
//
// 0096e120  33c9                 xor ecx, ecx
// 0096e122  51                   push ecx
// 0096e123  6a0f                 push 0xf
// 0096e125  51                   push ecx
// 0096e126  51                   push ecx
// 0096e127  b820c66200           mov eax, 0x62c620
// 0096e12c  50                   push eax
// 0096e12d  68a0b99c00           push 0x9cb9a0
// 0096e132  6888b99c00           push 0x9cb988
// 0096e137  b9784fb800           mov ecx, 0xb84f78
// 0096e13c  e81f14ccff           call 0x62f560
// 0096e141  6840119800           push 0x981140
// 0096e146  e8de67e8ff           call 0x7f4929
// 0096e14b  59                   pop ecx
// 0096e14c  c3                   ret 

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

static Desc desc("AvailablePhysicalMemory", "PerfCounters", &Owner::m0, 0, 15, 0);
