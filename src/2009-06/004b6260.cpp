// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
#include <new>

struct Functor {
    union { char buf[8]; char* ptr; };
    unsigned int size;
    int extra;
    const char* data() const { return size > 8 ? ptr : buf; }
    __forceinline Functor(const Functor& o) : size(o.size)
    {
        ptr = 0;
        char* d;
        const char* src;
        if (size <= 8) {
            d = buf;
            src = o.buf;
        } else {
            d = ptr = (char*)operator new(size);
            src = o.ptr;
        }
        memcpy(d, src, size);
        extra = o.extra;
    }
    ~Functor()
    {
        if (size > 8 && ptr)
            operator delete(ptr);
    }
};

struct true_ {};
struct function_obj_tag {};
union function_buffer { void* obj_ptr; double align; char data[16]; };

inline bool has_empty_target(...) { return false; }

struct basic_vtable0 {
    void assign_functor(Functor f, function_buffer& functor, true_);
    bool assign_to(Functor f, function_buffer& functor, function_obj_tag);
};

bool basic_vtable0::assign_to(Functor f, function_buffer& functor, function_obj_tag)
{
    if (!has_empty_target(&f)) {
        assign_functor(f, functor, true_());
        return true;
    } else {
        return false;
    }
}
