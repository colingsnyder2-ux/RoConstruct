// from server: 100% by nuck16
// roc 2009-12 00977c70  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977c70
//
// 00977c70  33c9                 xor ecx, ecx
// 00977c72  51                   push ecx
// 00977c73  6a0f                 push 0xf
// 00977c75  51                   push ecx
// 00977c76  b895020000           mov eax, 0x295
// 00977c7b  50                   push eax
// 00977c7c  6894d59d00           push 0x9dd594
// 00977c81  689cd59d00           push 0x9dd59c
// 00977c86  b9f04bb900           mov ecx, 0xb94bf0
// 00977c8b  e8c056d8ff           call 0x6fd350
// 00977c90  68c0759800           push 0x9875c0
// 00977c95  e88fcce7ff           call 0x7f4929
// 00977c9a  59                   pop ecx
// 00977c9b  c3                   ret 

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

static Desc desc("AllowTeamChangeOnTouch", "Teams", &Owner::m0, 15, 0);
