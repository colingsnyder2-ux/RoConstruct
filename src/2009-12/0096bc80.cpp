// from server: 100% by nuck16
// roc 2009-12 0096bc80  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096bc80
//
// 0096bc80  6a00                 push 0
// 0096bc82  6a06                 push 6
// 0096bc84  6838010000           push 0x138
// 0096bc89  6884b09b00           push 0x9bb084
// 0096bc8e  68e8b09b00           push 0x9bb0e8
// 0096bc93  b9c8e4b700           mov ecx, 0xb7e4c8
// 0096bc98  e88348b9ff           call 0x500520
// 0096bc9d  6880f29700           push 0x97f280
// 0096bca2  e8828ce8ff           call 0x7f4929
// 0096bca7  59                   pop ecx
// 0096bca8  c3                   ret 

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

static Desc desc("BuildPermissions", "Data", 312, 6, 0);
