// from server: 100% by nuck16
// roc 2009-12 00972700  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972700
//
// 00972700  6a01                 push 1
// 00972702  68a0f29c00           push 0x9cf2a0
// 00972707  6898f29c00           push 0x9cf298
// 0097270c  688cf29c00           push 0x9cf28c
// 00972711  68740b0000           push 0xb74
// 00972716  b92005b900           mov ecx, 0xb90520
// 0097271b  e8f0b8cfff           call 0x66e010
// 00972720  68304c9800           push 0x984c30
// 00972725  e8ff21e8ff           call 0x7f4929
// 0097272a  59                   pop ecx
// 0097272b  c3                   ret 

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

static Desc desc(2932, "ItemChanged", "object", "descriptor", 1);
