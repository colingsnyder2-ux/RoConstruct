// from server: 100% by nuck16
// roc 2009-12 00977c40  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977c40
//
// 00977c40  33c9                 xor ecx, ecx
// 00977c42  51                   push ecx
// 00977c43  6a0f                 push 0xf
// 00977c45  51                   push ecx
// 00977c46  b894020000           mov eax, 0x294
// 00977c4b  50                   push eax
// 00977c4c  6894d59d00           push 0x9dd594
// 00977c51  68e0b09b00           push 0x9bb0e0
// 00977c56  b9144cb900           mov ecx, 0xb94c14
// 00977c5b  e8f056d8ff           call 0x6fd350
// 00977c60  68e0759800           push 0x9875e0
// 00977c65  e8bfcce7ff           call 0x7f4929
// 00977c6a  59                   pop ecx
// 00977c6b  c3                   ret 

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

static Desc desc("Neutral", "Teams", &Owner::m0, 15, 0);
