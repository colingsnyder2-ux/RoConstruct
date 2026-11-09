// from server: 100% by nuck16
// roc 2009-12 0096e480  unit: seg_00960000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096e480
//
// 0096e480  6a01                 push 1
// 0096e482  33c9                 xor ecx, ecx
// 0096e484  68b8ba9c00           push 0x9cbab8
// 0096e489  51                   push ecx
// 0096e48a  b8a0166300           mov eax, 0x6316a0
// 0096e48f  50                   push eax
// 0096e490  b9a050b800           mov ecx, 0xb850a0
// 0096e495  e8162bccff           call 0x630fb0
// 0096e49a  6810179800           push 0x981710
// 0096e49f  e88564e8ff           call 0x7f4929
// 0096e4a4  59                   pop ecx
// 0096e4a5  c3                   ret 

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

static Desc desc(&Owner::m0, "ResetCdnFailureCounts", 1);
