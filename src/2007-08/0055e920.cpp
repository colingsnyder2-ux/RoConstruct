// from server: 44% by colin
struct DataModel;
struct Instance;

struct StatsHud {
    char pad[0x110];
    bool checked;
};

struct StatsCommand {
    char pad[0xc];
    DataModel* dataModel;
    void execute(int);
};

struct DataModel {
    char pad[0x1a0];
    Instance* statsHud;
};

struct Instance {
    virtual bool isA(const char*) const;
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void dummy19();
    virtual void dummy20();
    virtual void dummy21();
    virtual bool isEnabled() const;
};

extern "C" {
    void* __stdcall sub_77E698(void*);
    void __stdcall sub_77E6AC(void*);
}

extern "C" void* __cdecl sub_53E7A0(Instance*, const char*, const char*, int, int);
extern "C" void* __cdecl sub_630D36(void*);

void StatsCommand::execute(int)
{
    Instance* hud = dataModel->statsHud;

    char buf1[0x1c];
    sub_77E698(buf1);
    void* a = sub_53E7A0(hud, "StatsHud1", "StatsHud1", 0, 0);
    void* b = sub_630D36(a);
    sub_77E6AC(buf1);
    if (b) {
        bool enabled = ((Instance*)b)->isEnabled();
        ((StatsHud*)b)->checked = !enabled;
    }

    char buf2[0x1c];
    sub_77E698(buf2);
    void* c = sub_53E7A0(hud, "StatsHud2", "StatsHud2", 0, 0);
    void* d = sub_630D36(c);
    sub_77E6AC(buf2);
    if (d) {
        bool enabled = ((Instance*)d)->isEnabled();
        ((StatsHud*)d)->checked = !enabled;
    }
}
