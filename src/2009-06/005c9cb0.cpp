// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)

class sp_counted_base
{
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
private:
    long use_count_;
    long weak_count_;
};

template <class T>
class shared_ptr
{
public:
    ~shared_ptr() { if (pn) pn->release(); }
    T* operator->() const { return px; }
private:
    T* px;
    sp_counted_base* pn;
};

namespace RBX {
struct Settings
{
    char pad[0x2c];
    int handle;
};

shared_ptr<Settings> getSettings();
bool queryValue(int handle, double& value);

double getValue()
{
    double value;
    queryValue(getSettings()->handle, value);
    return value;
}
}
