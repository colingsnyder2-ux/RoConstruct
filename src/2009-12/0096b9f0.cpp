// from server: 100% by nuck16
// roc 2009-12 0096b9f0  unit: seg_00960000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096b9f0
//
// 0096b9f0  6a01                 push 1
// 0096b9f2  6a01                 push 1
// 0096b9f4  681cb09b00           push 0x9bb01c
// 0096b9f9  33c9                 xor ecx, ecx
// 0096b9fb  680cb09b00           push 0x9bb00c
// 0096ba00  51                   push ecx
// 0096ba01  b840205100           mov eax, 0x512040
// 0096ba06  50                   push eax
// 0096ba07  b998e6b700           mov ecx, 0xb7e698
// 0096ba0c  e83fdcb9ff           call 0x509650
// 0096ba11  68a0f89700           push 0x97f8a0
// 0096ba16  e80e8fe8ff           call 0x7f4929
// 0096ba1b  59                   pop ecx
// 0096ba1c  c3                   ret 

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

static Desc desc(&Owner::m0, "LoadCharacter", "inGame", 1, 1);
