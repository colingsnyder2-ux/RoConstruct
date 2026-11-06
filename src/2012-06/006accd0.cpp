// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct sp_counted_base
{
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count;
    long weak_count;

    void release()
    {
        if (_InterlockedDecrement(&use_count) == 0)
        {
            dispose();
            if (_InterlockedDecrement(&weak_count) == 0)
                destroy();
        }
    }
};

struct SharedPtr
{
    void* px;
    sp_counted_base* pn;
    ~SharedPtr()
    {
        if (pn != 0)
            pn->release();
    }
};

struct String;
typedef void (String::*StringDtorFn)();
extern StringDtorFn String_dtor_imp;

struct String
{
    char buf[28];
    void destroy_imp();
    ~String()
    {
        (this->*String_dtor_imp)();
    }
};

class __multiple_inheritance Target;

typedef void (Target::*TargetMethod)(const SharedPtr&, const String&, const SharedPtr&);

struct BoundCall
{
    TargetMethod method;
    Target* obj;
};

void invoke(BoundCall* buf, SharedPtr a, String s, SharedPtr b);

void invoke(BoundCall* buf, SharedPtr a, String s, SharedPtr b)
{
    Target* o = buf->obj;
    (o->*buf->method)(a, s, b);
}
