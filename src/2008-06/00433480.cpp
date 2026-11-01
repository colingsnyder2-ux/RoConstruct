// from server: 100% by king_originala
struct Base
{
    virtual ~Base();
    char padding[0x54];
};

struct Member
{
    char storage[0x118];
    ~Member();
};

struct CObjectBrowser : Base
{
    Member first;
    Member second;
    virtual ~CObjectBrowser();
};

CObjectBrowser::~CObjectBrowser()
{
}
