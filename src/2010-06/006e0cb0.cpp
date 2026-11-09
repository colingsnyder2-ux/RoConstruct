// from server: 49% by atomic.potato
extern "C" void* __stdcall make_desc_005b6aa0(const char*, int);

struct Descriptor_005b6aa0 { void attach(void*); };
extern Descriptor_005b6aa0 global_desc_005b6aa0;
extern void register_desc_005b6aa0(void(*)());
extern int name_005b6aa0;
extern int callback_impl;

struct Init_005b6aa0 {
    Init_005b6aa0() {
        void* p = make_desc_005b6aa0((const char*)&name_005b6aa0, 0);
        global_desc_005b6aa0.attach(p);
        register_desc_005b6aa0((void(*)())&callback_impl);
    }
};
Init_005b6aa0* func_005b6aa0() { static Init_005b6aa0 init; return &init; }

void* __stdcall sub_6e0790(void*, int, int, int, int, int);
void* __stdcall sub_5b6aa0(int, int);
void __stdcall sub_7a799a(void*);

struct Other {
    void method(void*);
};

struct TextLabel {
    void ctor(int, int, int, int, int, int, int);
};

void TextLabel::ctor(int a, int b, int c, int d, int e, int f, int g) {
    void* p = sub_6e0790(this, a, b, c, d, e);
    int saved = *(int*)p;
    *(int*)p = 0;
    int local = saved;
    int zero = 0;
    sub_5b6aa0(f, g);
    ((Other*)this)->method(&local);
    sub_7a799a(&zero);
    *(int*)this = 0xa48394;
}
