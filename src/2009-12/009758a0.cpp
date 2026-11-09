// from server: 100% by nuck16
// roc 2009-12 009758a0  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009758a0
//
// 009758a0  6a01                 push 1
// 009758a2  6a01                 push 1
// 009758a4  6890959d00           push 0x9d9590
// 009758a9  33c9                 xor ecx, ecx
// 009758ab  687c959d00           push 0x9d957c
// 009758b0  51                   push ecx
// 009758b1  b890916d00           mov eax, 0x6d9190
// 009758b6  50                   push eax
// 009758b7  b94031b900           mov ecx, 0xb93140
// 009758bc  e8af2fd6ff           call 0x6d8870
// 009758c1  6830629800           push 0x986230
// 009758c6  e85ef0e7ff           call 0x7f4929
// 009758cb  59                   pop ecx
// 009758cc  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "GetTimesForFrames", "frames", 1, 1);
