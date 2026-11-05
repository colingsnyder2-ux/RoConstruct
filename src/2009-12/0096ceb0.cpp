// from server: 100% by nuck16
// roc 2009-12 0096ceb0  unit: seg_00960000  size: 57 bytes
//
// 0096ceb0  56                   push esi
// 0096ceb1  33f6                 xor esi, esi
// 0096ceb3  56                   push esi
// 0096ceb4  6a0f                 push 0xf
// 0096ceb6  33c9                 xor ecx, ecx
// 0096ceb8  51                   push ecx
// 0096ceb9  b8809c5200           mov eax, 0x529c80
// 0096cebe  50                   push eax
// 0096cebf  56                   push esi
// 0096cec0  bab08a5200           mov edx, 0x528ab0
// 0096cec5  52                   push edx
// 0096cec6  68b8c39b00           push 0x9bc3b8
// 0096cecb  68f4c49b00           push 0x9bc4f4
// 0096ced0  b9b400b800           mov ecx, 0xb800b4
// 0096ced5  e866c2bbff           call 0x529140
// 0096ceda  68b0029800           push 0x9802b0
// 0096cedf  e8457ae8ff           call 0x7f4929
// 0096cee4  83c404               add esp, 4
// 0096cee7  5e                   pop esi
// 0096cee8  c3                   ret 

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

static Desc desc("DataSendRate", "Network", &Owner::m0, &Owner::m1, 15, 0);
