// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Count
{
    unsigned int pi;
    Count() : pi(0) {}
    Count(const Count& o) : pi(o.pi) {}
    ~Count() {}
};

struct Result
{
    unsigned int px;
    Count pn;

    Result() : px(0), pn() {}
};

struct Source
{
    Result get();
};

struct S
{
    unsigned char padding[0x54];
    Source* source;

    void baseCall();
    void consume(Result value);
    void f();
};

void S::f()
{
    baseCall();
    if (source)
        consume(source->get());
    else
        consume(Result());
}
