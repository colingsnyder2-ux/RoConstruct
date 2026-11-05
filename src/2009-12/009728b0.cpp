// from server: 100% by nuck16
// roc 2009-12 009728b0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009728b0
//
// 009728b0  6a04                 push 4
// 009728b2  33c9                 xor ecx, ecx
// 009728b4  51                   push ecx
// 009728b5  6830f39c00           push 0x9cf330
// 009728ba  689cb19b00           push 0x9bb19c
// 009728bf  6828f39c00           push 0x9cf328
// 009728c4  51                   push ecx
// 009728c5  b8d0216700           mov eax, 0x6721d0
// 009728ca  50                   push eax
// 009728cb  b90004b900           mov ecx, 0xb90400
// 009728d0  e89bc1cfff           call 0x66ea70
// 009728d5  68504b9800           push 0x984b50
// 009728da  e84a20e8ff           call 0x7f4929
// 009728df  59                   pop ecx
// 009728e0  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, const char *, int, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "HttpGet", "url", "synchronous", 0, 4);
