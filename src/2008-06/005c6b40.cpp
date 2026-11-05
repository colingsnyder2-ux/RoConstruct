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
    unsigned char storage[64];
    CursorBase(void*);
};

struct InletCursor : CursorBase {
    InletCursor(void*);
    virtual ~InletCursor();
};

__forceinline InletCursor::InletCursor(void* context)
    : CursorBase(context)
{
}

struct InletTool {
    unsigned char storage[24];
    void* context;
    InletCursor* createCursor();
};

InletCursor* InletTool::createCursor()
{
    return new InletCursor(context);
}
