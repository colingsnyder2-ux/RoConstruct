// from server: 100% by nuck16
// roc 2009-12 0096bce0  unit: seg_00960000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096bce0
//
// 0096bce0  6a01                 push 1
// 0096bce2  6828b19b00           push 0x9bb128
// 0096bce7  6818b19b00           push 0x9bb118
// 0096bcec  6824010000           push 0x124
// 0096bcf1  b960e6b700           mov ecx, 0xb7e660
// 0096bcf6  e8e5deb9ff           call 0x509be0
// 0096bcfb  6860f49700           push 0x97f460
// 0096bd00  e8248ce8ff           call 0x7f4929
// 0096bd05  59                   pop ecx
// 0096bd06  c3                   ret 

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
    Desc(int, const char *, const char *, int);
    ~Desc();
};

static Desc desc(292, "CharacterAdded", "character", 1);
