// from server: 100% by tester
extern void (__thiscall *destroy_string)(void *);

struct StringStorage
{
    char storage[32];
    ~StringStorage();
};

inline StringStorage::~StringStorage()
{
    destroy_string(this);
}

struct Member
{
    ~Member();
};

struct S : StringStorage
{
    Member member;
    ~S();
};

S::~S()
{
}
