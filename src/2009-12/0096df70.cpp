// from server: 100% by nuck16
// roc 2009-12 0096df70  unit: seg_00960000  size: 45 bytes
//
// 0096df70  33c9                 xor ecx, ecx
// 0096df72  51                   push ecx
// 0096df73  6a0f                 push 0xf
// 0096df75  51                   push ecx
// 0096df76  51                   push ecx
// 0096df77  b8e0bf6200           mov eax, 0x62bfe0
// 0096df7c  50                   push eax
// 0096df7d  6864b79a00           push 0x9ab764
// 0096df82  6824b99c00           push 0x9cb924
// 0096df87  b9e44cb800           mov ecx, 0xb84ce4
// 0096df8c  e8cf15ccff           call 0x62f560
// 0096df91  6820109800           push 0x981020
// 0096df96  e88e69e8ff           call 0x7f4929
// 0096df9b  59                   pop ecx
// 0096df9c  c3                   ret 

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
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("OsPlatformId", "Profile", &Owner::m0, 0, 15, 0);
