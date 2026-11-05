// from server: 100% by nuck16
// roc 2009-12 00978410  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978410
//
// 00978410  33c9                 xor ecx, ecx
// 00978412  51                   push ecx
// 00978413  6830e79d00           push 0x9de730
// 00978418  51                   push ecx
// 00978419  b840317100           mov eax, 0x713140
// 0097841e  50                   push eax
// 0097841f  b9c853b900           mov ecx, 0xb953c8
// 00978424  e867c4d9ff           call 0x714890
// 00978429  68907b9800           push 0x987b90
// 0097842e  e8f6c4e7ff           call 0x7f4929
// 00978433  59                   pop ecx
// 00978434  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "GetMoonPhase", 0);
