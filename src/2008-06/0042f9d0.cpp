// from server: 100% by king_originala
struct Section {
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
    virtual Section* section(const char*);
    void release();
};

struct SectionOwner {
    Section* p;
    ~SectionOwner();
};

inline SectionOwner::~SectionOwner()
{
    if (p)
        p->release();
}

struct ExchangeOptions {
    int mode;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
};

struct Options {
    void exchange(Section*, int);
};

struct CommandBars {
    char pad0[116];
    Options* options;
    void exchange(Section*, ExchangeOptions*);
    int f();
};

struct DockingPane {
    void exchange(Section*);
};

struct MyXTPCommandBars {
    char pad0[236];
    CommandBars* bars;
    char pad1[72];
    DockingPane docking;
    void exchange(Section*, int);
};

void MyXTPCommandBars::exchange(Section* px, int mode)
{
    CommandBars* manager = bars;
    ExchangeOptions options;
    options.a = 1;
    options.c = 1;
    options.f = 1;
    options.mode = mode;
    options.b = 1;
    options.i = 0;
    options.e = 0;
    options.d = 0;
    options.g = 0;
    options.h = 0;

    SectionOwner commandBars = { px->section("CommandBars") };
    manager->exchange(commandBars.p, &options);

    SectionOwner shortcuts = { px->section("Shortcuts") };
    reinterpret_cast<Section*>(manager->f())->section(
        reinterpret_cast<const char*>(shortcuts.p));

    SectionOwner commandOptions = { px->section("Options") };
    manager = reinterpret_cast<CommandBars*>(manager->options);
    reinterpret_cast<Options*>(manager)->exchange(commandOptions.p, 1);

    SectionOwner dockingPane = { px->section("DockingPane") };
    docking.exchange(dockingPane.p);
}
