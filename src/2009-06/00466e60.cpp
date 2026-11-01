// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
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
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    ~shared_ptr() { if (pn) pn->release(); }
};
}
namespace rbx { namespace signals {
class connection {
public:
    void* px;
    void* pn;
    ~connection();
    void disconnect() const;
};
class scoped_connection : public connection {
public:
    ~scoped_connection() { disconnect(); }
};
} }
class CXTCaptionBase { public: virtual ~CXTCaptionBase(); char pad[0x50]; };
class CXTThemeManagerStyleHost { public: virtual ~CXTThemeManagerStyleHost(); char pad[0x138]; };
class CXTCaption : public CXTCaptionBase, public CXTThemeManagerStyleHost { public: virtual ~CXTCaption(); };
class ActiveDocView { public: virtual ~ActiveDocView(); };
class A; class B;
class CSelectionCaption : public CXTCaption, public ActiveDocView {
public:
    boost::shared_ptr<A> a;
    boost::shared_ptr<B> b;
    rbx::signals::scoped_connection connection;
    virtual ~CSelectionCaption();
};
CSelectionCaption::~CSelectionCaption() {}
