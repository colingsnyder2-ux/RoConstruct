// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
struct SharedCount {
    sp_counted_base* pi_;
    ~SharedCount() { if (pi_ != 0) pi_->release(); }
};
struct Shared { void* px; SharedCount pn; };
class connection {
public:
    void disconnect() const;
    ~connection();
    int a; void* b;
};
class scoped_connection : public connection {
public:
    ~scoped_connection() { disconnect(); }
};
struct Base {
    virtual ~Base();
    void cleanup(int);
    char storage[0x264];
};
struct S : Base {
    Shared shared;
    scoped_connection conn;
    virtual ~S();
};
S::~S()
{
    cleanup(0);
}
