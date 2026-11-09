// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
struct sp_counted { virtual void dispose(); long use_count; long weak_count; void add_ref_copy() { _InterlockedIncrement(&use_count); } };
template<class T> struct shared_ptr {
    T* px; sp_counted* pn;
    shared_ptr(const shared_ptr& o) : px(o.px), pn(o.pn) { if (pn) pn->add_ref_copy(); }
    ~shared_ptr();
};
struct Channel;
shared_ptr<Channel>& getChannel();
int getLevel(shared_ptr<Channel>& c);
void setLevel(shared_ptr<Channel>& c, shared_ptr<Channel> c2, int level, int flag);
struct LevelHolder {
    int level;
    void apply();
};
void LevelHolder::apply()
{
    int l = level;
    shared_ptr<Channel>& c = getChannel();
    if (getLevel(c) != l)
        setLevel(c, c, l, 1);
}
