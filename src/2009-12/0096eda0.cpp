// from server: 100% by nuck16
// roc 2009-12 0096eda0  unit: seg_00960000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096eda0
//
// 0096eda0  6a01                 push 1
// 0096eda2  68acc09c00           push 0x9cc0ac
// 0096eda7  6860c09c00           push 0x9cc060
// 0096edac  689cc09c00           push 0x9cc09c
// 0096edb1  6888000000           push 0x88
// 0096edb6  b93055b800           mov ecx, 0xb85530
// 0096edbb  e85073ccff           call 0x636110
// 0096edc0  68401a9800           push 0x981a40
// 0096edc5  e85f5be8ff           call 0x7f4929
// 0096edca  59                   pop ecx
// 0096edcb  c3                   ret 

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
    Desc(int, const char *, const char *, const char *, int);
    ~Desc();
};

static Desc desc(136, "AncestryChanged", "child", "parent", 1);
