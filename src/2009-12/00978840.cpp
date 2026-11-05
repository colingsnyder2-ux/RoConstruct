// from server: 100% by nuck16
// roc 2009-12 00978840  unit: seg_00970000  size: 57 bytes
//
// 00978840  56                   push esi
// 00978841  33f6                 xor esi, esi
// 00978843  56                   push esi
// 00978844  6a0f                 push 0xf
// 00978846  33c9                 xor ecx, ecx
// 00978848  51                   push ecx
// 00978849  b800597100           mov eax, 0x715900
// 0097884e  50                   push eax
// 0097884f  56                   push esi
// 00978850  baf0587100           mov edx, 0x7158f0
// 00978855  52                   push edx
// 00978856  6884b09b00           push 0x9bb084
// 0097885b  68f0f49d00           push 0x9df4f0
// 00978860  b97056b900           mov ecx, 0xb95670
// 00978865  e8f6dcd9ff           call 0x716560
// 0097886a  68707d9800           push 0x987d70
// 0097886f  e8b5c0e7ff           call 0x7f4929
// 00978874  83c404               add esp, 4
// 00978877  5e                   pop esi
// 00978878  c3                   ret 

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

static Desc desc("BaseAngle", "Data", &Owner::m0, &Owner::m1, 15, 0);
