// from server: 100% by king_originala
#include <intrin.h>
// from server: 89% by colin
// from server: 86% by colin
extern char sourceType;
extern char targetType;

struct S {
    char padding0[0x104];
    void* parent;
    char padding1[0x48];
    int value;

    int f();
};

extern "C" S* __cdecl runtimeCast(void*, int, void*, void*, int);

int S::f()
{
    int state=value;
    _ReadWriteBarrier();
    if (state)
        return state;

    void* current=parent;
    _ReadWriteBarrier();
    S* cast = runtimeCast(current, 0, &sourceType, &targetType, 0);
    if (cast) {
        void* p = parent;
        if (runtimeCast(p, 0, &sourceType, &targetType, 0)->f())
            return 1;
    }

    return 0;
}
