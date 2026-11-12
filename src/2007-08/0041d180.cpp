// from server: 100% by EspClaude
// from server: 84% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-lib: openrbx-client-dll roc_claude_bbe8b55c4372bac9.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;

struct Context {
    char padding[0x104];
    std::vector<Shared>* entries;
    Shared get();
};

struct Parent {
    char padding[0x188];
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
    int count = context->entries->size();

    if (count == 1) {
        void* result = context->get().get();
        return result;
    }

    if (count == 0)
        return parent->fallback;

    return 0;
}
