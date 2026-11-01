// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD /EHsc
#include <intrin.h>
struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
template<class T> struct weak_ptr {
    T* px;
    sp_counted_base* pi;
    ~weak_ptr() { if (pi) pi->weak_release(); }
};
struct Obj;
struct Sub {
    char data[24];
    ~Sub();
};
struct S {
    weak_ptr<Obj> weak;
    Sub sub;
    ~S();
};
S::~S()
{
}
