// from server: 100% by nuck16
// roc 2009-12 0096c6b0  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c6b0
//
// 0096c6b0  6a04                 push 4
// 0096c6b2  689cb19b00           push 0x9bb19c
// 0096c6b7  33c9                 xor ecx, ecx
// 0096c6b9  6810b99b00           push 0x9bb910
// 0096c6be  51                   push ecx
// 0096c6bf  b880275100           mov eax, 0x512780
// 0096c6c4  50                   push eax
// 0096c6c5  b978ecb700           mov ecx, 0xb7ec78
// 0096c6ca  e8a107bbff           call 0x51ce70
// 0096c6cf  68f0fb9700           push 0x97fbf0
// 0096c6d4  e85082e8ff           call 0x7f4929
// 0096c6d9  59                   pop ecx
// 0096c6da  c3                   ret 

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

static Desc desc(&Owner::m0, "SetBuildToolsUrl", "url", 4);
