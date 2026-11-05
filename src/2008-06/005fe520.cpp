// from server: 73% by king_originala
struct Base
{
    unsigned char data[0x1A0];
    ~Base();
};

struct MemberA
{
    unsigned long table;
    unsigned char data[12];
    ~MemberA();
};

struct MemberB
{
    unsigned long table;
    unsigned char data[12];
    ~MemberB();
};

struct ThreadRef
{
    unsigned char data[20];
    ~ThreadRef();
};

struct S : Base
{
    MemberA a;
    MemberB b;
    unsigned long *virtualTable;
    unsigned char padding[0x40];
    ThreadRef ref0;
    ThreadRef ref1;
    ThreadRef ref2;
    ThreadRef ref3;
    ThreadRef ref4;
    ~S();
};

S::~S()
{
    *reinterpret_cast<unsigned long *>(data + 0x130) = 0x008419C4;
    a.table = 0x008419BC;
    b.table = 0x008419A4;

    unsigned long offset = virtualTable[1];
    *reinterpret_cast<unsigned long *>(
        reinterpret_cast<unsigned char *>(this) + 0x1C0 + offset
    ) = 0x0084199C;

    offset = virtualTable[1];
    *reinterpret_cast<unsigned long *>(
        reinterpret_cast<unsigned char *>(this) + 0x1BC + offset
    ) = offset - 0xAC;
}
