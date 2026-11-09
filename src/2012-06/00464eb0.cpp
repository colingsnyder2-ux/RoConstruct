// from server: 64% by atomic.potato
extern "C" void __stdcall func_0067f2e0(void*);
extern "C" void* __stdcall func_0067f480();
extern "C" void __stdcall func_00972290(unsigned char, const char*);
extern "C" void __stdcall func_00974670();

extern unsigned char g_e2e774;
extern unsigned char g_e580b3;
extern void* g_e5809c;

struct S {
    void* vtable;
    unsigned char b4;
    unsigned char b5;
    char pad6[2];
    void* field8;
    void* fieldc;
    void init(unsigned int a, void* b, void* c);
};

void S::init(unsigned int a, void* b, void* c)
{
    b4 = (unsigned char)a;
    b5 = (unsigned char)(a >> 8);
    field8 = c;
    vtable = (void*)0xb43c2c;
    void* tmp = b;
    func_0067f2e0(&tmp);
    fieldc = tmp;
    if (g_e2e774) {
        func_00974670();
    }
    if (g_e580b3) {
        void* d = fieldc;
        if (func_0067f480() == d) {
            if (g_e5809c) {
                typedef unsigned char (__stdcall *fn_t)(int, const char*, const char*);
                fn_t fn = (fn_t)g_e5809c;
                if (fn(0x43, (const char*)0xb57c00, (const char*)0xb57bec)) {
                    return;
                }
            }
            func_00972290(g_e580b3, (const char*)0xb57b70);
        }
    }
}
