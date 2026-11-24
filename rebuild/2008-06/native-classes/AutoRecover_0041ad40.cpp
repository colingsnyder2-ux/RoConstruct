// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

// INFERRED: func_006a0920 is called with one argument (push 4 / add esp,4) and behaves like operator new.
extern "C" void* fn_006a0920(unsigned int size);

namespace boost { namespace signals { namespace detail {

struct slot_base {
    struct data_t {
        // INFERRED: heap block of 4 bytes holding a back-pointer to the owning data_t.
        struct Holder {
            void* owner;
            Holder(void* o) : owner(o) {}
            static void* operator new(unsigned int sz) {
                return fn_006a0920(sz);
            }
            static void operator delete(void* p) {
                ::operator delete(p);
            }
        };

        // INFERRED: stand-in for std::vector<const trackable*> bound_objects (0xc..0x14).
        struct Vec {
            void* first;
            void* last;
            void* end;
            Vec() : first(0), last(0), end(0) {}
        };

        Holder* holder;      // 0x00
        int     pad4;        // 0x04
        int     pad8;        // 0x08
        Vec     bound;       // 0x0c
        int     pad18;       // 0x18
        int     f1c;         // 0x1c
        int     f20;         // 0x20
        bool    f24;         // 0x24

        data_t();
    };
};

// INFERRED: the new-expression is evaluated first (member 0), then the remaining members are cleared.
slot_base::data_t::data_t()
    : holder(new Holder(this)), bound(), f1c(0), f20(0), f24(false)
{
}

}}} // namespace boost::signals::detail
