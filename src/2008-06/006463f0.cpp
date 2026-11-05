// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_contextnonvolatile25f911d76fa7d3de.cpp

// Candidate translation unit (score above; library headers required).
struct Context {
    void update(void* item, bool enabled);
};

struct Object {
    virtual void reserved();
    virtual int kind();
    Object* parent;
    unsigned int padding;
    Context* context;
};

struct S {
    unsigned int padding0;
    Object* object;
    unsigned int padding8;
    void* first;
    void* second;
    char padding14[176];
    float value;

    double evaluate(int argument);
    void f(int argument);
};

void S::f(int argument)
{
    if ((value = evaluate(argument)) != 0.0f) {
        Context* context;
        if (!object) {
            context = 0;
        } else {
            Object* source;
            if (object->kind() != 7)
                source = object;
            else
                source = object->parent;
            context = source->context;
        }
        context->update(first, true);
        context->update(second, true);
    }
}