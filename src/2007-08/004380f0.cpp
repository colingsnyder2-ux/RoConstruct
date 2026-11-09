// from server: 41% by colin
struct StdString {
    void ctor(const StdString&);
    void dtor();
    char buf[28];
};

struct Listener {
    char pad0[4];
    char pad4[0x14];
    int field18;
};

struct Msg {
    int type;
    StdString text;
    int a;
    int b;
};

struct Out {
    char pad0[4];
    char pad4[0x14];
    int field18;
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __stdcall string_copy_ctor(StdString*, const StdString*);
extern "C" void __stdcall string_dtor(StdString*);
extern "C" void __stdcall list_push(void*, void*);
extern "C" void __stdcall out_print(int, void*);

struct VStandardOut {
    void marshaledListener(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
};

void VStandardOut::marshaledListener(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
    Listener* self = (Listener*)this;
    Msg* msg = (Msg*)operator_new(0x38);
    if (msg) {
        msg->type = a;
        string_copy_ctor(&msg->text, (const StdString*)&b);
        msg->a = e;
        msg->b = f;
        out_print((int)msg, self);
    } else {
        msg = 0;
    }
    void* local = msg;
    list_push(&self->pad4, &local);
    out_print(self->field18, msg);
    string_dtor((StdString*)&b);
}
