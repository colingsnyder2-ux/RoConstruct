// from server: 100% by nuck16
// roc 2009-12 00977d70  unit: seg_00970000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977d70
//
// 00977d70  33c9                 xor ecx, ecx
// 00977d72  51                   push ecx
// 00977d73  51                   push ecx
// 00977d74  51                   push ecx
// 00977d75  b8b0e36f00           mov eax, 0x6fe3b0
// 00977d7a  50                   push eax
// 00977d7b  68b8000000           push 0xb8
// 00977d80  68dc1f9d00           push 0x9d1fdc
// 00977d85  6884db9d00           push 0x9ddb84
// 00977d8a  b92c4db900           mov ecx, 0xb94d2c
// 00977d8f  e85c6cd8ff           call 0x6fe9f0
// 00977d94  6840779800           push 0x987740
// 00977d99  e88bcbe7ff           call 0x7f4929
// 00977d9e  59                   pop ecx
// 00977d9f  c3                   ret 

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

static Desc desc("Outfit2", "Appearance", 184, &Owner::m0, 0, 0);
