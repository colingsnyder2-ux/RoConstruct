// from server: 100% by king_originala
struct Base_00424510 {
    char storage[0x98];
    ~Base_00424510();
};

struct Aggregate_00424510 {
    char storage[0x24];
    ~Aggregate_00424510();
};

struct MemberBase_00424510 {
    virtual ~MemberBase_00424510();
};

struct Member_00424510 : MemberBase_00424510 {
    char storage[4];
    ~Member_00424510();
};

struct Resource_00424510 {
    void *object;
    bool criticalSection;
    ~Resource_00424510();
};

struct S_00424510 : Base_00424510 {
    Aggregate_00424510 aggregate;
    Member_00424510 member;
    Resource_00424510 resource;
    ~S_00424510();
};

S_00424510::~S_00424510()
{
}
