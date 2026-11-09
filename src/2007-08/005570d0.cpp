// from server: 100% by tajop
struct Event {
    int type;
};

struct GuiResponse {
    int response;
    void* target;
    GuiResponse() { target = 0; response = 0; }
};

struct GuiBaseA {
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
    virtual bool isVisible();
    char padA[0xe4];
};

struct GuiBaseB {
    virtual GuiResponse process(const Event& event);
};

struct UnifiedWidget : public GuiBaseA, public GuiBaseB {
    char padW[0x10];
    int menuState;

    GuiResponse processNothing(const Event& event);
    GuiResponse processHover(const Event& event);
    GuiResponse processShown(const Event& event);

    virtual GuiResponse process(const Event& event);
};

GuiResponse UnifiedWidget::process(const Event& event)
{
    if (isVisible()) {
        int t = event.type;
        if (t == 1 || t == 2 || t == 3 || t == 4 || t == 5 || t == 6) {
            switch (menuState) {
            case 0:
                return processNothing(event);
            case 1:
                return processHover(event);
            case 2:
            case 3:
                return processShown(event);
            }
        }
    }
    return GuiResponse();
}
