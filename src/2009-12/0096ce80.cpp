// from server: 100% by nuck16
// roc 2009-12 0096ce80  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ce80
//
// 0096ce80  6a00                 push 0
// 0096ce82  6a0f                 push 0xf
// 0096ce84  68cc000000           push 0xcc
// 0096ce89  68b8c39b00           push 0x9bc3b8
// 0096ce8e  68e0c49b00           push 0x9bc4e0
// 0096ce93  b93000b800           mov ecx, 0xb80030
// 0096ce98  e8d3c1bbff           call 0x529070
// 0096ce9d  68d0029800           push 0x9802d0
// 0096cea2  e8827ae8ff           call 0x7f4929
// 0096cea7  59                   pop ecx
// 0096cea8  c3                   ret 

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

static Desc desc("PreferredClientPort", "Network", 204, 15, 0);
