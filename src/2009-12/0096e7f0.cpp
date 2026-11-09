// from server: 100% by nuck16
// roc 2009-12 0096e7f0  unit: seg_00960000  size: 57 bytes
//
// 0096e7f0  56                   push esi
// 0096e7f1  33f6                 xor esi, esi
// 0096e7f3  56                   push esi
// 0096e7f4  6a0f                 push 0xf
// 0096e7f6  33c9                 xor ecx, ecx
// 0096e7f8  51                   push ecx
// 0096e7f9  b870166300           mov eax, 0x631670
// 0096e7fe  50                   push eax
// 0096e7ff  56                   push esi
// 0096e800  ba80bd6200           mov edx, 0x62bd80
// 0096e805  52                   push edx
// 0096e806  6820a79b00           push 0x9ba720
// 0096e80b  68c8bb9c00           push 0x9cbbc8
// 0096e810  b9bc4cb800           mov ecx, 0xb84cbc
// 0096e815  e83630ccff           call 0x631850
// 0096e81a  6860149800           push 0x981460
// 0096e81f  e80561e8ff           call 0x7f4929
// 0096e824  83c404               add esp, 4
// 0096e827  5e                   pop esi
// 0096e828  c3                   ret 

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

static Desc desc("Concurrency", "Configuration", &Owner::m0, &Owner::m1, 15, 0);
