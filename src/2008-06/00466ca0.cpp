// from server: 100% by king_originala
struct Base
{
    virtual ~Base();
    char padding[0x70];
};

struct Splitter
{
    char storage[0x11c];
    ~Splitter();
};

struct Member
{
    ~Member();
};

struct CSettingsExplorer : Base
{
    Splitter splitter;
    Member member;
    virtual ~CSettingsExplorer();
};

CSettingsExplorer::~CSettingsExplorer()
{
}
