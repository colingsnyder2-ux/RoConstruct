// from server: 100% by nuck16
// roc 2009-12 0096c500  unit: seg_00960000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c500
//
// 0096c500  33c9                 xor ecx, ecx
// 0096c502  51                   push ecx
// 0096c503  6a0f                 push 0xf
// 0096c505  51                   push ecx
// 0096c506  51                   push ecx
// 0096c507  b830335100           mov eax, 0x513330
// 0096c50c  50                   push eax
// 0096c50d  6884b09b00           push 0x9bb084
// 0096c512  6894b89b00           push 0x9bb894
// 0096c517  b908edb700           mov ecx, 0xb7ed08
// 0096c51c  e8bfe0baff           call 0x51a5e0
// 0096c521  68d0fa9700           push 0x97fad0
// 0096c526  e8fe83e8ff           call 0x7f4929
// 0096c52b  59                   pop ecx
// 0096c52c  c3                   ret 

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

static Desc desc("LocalPlayer", "Data", &Owner::m0, 0, 15, 0);
