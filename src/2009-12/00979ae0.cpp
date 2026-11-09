// from server: 100% by nuck16
// roc 2009-12 00979ae0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979ae0
//
// 00979ae0  6a00                 push 0
// 00979ae2  6a0f                 push 0xf
// 00979ae4  6864010000           push 0x164
// 00979ae9  68141c9e00           push 0x9e1c14
// 00979aee  68ec029d00           push 0x9d02ec
// 00979af3  b96064b900           mov ecx, 0xb96460
// 00979af8  e803f5dbff           call 0x739000
// 00979afd  6830889800           push 0x988830
// 00979b02  e822aee7ff           call 0x7f4929
// 00979b07  59                   pop ecx
// 00979b08  c3                   ret 

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

static Desc desc("location", "Goals", 356, 15, 0);
