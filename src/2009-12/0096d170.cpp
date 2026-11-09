// from server: 100% by nuck16
// roc 2009-12 0096d170  unit: seg_00960000  size: 57 bytes
//
// 0096d170  56                   push esi
// 0096d171  33f6                 xor esi, esi
// 0096d173  56                   push esi
// 0096d174  6a0f                 push 0xf
// 0096d176  33c9                 xor ecx, ecx
// 0096d178  51                   push ecx
// 0096d179  b8d09d5200           mov eax, 0x529dd0
// 0096d17e  50                   push eax
// 0096d17f  56                   push esi
// 0096d180  ba808a5200           mov edx, 0x528a80
// 0096d185  52                   push edx
// 0096d186  680cc69b00           push 0x9bc60c
// 0096d18b  6800c69b00           push 0x9bc600
// 0096d190  b940ffb700           mov ecx, 0xb7ff40
// 0096d195  e856d0bbff           call 0x52a1f0
// 0096d19a  6830029800           push 0x980230
// 0096d19f  e88577e8ff           call 0x7f4929
// 0096d1a4  83c404               add esp, 4
// 0096d1a7  5e                   pop esi
// 0096d1a8  c3                   ret 

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

static Desc desc("PhysicsSend", "Physics", &Owner::m0, &Owner::m1, 15, 0);
