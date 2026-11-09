// from server: 100% by nuck16
// roc 2009-12 0096d040  unit: seg_00960000  size: 57 bytes
//
// 0096d040  56                   push esi
// 0096d041  33f6                 xor esi, esi
// 0096d043  56                   push esi
// 0096d044  6a0f                 push 0xf
// 0096d046  33c9                 xor ecx, ecx
// 0096d048  51                   push ecx
// 0096d049  b8e08a5200           mov eax, 0x528ae0
// 0096d04e  50                   push eax
// 0096d04f  56                   push esi
// 0096d050  ba90725700           mov edx, 0x577290
// 0096d055  52                   push edx
// 0096d056  68b8c39b00           push 0x9bc3b8
// 0096d05b  6884c59b00           push 0x9bc584
// 0096d060  b958feb700           mov ecx, 0xb7fe58
// 0096d065  e8d6c3bbff           call 0x529440
// 0096d06a  6890039800           push 0x980390
// 0096d06f  e8b578e8ff           call 0x7f4929
// 0096d074  83c404               add esp, 4
// 0096d077  5e                   pop esi
// 0096d078  c3                   ret 

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

static Desc desc("ReportStatURL", "Network", &Owner::m0, &Owner::m1, 15, 0);
