// from server: 100% by nuck16
// roc 2009-12 0096ec00  unit: seg_00960000  size: 45 bytes
//
// 0096ec00  6a01                 push 1
// 0096ec02  6a04                 push 4
// 0096ec04  6840c09c00           push 0x9cc040
// 0096ec09  33c9                 xor ecx, ecx
// 0096ec0b  6834c09c00           push 0x9cc034
// 0096ec10  51                   push ecx
// 0096ec11  b870286300           mov eax, 0x632870
// 0096ec16  50                   push eax
// 0096ec17  b96051b800           mov ecx, 0xb85160
// 0096ec1c  e89f64ccff           call 0x6350c0
// 0096ec21  6870199800           push 0x981970
// 0096ec26  e8fe5ce8ff           call 0x7f4929
// 0096ec2b  59                   pop ecx
// 0096ec2c  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};


struct Desc
{
    Desc(void (Owner::*)(), const char *, const char *, int, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "GetDebugId", "scopeLength", 4, 1);
