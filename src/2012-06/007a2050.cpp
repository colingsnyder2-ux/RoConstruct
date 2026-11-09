// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Name;
struct Controller;

const Name& getLocalScope();

struct CountedBase
{
    long use_count;
    long weak_count;
    virtual ~CountedBase();
    virtual void dispose() = 0;
    virtual void destroy();
};

struct SharedPtr
{
    Controller* px;
    CountedBase* pi;
    ~SharedPtr()
    {
        CountedBase* p = pi;
        if (p)
        {
            if (_InterlockedDecrement(&p->use_count) == 0)
            {
                p->dispose();
                if (_InterlockedDecrement(&p->weak_count) == 0)
                    p->destroy();
            }
        }
    }
};

SharedPtr shared_from(Controller* c);

struct WeakPtr
{
    Controller* px;
    CountedBase* pi;
    WeakPtr() : px(0), pi(0) {}
    ~WeakPtr();
    void assign(const SharedPtr& r)
    {
        px = r.px;
        CountedBase* tmp = r.pi;
        if (tmp != pi)
        {
            if (tmp)
                _InterlockedIncrement(&tmp->weak_count);
            CountedBase* old = pi;
            if (old)
            {
                if (_InterlockedDecrement(&old->weak_count) == 0)
                    old->destroy();
            }
            pi = tmp;
        }
    }
};

struct StdString
{
    char buf[0x1c];
    StdString();
    ~StdString();
    void construct();
};

extern void (StdString::*imp_string_ctor)();

inline StdString::StdString()
{
    (this->*imp_string_ctor)();
}

struct ContentId
{
    StdString id;
    const Name* mime;
    ContentId() : mime(&getLocalScope()) {}
};

struct GuiDrawImage
{
    char data[0x84];
    GuiDrawImage();
    ~GuiDrawImage();
};

struct B0 { virtual ~B0(); };
struct B1 { virtual ~B1(); char d[0x10]; };
struct B2 { virtual ~B2(); };
struct B3 { virtual ~B3(); char d[0x60]; };
struct B4 { virtual ~B4(); char d[0x14]; };

struct Widget : B0, B1, B2, B3, B4
{
    Widget();
    virtual ~Widget();
};

struct ButtonBindingWidget : Widget
{
    GuiDrawImage guiImageDraw;
    ContentId textureId;
    int button;
    WeakPtr controller;

    ButtonBindingWidget(int button, Controller* c);
    virtual ~ButtonBindingWidget();
};

ButtonBindingWidget::ButtonBindingWidget(int b, Controller* c)
    : button(b)
{
    controller.assign(shared_from(c));
}
