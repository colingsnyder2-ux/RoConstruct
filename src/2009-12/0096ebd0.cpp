// from server: 100% by nuck16
// roc 2009-12 0096ebd0  unit: seg_00960000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ebd0
//
// 0096ebd0  33c9                 xor ecx, ecx
// 0096ebd2  51                   push ecx
// 0096ebd3  6828c09c00           push 0x9cc028
// 0096ebd8  6818c09c00           push 0x9cc018
// 0096ebdd  51                   push ecx
// 0096ebde  b8a0286300           mov eax, 0x6328a0
// 0096ebe3  50                   push eax
// 0096ebe4  b9d052b800           mov ecx, 0xb852d0
// 0096ebe9  e81263ccff           call 0x634f00
// 0096ebee  6840189800           push 0x981840
// 0096ebf3  e8315de8ff           call 0x7f4929
// 0096ebf8  59                   pop ecx
// 0096ebf9  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "IsAncestorOf", "descendant", 0);
