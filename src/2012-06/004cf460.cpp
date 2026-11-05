// from server: 0% by atomic.potato
extern "C" void* __stdcall alloc_004cf460(unsigned int, const char*, int, const char*);
extern "C" void* __stdcall str_ctor_004cf460(void*, const char*);
extern "C" void __stdcall str_dtor_004cf460(void*);
extern "C" void __stdcall root_ctor_004cf460(void*, const void*, const void*, const void*);
extern "C" void __stdcall smf_ctor_004cf460(void*);
extern "C" void __stdcall root_add_smf_004cf460(void*, void*);
extern "C" void __stdcall root_load_plugin_004cf460(void*, const void*);
extern "C" void __stdcall sub_009831f5(void*);

extern int g_e1c404;
extern int g_e1c3c0;
extern int g_b66890;

struct GfxClustererPart_004cf460 {
    int field0;
    int field4;
    void __cdecl init(int);
};

void GfxClustererPart_004cf460::init(int arg)
{
    char buf1[0x28];
    char buf2[0x28];
    void* p;
    int saved;

    if (this->field0 != 0)
        return;

    p = alloc_004cf460(0x214, "spatialNodeLevel == -1 file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\Inc", 0, 0);
    if (p != 0) {
        str_ctor_004cf460(buf1, "8csm");
        str_ctor_004cf460(buf2, "8csm");
        root_ctor_004cf460(p, buf2, buf1, (void*)arg);
        str_dtor_004cf460(buf2);
        str_dtor_004cf460(buf1);
    }
    this->field0 = (int)p;

    if ((g_e1c404 & 1) == 0) {
        g_e1c404 |= 1;
        smf_ctor_004cf460(&g_e1c3c0);
        g_e1c3c0 = (int)&g_b66890;
        sub_009831f5((void*)0xb12a70);
    }

    root_add_smf_004cf460((void*)this->field0, &g_e1c3c0);

    if (arg == 0) {
        str_ctor_004cf460(buf1, "Plugin_CgProgramManager.dll");
        root_load_plugin_004cf460((void*)this->field0, buf1);
        str_dtor_004cf460(buf1);

        str_ctor_004cf460(buf1, "RenderSystem_Direct3D9.dll");
        root_load_plugin_004cf460((void*)this->field0, buf1);
        str_dtor_004cf460(buf1);
    }
}
