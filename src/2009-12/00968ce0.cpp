// from server: 100% by nuck16
// roc 2009-12 00968ce0  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968ce0
//
// 00968ce0  6a00                 push 0
// 00968ce2  6a06                 push 6
// 00968ce4  68fc000000           push 0xfc
// 00968ce9  6880aa9a00           push 0x9aaa80
// 00968cee  6888aa9a00           push 0x9aaa88
// 00968cf3  b978afb700           mov ecx, 0xb7af78
// 00968cf8  e883f2adff           call 0x447f80
// 00968cfd  6830e59700           push 0x97e530
// 00968d02  e822bce8ff           call 0x7f4929
// 00968d07  59                   pop ecx
// 00968d08  c3                   ret 

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

static Desc desc("profileName", "Quality", 252, 6, 0);
