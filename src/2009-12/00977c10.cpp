// from server: 100% by nuck16
// roc 2009-12 00977c10  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977c10
//
// 00977c10  33c9                 xor ecx, ecx
// 00977c12  51                   push ecx
// 00977c13  6a0f                 push 0xf
// 00977c15  51                   push ecx
// 00977c16  b898020000           mov eax, 0x298
// 00977c1b  50                   push eax
// 00977c1c  6888d59d00           push 0x9dd588
// 00977c21  687cd59d00           push 0x9dd57c
// 00977c26  b9344cb900           mov ecx, 0xb94c34
// 00977c2b  e85056d8ff           call 0x6fd280
// 00977c30  6800769800           push 0x987600
// 00977c35  e8efcce7ff           call 0x7f4929
// 00977c3a  59                   pop ecx
// 00977c3b  c3                   ret 

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
    Desc(const char *, const char *, void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Duration", "Forcefield", &Owner::m0, 15, 0);
