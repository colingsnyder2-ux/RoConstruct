// from server: 100% by nuck16
// roc 2009-12 0096e5d0  unit: seg_00960000  size: 45 bytes
//
// 0096e5d0  33c9                 xor ecx, ecx
// 0096e5d2  51                   push ecx
// 0096e5d3  6a0f                 push 0xf
// 0096e5d5  51                   push ecx
// 0096e5d6  51                   push ecx
// 0096e5d7  b810bd6200           mov eax, 0x62bd10
// 0096e5dc  50                   push eax
// 0096e5dd  68b8c59b00           push 0x9bc5b8
// 0096e5e2  6830bb9c00           push 0x9cbb30
// 0096e5e7  b9744bb800           mov ecx, 0xb84b74
// 0096e5ec  e89f08ccff           call 0x62ee90
// 0096e5f1  68a00f9800           push 0x980fa0
// 0096e5f6  e82e63e8ff           call 0x7f4929
// 0096e5fb  59                   pop ecx
// 0096e5fc  c3                   ret 

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

static Desc desc("SchedulerDutyCycle", "Diagnostics", &Owner::m0, 0, 15, 0);
