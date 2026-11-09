// from server: 100% by nuck16
// roc 2009-12 00979ce0  unit: seg_00970000  size: 57 bytes
//
// 00979ce0  56                   push esi
// 00979ce1  33f6                 xor esi, esi
// 00979ce3  56                   push esi
// 00979ce4  6a02                 push 2
// 00979ce6  33c9                 xor ecx, ecx
// 00979ce8  51                   push ecx
// 00979ce9  b830de7300           mov eax, 0x73de30
// 00979cee  50                   push eax
// 00979cef  56                   push esi
// 00979cf0  ba90da7300           mov edx, 0x73da90
// 00979cf5  52                   push edx
// 00979cf6  6898bf9c00           push 0x9cbf98
// 00979cfb  6854249e00           push 0x9e2454
// 00979d00  b90868b900           mov ecx, 0xb96808
// 00979d05  e8363fdcff           call 0x73dc40
// 00979d0a  68c08b9800           push 0x988bc0
// 00979d0f  e815ace7ff           call 0x7f4929
// 00979d14  83c404               add esp, 4
// 00979d17  5e                   pop esi
// 00979d18  c3                   ret 

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

static Desc desc("FrontendMouseClick", "Behavior", &Owner::m0, &Owner::m1, 2, 0);
