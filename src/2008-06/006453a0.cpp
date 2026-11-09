// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_statetransitionflow_aa212893bcc92d75.cpp

// Candidate translation unit (score above; library headers required).
#include <memory>
struct State {
    virtual void v0();
    virtual void v1();
    virtual int kind();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual ~State();

    int reserved;
    void* context;

    bool accepts(int index);
    void update(float value);
};

struct Configuration {
    char reserved[0x13a];
    unsigned char enabled;
};

extern Configuration* __cdecl configuration();
extern State* __cdecl createState(int kind, void* context);
extern int transitions[][18];

void __cdecl transition(std::auto_ptr<State>* current, float value)
{
    int oldKind = (*current)->kind();
    int nextKind;
    int i;

    for (i = 0; i < 17; ++i) {
        if (configuration()->enabled)
            nextKind = 7;
        else {
            nextKind = transitions[oldKind][i];
            if (nextKind == 13)
                continue;
        }

        if (nextKind != oldKind && (*current)->accepts(i))
            goto changeState;
    }

    return;
changeState:

    void* context = (*current)->context;
    current->reset();

    State* replacement = createState(nextKind, context);
    current->reset(replacement);
    replacement->update(value);
}
