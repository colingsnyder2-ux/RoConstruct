// from server: 100% by king_originala
void __cdecl operator delete(void*);

struct Base {
    char padding[0x58];
    ~Base();
};

struct Member {
    ~Member();
};

struct BaseCleanup {
    Base* object;
    BaseCleanup(Base* p);
    ~BaseCleanup();
};

inline BaseCleanup::BaseCleanup(Base* p) : object(p)
{
}

inline BaseCleanup::~BaseCleanup()
{
    object->Base::~Base();
}

struct CWrapperView : Base {
    Member member;
    void* destroy(unsigned int flags);
};

void* CWrapperView::destroy(unsigned int flags)
{
    {
        BaseCleanup cleanup(this);
        member.~Member();
    }

    if (flags & 1)
        operator delete(this);

    return this;
}
