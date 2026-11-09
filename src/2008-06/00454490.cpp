// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_docguard_dfb32bd0207cbfab.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct State
{
    unsigned char padding[0x138];
    int enabled;
};

struct Object
{
    State* getState();
};

struct Result : boost::shared_ptr<Object> {
    State* getState() const { return get() ? get()->getState() : 0; }
};
typedef boost::shared_ptr<Object> Pair;

struct Source
{
    Result get();
};

struct Guard
{
    unsigned char storage[12];
    Guard(Pair value);
    ~Guard();
};

struct Callback
{
    virtual void setEnabled(int value);
};

struct S
{
    unsigned char padding[0x94];
    Source* source;
    Result get();
    void f(Callback* callback);
};

void S::f(Callback* callback)
{
    Guard guard(source->get());

    State* state = get().getState();

    int enabled;
    if (state && state->enabled)
        enabled = 1;
    else
        enabled = 0;

    callback->setEnabled(enabled);
}
