// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Sink {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void notify(void* object, unsigned char* value);
};
extern Sink* g_sink;
struct BodyMover {
    void f();
};
void BodyMover::f()
{
    unsigned char value = 0;
    void* object = 0;
    if (this != 0)
        object = (char*)this + 0x1c;
    g_sink->notify(object, &value);
}