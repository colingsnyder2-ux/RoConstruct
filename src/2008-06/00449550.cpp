// from server: 100% by king_originala
struct Window {
    char reserved[32];
    void* handle;
};

struct Object {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual Window* window();
};

extern "C" Object* __stdcall getObject();
extern "C" int (__stdcall *FlashWindow)(void*, int);
extern "C" void __stdcall notify(unsigned int, unsigned int, int);
extern "C" void __stdcall finish(int);

void __stdcall function(int, int)
{
    Object* p = getObject();
    if (p && p->window()) {
        p = getObject();
        Window* w = p ? p->window() : 0;
        FlashWindow(w->handle, 0);
        notify(196, 0, -1);
    }
    finish(0);
}
