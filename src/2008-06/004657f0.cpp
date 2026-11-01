// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control
{
    long unused;
    volatile long references;
};

struct Shared
{
    void* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->references);
}

struct Document
{
    char padding[0x54];
    Shared value;
};

struct CScriptEditor
{
    char padding[0x54];
    Document* document;

    void consume(Shared);
    void notify(int, int, int);
};

void CScriptEditor::notify(int, int event, int)
{
    if (event == 1)
        consume(document->value);
}
