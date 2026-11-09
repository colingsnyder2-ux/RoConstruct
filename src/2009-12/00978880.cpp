// from server: 100% by nuck16
// roc 2009-12 00978880  unit: seg_00970000  size: 57 bytes
//
// 00978880  56                   push esi
// 00978881  33f6                 xor esi, esi
// 00978883  56                   push esi
// 00978884  6a0f                 push 0xf
// 00978886  33c9                 xor ecx, ecx
// 00978888  51                   push ecx
// 00978889  b8606d7100           mov eax, 0x716d60
// 0097888e  50                   push eax
// 0097888f  56                   push esi
// 00978890  ba20597100           mov edx, 0x715920
// 00978895  52                   push edx
// 00978896  6884b09b00           push 0x9bb084
// 0097889b  68fcf49d00           push 0x9df4fc
// 009788a0  b95c57b900           mov ecx, 0xb9575c
// 009788a5  e886ded9ff           call 0x716730
// 009788aa  68507d9800           push 0x987d50
// 009788af  e875c0e7ff           call 0x7f4929
// 009788b4  83c404               add esp, 4
// 009788b7  5e                   pop esi
// 009788b8  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
    void m1();
};


struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("MaxVelocity", "Data", &Owner::m0, &Owner::m1, 15, 0);
