// from server: 100% by nuck16
// roc 2009-12 0096bba0  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096bba0
//
// 0096bba0  6a01                 push 1
// 0096bba2  6a06                 push 6
// 0096bba4  68dc000000           push 0xdc
// 0096bba9  6884b09b00           push 0x9bb084
// 0096bbae  68a8b09b00           push 0x9bb0a8
// 0096bbb3  b9a8e4b700           mov ecx, 0xb7e4a8
// 0096bbb8  e86346b9ff           call 0x500220
// 0096bbbd  6800f39700           push 0x97f300
// 0096bbc2  e8628de8ff           call 0x7f4929
// 0096bbc7  59                   pop ecx
// 0096bbc8  c3                   ret 

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

static Desc desc("SuperSafeChat", "Data", 220, 6, 1);
