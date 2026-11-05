// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_rootvector_d43a930ba32a87b4.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/shared_ptr.hpp>
typedef std::vector<boost::shared_ptr<void> > Arguments;
struct Bounds {
    float values[6];

    Bounds() {}
    Bounds(const Bounds& b) {
        values[0] = b.values[0];
        values[1] = b.values[1];
        values[2] = b.values[2];
        values[3] = b.values[3];
        values[4] = b.values[4];
        values[5] = b.values[5];
    }
};

struct Result {
    void finish();
};

struct Target {
    virtual void unused();
    virtual Result* update(Bounds, void*, int);
};

struct Root {
    char padding[0x288];
    Target target;
    char gap[0x48];
    unsigned int context;

    void apply(void*, Arguments*);
    void collect(void*, Arguments*, void*);
    void run(void*, void*);
};

extern void* __cdecl getCharacter(Root*);
extern void __cdecl calculateBounds(Bounds*, Arguments*);

void Root::run(void* argument, void* extra)
{
    Arguments arguments;

    if (getCharacter(this))
        apply(argument, &arguments);
    else
        collect(argument, &arguments, extra);

    if (arguments.size() > 0) {
        Bounds bounds;
        calculateBounds(&bounds, &arguments);
        target.update(bounds, &context, 1)->finish();
    }
}