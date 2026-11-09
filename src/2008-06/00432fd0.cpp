// from server: 100% by king_originala
struct Object
{
    void release();
};

struct Base
{
    virtual ~Base();
    char padding[0xe4];
};

struct CBrowserFrameWnd : Base
{
    Object* object;
    ~CBrowserFrameWnd();
};

CBrowserFrameWnd::~CBrowserFrameWnd()
{
    if (object)
        object->release();
}
