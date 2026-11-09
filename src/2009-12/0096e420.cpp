// from server: 100% by nuck16
// roc 2009-12 0096e420  unit: seg_00960000  size: 45 bytes
//
// 0096e420  33c9                 xor ecx, ecx
// 0096e422  51                   push ecx
// 0096e423  6a0f                 push 0xf
// 0096e425  51                   push ecx
// 0096e426  51                   push ecx
// 0096e427  b800be6200           mov eax, 0x62be00
// 0096e42c  50                   push eax
// 0096e42d  68a0b99c00           push 0x9cb9a0
// 0096e432  6890ba9c00           push 0x9cba90
// 0096e437  b9684ab800           mov ecx, 0xb84a68
// 0096e43c  e85f12ccff           call 0x62f6a0
// 0096e441  6800139800           push 0x981300
// 0096e446  e8de64e8ff           call 0x7f4929
// 0096e44b  59                   pop ecx
// 0096e44c  c3                   ret 

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

static Desc desc("CdnFailureCount", "PerfCounters", &Owner::m0, 0, 15, 0);
