// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_stateiterationfbbd2f0dbb9894a6.cpp

// Candidate translation unit (score above; library headers required).

extern "C" void (__cdecl* const invalidParameter)();

struct Flag {
    bool value;
    Flag(bool v);
    Flag(const Flag& other):value(other.value){}
};

inline Flag::Flag(bool v) : value(v)
{
}

struct Iteration {
    unsigned int index;
    unsigned int count;
    Iteration* previous;
};

struct Descriptor {
    unsigned char padding[16];
    void** first;
    void** last;
    void** capacity;
    Iteration* active;

    void visit(Flag value, void* entry);
    void apply(Flag value);
};

void Descriptor::apply(Flag value)
{
    Iteration iteration = {
        0,
        static_cast<unsigned int>(last - first),
        active
    };

    active = &iteration;

    if (iteration.index < iteration.count) {
        void (__cdecl* handler)() = invalidParameter;
        do {
            unsigned int index = iteration.index;
            if (index >= static_cast<unsigned int>(last - first))
                handler();

            visit(Flag(value.value), first[index]);
            ++iteration.index;
        } while (iteration.index < iteration.count);
    }

    active = iteration.previous;
}