// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_insertget_0d7f4b9e0fa30ebc.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;

struct Entries {
    char padding[12];
    Shared* begin;
    Shared* end;
};

struct Context {
    char padding[0x154];
    Entries* entries;
    Shared get();
};

struct Parent {
    char padding[0x204];
    void* fallback;
    Context* getContext();
};

struct InsertService {
    char padding[12];
    Parent* parent;
    void* get();
};

void* InsertService::get()
{
    Context* context = parent ? parent->getContext() : 0;
    int count = context->entries->end - context->entries->begin;

    if (count == 1) {
        void* result = context->get().get();
        return result;
    }

    if (count == 0)
        return parent->fallback;

    return 0;
}