// from server: 100% by king_originala
struct Interface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void apply(void*, void*);
};

struct Context {
    Interface* object;
    char* value;
};

void __cdecl invoke(Context* context, char* value)
{
    void* adjusted = value ? value + 20 : 0;
    context->object->apply(context->value ? context->value + 20 : 0, adjusted);
}
