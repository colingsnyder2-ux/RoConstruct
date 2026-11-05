// from server: 100% by nuck16
// roc 2009-12 0096ea80  unit: seg_00960000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ea80
//
// 0096ea80  33c9                 xor ecx, ecx
// 0096ea82  51                   push ecx
// 0096ea83  51                   push ecx
// 0096ea84  68c4bf9c00           push 0x9cbfc4
// 0096ea89  68e01d9b00           push 0x9b1de0
// 0096ea8e  68b4bf9c00           push 0x9cbfb4
// 0096ea93  51                   push ecx
// 0096ea94  b800446300           mov eax, 0x634400
// 0096ea99  50                   push eax
// 0096ea9a  b96855b800           mov ecx, 0xb85568
// 0096ea9f  e88c5dccff           call 0x634830
// 0096eaa4  6850189800           push 0x981850
// 0096eaa9  e87b5ee8ff           call 0x7f4929
// 0096eaae  59                   pop ecx
// 0096eaaf  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, const char *, int, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "FindFirstChild", "name", "recursive", 0, 0);
