// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Primary {
    virtual void primary();
};

struct Secondary {
    virtual void secondary();
};

struct Base : Primary, Secondary {
    char padding[28];
    Base(void*);
};

struct Cursor : Base {
    Cursor(void*);
    virtual void primary();
    virtual void secondary();
};

__forceinline Cursor::Cursor(void* p) : Base(p) {}

struct Context {
    char padding[0x204];
    void* value;
};

struct Tool {
    char padding[0x0c];
    Context* context;
    Cursor* f();
};

Cursor* Tool::f() {
    return new Cursor(context->value);
}
