// from server: 100% by nuck16
// roc 2009-12 00978540  unit: seg_00970000  size: 57 bytes
//
// 00978540  56                   push esi
// 00978541  33f6                 xor esi, esi
// 00978543  56                   push esi
// 00978544  6a0f                 push 0xf
// 00978546  33c9                 xor ecx, ecx
// 00978548  51                   push ecx
// 00978549  b810507100           mov eax, 0x715010
// 0097854e  50                   push eax
// 0097854f  56                   push esi
// 00978550  bad04d5700           mov edx, 0x574dd0
// 00978555  52                   push edx
// 00978556  68dc1f9d00           push 0x9d1fdc
// 0097855b  68a8e79d00           push 0x9de7a8
// 00978560  b99054b900           mov ecx, 0xb95490
// 00978565  e8f6bed9ff           call 0x714460
// 0097856a  68e0799800           push 0x9879e0
// 0097856f  e8b5c3e7ff           call 0x7f4929
// 00978574  83c404               add esp, 4
// 00978577  5e                   pop esi
// 00978578  c3                   ret 

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

static Desc desc("Brightness", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
