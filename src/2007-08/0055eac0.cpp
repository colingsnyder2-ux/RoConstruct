// from server: 55% by colin
struct DataModel;

struct Instance {
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
    virtual bool isA(const char* name);
};

struct StatsCommand {
    char pad[0xc];
    DataModel* dataModel;
    bool isChecked() const;
};

struct DataModel {
    char pad[0x1a0];
    Instance* statsHud;
};

struct String {
    void* pad[7];
    String(const char*);
    ~String();
};

extern "C" {
    void* __stdcall sub_77E698(void*);
    void __stdcall sub_77E6AC(void*);
}

extern "C" void* __cdecl sub_53E7A0(void*, const char*, const char*, int, void*);
extern "C" Instance* __cdecl sub_630D36(void*);

bool StatsCommand::isChecked() const {
    Instance* hud = dataModel->statsHud;
    String s("StatsHud1");
    void* p = sub_53E7A0(hud, "StatsHud1", "StatsHud1", 0, &s);
    Instance* q = sub_630D36(p);
    s.~String();
    if (q) {
        if (q->isA("StatsHud1")) {
            return true;
        }
    }
    return false;
}
