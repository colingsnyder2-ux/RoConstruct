// from server: 100% by nuck16
// roc 2009-12 0096c7a0  unit: seg_00960000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c7a0
//
// 0096c7a0  6a01                 push 1
// 0096c7a2  68b8b89b00           push 0x9bb8b8
// 0096c7a7  6878b99b00           push 0x9bb978
// 0096c7ac  6874010000           push 0x174
// 0096c7b1  b9a8efb700           mov ecx, 0xb7efa8
// 0096c7b6  e8650ebbff           call 0x51d620
// 0096c7bb  68b0fc9700           push 0x97fcb0
// 0096c7c0  e86481e8ff           call 0x7f4929
// 0096c7c5  59                   pop ecx
// 0096c7c6  c3                   ret 

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
    Desc(int, const char *, const char *, int);
    ~Desc();
};

static Desc desc(372, "PlayerRemoving", "player", 1);
