// from server: 100% by king_originala
extern void (__thiscall *destroyString)(void *);

void __cdecl operator delete(void *);

struct Base
{
    virtual ~Base();
    char storage[0xa0];
};

struct Member
{
    char storage[0x4c];
    ~Member();
};

struct String
{
    char storage[0x1c];
    ~String();
};

inline String::~String()
{
    destroyString(this);
}

struct Document
{
    ~Document();
};

struct CRobloxModule : Base
{
    Member member;
    String text;
    Document *document;

    virtual ~CRobloxModule();
};

CRobloxModule::~CRobloxModule()
{
    delete document;
}
