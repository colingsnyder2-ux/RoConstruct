// from server: 100% by nuck16
// roc 2009-12 00974cd0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974cd0
//
// 00974cd0  6a00                 push 0
// 00974cd2  6a0f                 push 0xf
// 00974cd4  68b4000000           push 0xb4
// 00974cd9  6884b09b00           push 0x9bb084
// 00974cde  68e4769d00           push 0x9d76e4
// 00974ce3  b98c25b900           mov ecx, 0xb9258c
// 00974ce8  e81334d5ff           call 0x6c8100
// 00974ced  68505c9800           push 0x985c50
// 00974cf2  e832fce7ff           call 0x7f4929
// 00974cf7  59                   pop ecx
// 00974cf8  c3                   ret 

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

static Desc desc("Position", "Data", 180, 15, 0);
