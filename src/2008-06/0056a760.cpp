// from server: 100% by tester
#include <intrin.h>
struct Cnt { void* vt; long use; void add() { _InterlockedIncrement(&use); } };
struct Obj { int rc; };
struct SP {
    Obj* px; Cnt* pn;
    SP(const SP& o);
};
SP::SP(const SP& o) {
    px = o.px;
    pn = o.pn;
    if (pn) pn->add();
    ++px->rc;
}
