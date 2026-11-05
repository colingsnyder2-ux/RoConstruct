// from server: 100% by nuck16
// roc 2009-12 0096ba20  unit: seg_00960000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ba20
//
// 0096ba20  6a01                 push 1
// 0096ba22  33c9                 xor ecx, ecx
// 0096ba24  6824b09b00           push 0x9bb024
// 0096ba29  51                   push ecx
// 0096ba2a  b830cb5000           mov eax, 0x50cb30
// 0096ba2f  50                   push eax
// 0096ba30  b908e5b700           mov ecx, 0xb7e508
// 0096ba35  e8d6deb9ff           call 0x509910
// 0096ba3a  68f0f39700           push 0x97f3f0
// 0096ba3f  e8e58ee8ff           call 0x7f4929
// 0096ba44  59                   pop ecx
// 0096ba45  c3                   ret 

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

static Desc desc(&Owner::m0, "RemoveCharacter", 1);
