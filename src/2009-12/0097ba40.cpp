// from server: 100% by nuck16
// roc 2009-12 0097ba40  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097ba40
//
// 0097ba40  33c9                 xor ecx, ecx
// 0097ba42  51                   push ecx
// 0097ba43  6a0f                 push 0xf
// 0097ba45  51                   push ecx
// 0097ba46  51                   push ecx
// 0097ba47  b8c0b77600           mov eax, 0x76b7c0
// 0097ba4c  50                   push eax
// 0097ba4d  6884b09b00           push 0x9bb084
// 0097ba52  6828249a00           push 0x9a2428
// 0097ba57  b93481b900           mov ecx, 0xb98134
// 0097ba5c  e81f04dfff           call 0x76be80
// 0097ba61  68f09a9800           push 0x989af0
// 0097ba66  e8be8ee7ff           call 0x7f4929
// 0097ba6b  59                   pop ecx
// 0097ba6c  c3                   ret 

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

static Desc desc("X", "Data", &Owner::m0, 0, 15, 0);
