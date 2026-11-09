// from server: 100% by nuck16
// roc 2009-12 0096bae0  unit: seg_00960000  size: 57 bytes
//
// 0096bae0  56                   push esi
// 0096bae1  33f6                 xor esi, esi
// 0096bae3  56                   push esi
// 0096bae4  6a0f                 push 0xf
// 0096bae6  33c9                 xor ecx, ecx
// 0096bae8  51                   push ecx
// 0096bae9  b8e0c55000           mov eax, 0x50c5e0
// 0096baee  50                   push eax
// 0096baef  56                   push esi
// 0096baf0  ba80d26300           mov edx, 0x63d280
// 0096baf5  52                   push edx
// 0096baf6  6884b09b00           push 0x9bb084
// 0096bafb  6878b09b00           push 0x9bb078
// 0096bb00  b918e7b700           mov ecx, 0xb7e718
// 0096bb05  e80642b9ff           call 0x4ffd10
// 0096bb0a  6860f29700           push 0x97f260
// 0096bb0f  e8158ee8ff           call 0x7f4929
// 0096bb14  83c404               add esp, 4
// 0096bb17  5e                   pop esi
// 0096bb18  c3                   ret 

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

static Desc desc("Character", "Data", &Owner::m0, &Owner::m1, 15, 0);
