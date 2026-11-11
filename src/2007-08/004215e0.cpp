// from server: 97% by Intel
﻿// from server: 92% by EspClaude
// roc 2007-08 004215e0  unit: CSelectionTreeCtrl  size: 93 bytes
// 2007-08 hand variant: the target's return object has THREE fields (0, 4 and 8 - the third
// comes from the by-value argument slot), so Function is 12 bytes, not 8.

#include <intrin.h>

struct Control {
    void* first;
    volatile long references;
};

struct Shared
{
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
    {
        volatile long* references = &control->references;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(references, 1);
    }
}

struct Iterator
{
    void* reserved;
    Shared* current;
};

struct Function
{
    void (__cdecl *callback)(void*, Shared);
    void* context;
    int third;

    Function(const Function&);
};

inline Function::Function(const Function& other)
    : callback(other.callback), context(other.context), third(other.third)
{
}

Function __cdecl func_00423ba0(Iterator first, Iterator last, Function function)
{
    Shared* current = first.current;
    Shared* end = last.current;
    for (; current != end; ++current)
        function.callback(function.context, *current);
    return function;
}
