// from server: 100% by nuck16
// roc 2009-12 0096eae0  unit: seg_00960000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096eae0
//
// 0096eae0  33c9                 xor ecx, ecx
// 0096eae2  51                   push ecx
// 0096eae3  68d0bf9c00           push 0x9cbfd0
// 0096eae8  51                   push ecx
// 0096eae9  b8c0e55300           mov eax, 0x53e5c0
// 0096eaee  50                   push eax
// 0096eaef  b93854b800           mov ecx, 0xb85438
// 0096eaf4  e8c760ccff           call 0x634bc0
// 0096eaf9  68a0189800           push 0x9818a0
// 0096eafe  e8265ee8ff           call 0x7f4929
// 0096eb03  59                   pop ecx
// 0096eb04  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "Remove", 0);
