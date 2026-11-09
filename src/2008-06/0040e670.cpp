// from server: 100% by king_originala
// from server: 96% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern "C" int __cdecl lookup(int);
extern "C" int __cdecl validate(int);

struct Control {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void enable(int);

    char padding[0x144];
    int mode;
    char tail[0x94];

    Control(int);
    void setEditable(int);
    void setCaption(const char*);
    void updateMode();
    void setWidth(int);
    __forceinline void setMode(int);
};

__forceinline void Control::setMode(int value)
{
    if (mode != value) {
        mode = value;
        updateMode();
    }
}

struct Request {
    unsigned int code;
    Control* control;
    int enabled;
    int reserved[2];
    int id;
};

struct CBrowserView {
    char padding[0x118];
    Control* control;
    int f(Request*);
};

int CBrowserView::f(Request* volatile input)
{
    Request* request=input;
    if (request->enabled &&
        validate(lookup(request->id)) &&
        request->code == 0x80c9) {
        if (!control)
            control = new Control(0);

        control->setEditable(1);
        control->setCaption("Address");
        control->setMode(1);
        control->setWidth(40);
        control->enable(1);
        request->control = control;
        return 1;
    }
    return 0;
}
