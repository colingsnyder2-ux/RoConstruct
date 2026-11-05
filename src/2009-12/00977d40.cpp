// from server: 100% by nuck16
// roc 2009-12 00977d40  unit: seg_00970000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977d40
//
// 00977d40  33c9                 xor ecx, ecx
// 00977d42  51                   push ecx
// 00977d43  51                   push ecx
// 00977d44  51                   push ecx
// 00977d45  b8b0e36f00           mov eax, 0x6fe3b0
// 00977d4a  50                   push eax
// 00977d4b  6898000000           push 0x98
// 00977d50  68dc1f9d00           push 0x9d1fdc
// 00977d55  687cdb9d00           push 0x9ddb7c
// 00977d5a  b9884cb900           mov ecx, 0xb94c88
// 00977d5f  e88c6cd8ff           call 0x6fe9f0
// 00977d64  6860779800           push 0x987760
// 00977d69  e8bbcbe7ff           call 0x7f4929
// 00977d6e  59                   pop ecx
// 00977d6f  c3                   ret 

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
    Desc(const char *, const char *, int, void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Outfit1", "Appearance", 152, &Owner::m0, 0, 0);
