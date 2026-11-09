// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

extern "C" int (__cdecl *sprintf)(char*, const char*, ...);
extern const char text_0080b716[];

struct Count
{
    virtual ~Count();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
    void release();
};

inline void Count::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Editor
{
    char padding[0x1f0];
    int active;
    int get();
};

struct Object
{
    Editor* getEditor();
};

struct ReturnedShared
{
    Object* object;
    Count* count;
    ~ReturnedShared();
};

struct Shared
{
    Object* object;
    Count* count;
    Shared(const ReturnedShared&);
    ~Shared();
    Editor* getEditor() const;
};

inline ReturnedShared::~ReturnedShared()
{
    if (count)
        count->release();
}

inline Shared::Shared(const ReturnedShared& other)
    : object(other.object), count(other.count)
{
    if (count)
        _InterlockedIncrement(&count->strong);
}

inline Shared::~Shared()
{
    if (count)
        count->release();
}

inline Editor* Shared::getEditor() const
{
    return object ? object->getEditor() : 0;
}

struct Provider
{
    ReturnedShared get();
};

struct Guard
{
    char storage[12];
    Guard(Shared);
    ~Guard();
};

struct UI
{
    virtual void enable(int) = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void setText(const char*) = 0;
};

struct S
{
    char padding[0x94];
    Provider* provider;
    Shared getObject();
    void f(UI*);
};

void S::f(UI* ui)
{
    Guard guard(provider->get());
    Editor* editor = getObject().getEditor();

    if (editor && editor->active)
    {
        char text[32];
        sprintf(text, "%d threads", editor->get());
        ui->setText(text);
        ui->enable(1);
    }
    else
    {
        ui->setText(text_0080b716);
        ui->enable(0);
    }
}
