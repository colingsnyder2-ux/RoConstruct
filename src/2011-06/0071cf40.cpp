// from server: 31% by atomic.potato
struct S {
    char pad0[0x14];
    void* field14;
    char pad18[0x10];
    void* field28;
    void* field2c;
    char pad30[0x30];
    int f(int, int, int, int, int);
};

extern "C" void* __stdcall cb_005cf170(int, int);
extern "C" void cb_006a5b20();
extern "C" void cb_0062d1b0();
extern "C" void cb_0062d140();
extern "C" void cb_005bab20();
extern "C" void cb_00592b40();
extern "C" void cb_0062d1d0();

extern int g_cca3e4;
extern int g_cca728;

int S::f(int a1, int a2, int a3, int a4, int a5)
{
    void* p = cb_005cf170(a1, a2);
    cb_006a5b20();
    this->field28 = (void*)a4;
    this->field2c = (void*)a5;
    *(void**)this = (void*)0xab1508;
    cb_0062d1b0();
    g_cca3e4++;
    cb_0062d140();
    this->field14 = p;
    g_cca728++;
    cb_005bab20();
    cb_00592b40();
    cb_0062d1d0();
    return (int)this;
}
