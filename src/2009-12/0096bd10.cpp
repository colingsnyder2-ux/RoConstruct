// from server: 100% by nuck16
// roc 2009-12 0096bd10  unit: seg_00960000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096bd10
//
// 0096bd10  6a01                 push 1
// 0096bd12  6828b19b00           push 0x9bb128
// 0096bd17  6834b19b00           push 0x9bb134
// 0096bd1c  6828010000           push 0x128
// 0096bd21  b980e8b700           mov ecx, 0xb7e880
// 0096bd26  e8b5deb9ff           call 0x509be0
// 0096bd2b  68b0f39700           push 0x97f3b0
// 0096bd30  e8f48be8ff           call 0x7f4929
// 0096bd35  59                   pop ecx
// 0096bd36  c3                   ret 

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

static Desc desc(296, "CharacterRemoving", "character", 1);
