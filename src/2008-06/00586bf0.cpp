// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_script_2a3db53217189045.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct Script;
struct Source { Script* resolve(); };
struct Script {
    void method_005ad030(Script* other);
    boost::shared_ptr<void> method_00586b10();
    void target(Source* a, void* b);
};
void Script::target(Source* a, void* b) {
    if (a) {
        Script* r = a->resolve();
        if (r) r->method_005ad030(this);
    }
    if (b) method_00586b10();
}
