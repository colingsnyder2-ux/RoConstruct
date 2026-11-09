// from server: 100% by nuck16
// roc 2009-12 0096c770  unit: seg_00960000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c770
//
// 0096c770  6a01                 push 1
// 0096c772  68b8b89b00           push 0x9bb8b8
// 0096c777  686cb99b00           push 0x9bb96c
// 0096c77c  6870010000           push 0x170
// 0096c781  b930eeb700           mov ecx, 0xb7ee30
// 0096c786  e8950ebbff           call 0x51d620
// 0096c78b  6890fd9700           push 0x97fd90
// 0096c790  e89481e8ff           call 0x7f4929
// 0096c795  59                   pop ecx
// 0096c796  c3                   ret 

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

static Desc desc(368, "PlayerAdded", "player", 1);
