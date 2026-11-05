// from server: 100% by nuck16
// roc 2009-12 00977d00  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977d00
//
// 00977d00  33c9                 xor ecx, ecx
// 00977d02  51                   push ecx
// 00977d03  6a0f                 push 0xf
// 00977d05  51                   push ecx
// 00977d06  b8b0e36f00           mov eax, 0x6fe3b0
// 00977d0b  50                   push eax
// 00977d0c  6898000000           push 0x98
// 00977d11  68dc1f9d00           push 0x9d1fdc
// 00977d16  6874db9d00           push 0x9ddb74
// 00977d1b  b9e84cb900           mov ecx, 0xb94ce8
// 00977d20  e8eb6bd8ff           call 0x6fe910
// 00977d25  6880779800           push 0x987780
// 00977d2a  e8facbe7ff           call 0x7f4929
// 00977d2f  59                   pop ecx
// 00977d30  c3                   ret 

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

static Desc desc("Graphic", "Appearance", 152, &Owner::m0, 15, 0);
