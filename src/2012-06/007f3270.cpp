// from server: 80% by tajop
struct Inst;
struct ParentPad { char pad[0x1c]; };
struct Inst { int x; };
struct Parent : ParentPad, Inst { };

extern "C" void __cdecl rbx_release(char* p);

struct Tmp
{
    char* p;
    void* get();
    ~Tmp() { if (p) rbx_release(p + 5); }
};

struct Connection
{
    void assign(void* c);
};

struct Desc;

struct ER
{
    void* vtbl;
    int pad4;
    Parent* instance;
    Desc* desc;
    int pad10;
    int pad14;
    Connection listenerConnection;
    void listenerConnectionAdded();
    void connectSignalListener();
};

struct Fn
{
    void (ER::*f)();
    ER* o;
    Fn(void (ER::*f_)(), ER* o_) : f(f_), o(o_) {}
};

struct Desc
{
    Tmp connect(Inst* inst, const Fn& fn);
};

void ER::connectSignalListener()
{
    listenerConnection.assign(desc->connect(instance, Fn(&ER::listenerConnectionAdded, this)).get());
}
