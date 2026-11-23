// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: self-contained minimal boost 1.3x sp_counted_base layout (vtbl dtor/dispose/destroy, use_count +4, weak_count +8) taken from the disassembly.
#include <intrin.h>

class ChatEnter;

namespace boost {

namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }

    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) {
            destroy();
        }
    }

    long use_count_;
    long weak_count_;
};
}

template<class T>
class shared_ptr {
public:
    ~shared_ptr();
    T* px;
    detail::sp_counted_base* pn;
};

template<class T>
shared_ptr<T>::~shared_ptr() {
    if (pn) {
        pn->release();
    }
}

template class shared_ptr<ChatEnter>;

}
