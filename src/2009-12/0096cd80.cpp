// from server: 100% by nuck16
// roc 2009-12 0096cd80  unit: seg_00960000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096cd80
//
// 0096cd80  6a01                 push 1
// 0096cd82  68b80b0000           push 0xbb8
// 0096cd87  68f8be9b00           push 0x9bbef8
// 0096cd8c  33c9                 xor ecx, ecx
// 0096cd8e  68ecbe9b00           push 0x9bbeec
// 0096cd93  51                   push ecx
// 0096cd94  b8f05c5200           mov eax, 0x525cf0
// 0096cd99  50                   push eax
// 0096cd9a  b908feb700           mov ecx, 0xb7fe08
// 0096cd9f  e82ca9bbff           call 0x5276d0
// 0096cda4  6840009800           push 0x980040
// 0096cda9  e87b7be8ff           call 0x7f4929
// 0096cdae  59                   pop ecx
// 0096cdaf  c3                   ret 

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

static Desc desc(&Owner::m0, "Disconnect", "blockDuration", 3000, 1);
