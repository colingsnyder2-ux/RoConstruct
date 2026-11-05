// from server: 100% by nuck16
// roc 2009-12 00974420  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974420
//
// 00974420  6a00                 push 0
// 00974422  6a0f                 push 0xf
// 00974424  68cc000000           push 0xcc
// 00974429  6898bf9c00           push 0x9cbf98
// 0097442e  687c669d00           push 0x9d667c
// 00974433  b9a81ab900           mov ecx, 0xb91aa8
// 00974438  e8b328d4ff           call 0x6b6cf0
// 0097443d  6890569800           push 0x985690
// 00974442  e8e204e8ff           call 0x7f4929
// 00974447  59                   pop ecx
// 00974448  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};


struct Desc
{
    Desc(const char *, const char *, int, int, int);
    ~Desc();
};

static Desc desc("PlayOnRemove", "Behavior", 204, 15, 0);
