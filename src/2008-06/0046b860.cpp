// from server: 100% by Gemini
// from server: 99% by king_originala
// roc 2008-06 0046b860  unit: VCWorkspace::?$CComObject  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046b860

struct Dummy {
    ~Dummy();
    void g();
};

inline void swallow(bool b)
{
    if (b) {
        Dummy d;
        d.g();
    }
}

struct Context {
    void* get();
};

struct PointerVector {
    void* begin;
    void* end;
    void* capacity;

    void resize(unsigned int count);
};

struct Writer {
    PointerVector values;
    char storage[64];

    Writer(void* context, void* argument);
    ~Writer();
};

struct S {
    char padding[36];
    Context* context;

    int f(unsigned int count, void* argument);
};

int S::f(unsigned int count, void* argument)
{
    swallow(false);
    Writer writer(context ? context->get() : 0, argument);
    writer.values.resize(count);
    return 0;
}
