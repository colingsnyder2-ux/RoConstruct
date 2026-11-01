// from server: 100% by king_originala
struct Menu {
    unsigned int reserved;
    void* handle;
    void Destroy();
};

struct Window {
    void ModifyStyle(unsigned long remove, unsigned long add, unsigned int flags);
    void ModifyStyleEx(unsigned long remove, unsigned long add, unsigned int flags);
};

extern "C" int (__stdcall *IsMenu)(void* menu);
extern Window* __stdcall FindWindow(void* parent, int id, int recursive);

struct Frame {
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
    virtual Menu* GetMenu();
    virtual void SetMenu(Menu* menu);

    unsigned char reserved[28];
    void* handle;

    int BaseCreate(void* create);
    int OnCreate(void* create);
};

int Frame::OnCreate(void* create)
{
    int result = BaseCreate(create);
    if (result == -1)
        return result;

    Menu* menu = GetMenu();
    if (menu && IsMenu(menu->handle)) {
        menu->Destroy();
        SetMenu(0);
    }

    Window* window = FindWindow(handle, 0xe900, 1);
    window->ModifyStyle(0x800000, 0, 0x20);
    window->ModifyStyleEx(0x200, 0, 0x20);
    return 0;
}
