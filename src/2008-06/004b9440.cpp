// from server: 100% by king_originala
struct Base {
    char storage[0x130];
    ~Base();
};

struct MemberA {
    char storage[0x2a24];
    ~MemberA();
};

struct MemberB {
    char storage;
    ~MemberB();
};

struct S : Base {
    MemberA a;
    MemberB b;
    ~S();
};

S::~S()
{
}
