// from server: 100% by king_originala
struct Property;
extern Property property9762ec;
extern Property property9760a8;
extern Property property97603c;

struct RenderState {
    char data[16];
    void shouldRenderSetDirty();
};

struct Controller {
    char data[4];
    void setMode(int value);
};

struct Part {
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
    virtual void changed();

    char padding04[0x1c8];
    RenderState renderState;
    int mode;
    int enabled;
    char padding1e4[0x44];
    Controller controller;
    char padding22c[0x16c];
    bool dirty;

    void raisePropertyChanged(const Property& property);
    void setMode(int value);
};

void Part::setMode(int value)
{
    if (mode != value) {
        mode = value;
        controller.setMode(value == 1 ? 2 : 1);

        if (mode != 1 && enabled != 0) {
            enabled = 0;
            raisePropertyChanged(property9762ec);
        }

        raisePropertyChanged(property9760a8);
        raisePropertyChanged(property97603c);
        dirty = true;
        renderState.shouldRenderSetDirty();
        changed();
    }
}
