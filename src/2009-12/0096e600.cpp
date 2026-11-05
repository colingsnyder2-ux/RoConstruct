// from server: 100% by nuck16
// roc 2009-12 0096e600  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096e600
//
// 0096e600  6a00                 push 0
// 0096e602  6a0f                 push 0xf
// 0096e604  68a5000000           push 0xa5
// 0096e609  6858bb9c00           push 0x9cbb58
// 0096e60e  6844bb9c00           push 0x9cbb44
// 0096e613  b94c49b800           mov ecx, 0xb8494c
// 0096e618  e82311ccff           call 0x62f740
// 0096e61d  6820169800           push 0x981620
// 0096e622  e80263e8ff           call 0x7f4929
// 0096e627  59                   pop ecx
// 0096e628  c3                   ret 

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

static Desc desc("ReportSoundWarnings", "Errors", 165, 15, 0);
