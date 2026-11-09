// from server: 57% by Intel
extern "C" {
    extern unsigned char g_flag_00E580B3;
    extern void* g_ptr_00BB2C60;
    extern int (__cdecl *g_callback_00E5809C)(const char*, const char*, int);
    extern const char* g_str_004965E0;
    extern const char* g_str_00E1A908;
    extern const char* g_str_00B42FA8;
    extern const char* g_str_00B46518;
    extern const char* g_str_00B46490;
}

extern "C" void __cdecl func_004015A0(const char*, const char*);
extern "C" void* __cdecl func_00495A90();
extern "C" void* __cdecl func_0067F480();
extern "C" void __cdecl func_00972290(unsigned char, const char*);

int __cdecl func_00497570()
{
    if (!g_flag_00E580B3)
        goto LABEL_RETURN;

    if (!g_ptr_00BB2C60)
    {
        func_0067F480();
    }
    else
    {
        func_004015A0(g_str_004965E0, g_str_00E1A908);
        func_00495A90();
    }

    void* esi_val = func_00495A90();
    void* eax_val = func_0067F480();

    int cl = (eax_val == esi_val) ? 1 : 0;
    int dl = (g_ptr_00BB2C60 == 0) ? 1 : 0;

    if (cl == dl)
        goto LABEL_RETURN;

    if (g_callback_00E5809C)
    {
        int result = g_callback_00E5809C(g_str_00B46518, g_str_00B42FA8, 0x14B);
        if (result)
            goto LABEL_RETURN;
    }

    func_00972290(g_flag_00E580B3, g_str_00B46490);

LABEL_RETURN:
    return (g_ptr_00BB2C60 == 0) ? 1 : 0;
}
