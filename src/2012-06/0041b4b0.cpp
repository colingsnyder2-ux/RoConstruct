// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <algorithm>
struct VTB { void* invoker; void (*clear)(char*); void (*copy)(const char*, char*); };
struct Fn {
    VTB* vt;
    char buf[0x3c];
    Fn& operator=(const Fn& o) {
        if (&o != this) {
            if (vt) { vt->clear(buf); vt = 0; }
            if (o.vt) { o.vt->copy(o.buf, buf); vt = o.vt; }
        }
        return *this;
    }
};
struct Elem { int tag; Fn f; };
void fill_elems(Elem* first, Elem* last, const Elem& v) { std::fill(first, last, v); }
