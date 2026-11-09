// from server: 100% by nuck16
// roc 2009-12 0096c6e0  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c6e0
//
// 0096c6e0  6a04                 push 4
// 0096c6e2  689cb19b00           push 0x9bb19c
// 0096c6e7  33c9                 xor ecx, ecx
// 0096c6e9  6824b99b00           push 0x9bb924
// 0096c6ee  51                   push ecx
// 0096c6ef  b8e0265100           mov eax, 0x5126e0
// 0096c6f4  50                   push eax
// 0096c6f5  b968eeb700           mov ecx, 0xb7ee68
// 0096c6fa  e87107bbff           call 0x51ce70
// 0096c6ff  6800fc9700           push 0x97fc00
// 0096c704  e82082e8ff           call 0x7f4929
// 0096c709  59                   pop ecx
// 0096c70a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetBuildUserPermissionsUrl", "url", 4);
