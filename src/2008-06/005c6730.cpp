// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Primary {
    virtual void first();
};

struct Secondary {
    virtual void second();
};

struct CursorBase : Primary, Secondary {
    char reserved[64];
    CursorBase(void*);
};

struct Cursor : CursorBase {
    Cursor(void*);
    virtual void first();
    virtual void second();
};

inline Cursor::Cursor(void* context) : CursorBase(context)
{
}

struct Tool {
    char reserved[24];
    void* context;
    Cursor* createCursor();
};

Cursor* Tool::createCursor()
{
    return new Cursor(context);
}
