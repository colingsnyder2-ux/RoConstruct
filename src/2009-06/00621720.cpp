// from server: 98% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_041ca97d6aee7a6d.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/shared_ptr.hpp>
typedef std::vector<boost::shared_ptr<void> > Arguments;
struct Bounds {
    float values[6];
};
struct Result {
    void finish();
};
struct Camera { unsigned int c; };
struct Target {
    virtual void unused();
    virtual Result* update(const Bounds&, Camera*, int);
};
struct Root {
    char padding[0x118];
    Target target;
    char gap[0x24];
    Camera camera;
    void apply(void*, Arguments*);
    void collect(void*, Arguments*, void*, bool);
    void run(void*, void*, bool);
};
extern void* __cdecl getCharacter(Root*);
extern void __cdecl calculateBounds(Bounds*, Arguments*);
void Root::run(void* argument, void* extra, bool skip)
{
    Arguments arguments;
    if (getCharacter(this))
        apply(argument, &arguments);
    else
        collect(argument, &arguments, extra, skip);
    if (!skip && arguments.size() > 0) {
        Bounds bounds;
        calculateBounds(&bounds, &arguments);
        target.update(bounds, &camera, 1)->finish();
    }
}
