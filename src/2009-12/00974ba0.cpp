// from server: 100% by nuck16
// roc 2009-12 00974ba0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974ba0
//
// 00974ba0  6a00                 push 0
// 00974ba2  6a0f                 push 0xf
// 00974ba4  68a0000000           push 0xa0
// 00974ba9  6820d89a00           push 0x9ad820
// 00974bae  68f8739d00           push 0x9d73f8
// 00974bb3  b99c24b900           mov ecx, 0xb9249c
// 00974bb8  e8e31ad5ff           call 0x6c66a0
// 00974bbd  68005c9800           push 0x985c00
// 00974bc2  e862fde7ff           call 0x7f4929
// 00974bc7  59                   pop ecx
// 00974bc8  c3                   ret 

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

static Desc desc("SoundEnabled", "Sound", 160, 15, 0);
