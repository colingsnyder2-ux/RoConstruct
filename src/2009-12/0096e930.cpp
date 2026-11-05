// from server: 100% by nuck16
// roc 2009-12 0096e930  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096e930
//
// 0096e930  6a00                 push 0
// 0096e932  6a0f                 push 0xf
// 0096e934  68a6000000           push 0xa6
// 0096e939  6818bc9c00           push 0x9cbc18
// 0096e93e  6844bc9c00           push 0x9cbc44
// 0096e943  b9484ab800           mov ecx, 0xb84a48
// 0096e948  e8f30dccff           call 0x62f740
// 0096e94d  68e0139800           push 0x9813e0
// 0096e952  e8d25fe8ff           call 0x7f4929
// 0096e957  59                   pop ecx
// 0096e958  c3                   ret 

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

static Desc desc("IsFmodProfilingEnabled", "Benchmarking", 166, 15, 0);
