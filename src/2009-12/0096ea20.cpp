// from server: 100% by nuck16
// roc 2009-12 0096ea20  unit: seg_00960000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ea20
//
// 0096ea20  6a00                 push 0
// 0096ea22  6a0f                 push 0xf
// 0096ea24  6a74                 push 0x74
// 0096ea26  6898bf9c00           push 0x9cbf98
// 0096ea2b  688cbf9c00           push 0x9cbf8c
// 0096ea30  b9d853b800           mov ecx, 0xb853d8
// 0096ea35  e8e655ccff           call 0x634020
// 0096ea3a  68a0179800           push 0x9817a0
// 0096ea3f  e8e55ee8ff           call 0x7f4929
// 0096ea44  59                   pop ecx
// 0096ea45  c3                   ret 

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

static Desc desc("archivable", "Behavior", 116, 15, 0);
