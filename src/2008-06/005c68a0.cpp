// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct CursorBase : Primary, Secondary {
    char storage[64];
    CursorBase(void*);
};

struct Cursor : CursorBase {
    Cursor(void*);
    virtual ~Cursor();
};

inline Cursor::Cursor(void* value) : CursorBase(value) {}

struct WeldTool {
    char storage[24];
    void* context;
    Cursor* createCursor();
};

Cursor* WeldTool::createCursor()
{
    return new Cursor(context);
}
