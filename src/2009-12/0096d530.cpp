// from server: 100% by nuck16
// roc 2009-12 0096d530  unit: seg_00960000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d530
//
// 0096d530  6a01                 push 1
// 0096d532  684ce39b00           push 0x9be34c
// 0096d537  681cbf9b00           push 0x9bbf1c
// 0096d53c  683ce39b00           push 0x9be33c
// 0096d541  68c0290000           push 0x29c0
// 0096d546  b99807b800           mov ecx, 0xb80798
// 0096d54b  e86073bdff           call 0x5448b0
// 0096d550  6850099800           push 0x980950
// 0096d555  e8cf73e8ff           call 0x7f4929
// 0096d55a  59                   pop ecx
// 0096d55b  c3                   ret 

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

static Desc desc(10688, "Disconnection", "peer", "lostConnection", 1);
