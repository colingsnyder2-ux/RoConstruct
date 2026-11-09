// from server: 76% by colin
extern unsigned char g_flag;
extern void* g_logger;
extern void G1_func_00972290(int, const char*);
extern void G1_func_005a2d10();

struct S {
    void* field0;
    void f();
};

void S::f()
{
    if (g_flag == 0) {
        return;
    }

    if (field0 == 0) {
        void* logger = g_logger;
        if (logger != 0) {
            bool result = ((bool (__stdcall*)(const char*, const char*, int))logger)((const char*)0xb4e9a4, (const char*)0xb7b080, 0x81);
            if (result) {
                goto after_assert1;
            }
        }
        G1_func_00972290((int)g_flag, (const char*)0xb7b280);
    }
after_assert1:
    if (g_flag == 0) {
        return;
    }

    void* p = field0;
    if (p == 0) {
        return;
    }

    G1_func_005a2d10();
    if (g_flag == 0) {
        return;
    }

    void* logger = g_logger;
    if (logger != 0) {
        bool result = ((bool (__stdcall*)(const char*, const char*, int))logger)((const char*)0xb7b254, (const char*)0xb7b080, 0x82);
        if (result) {
            return;
        }
    }
    G1_func_00972290((int)g_flag, (const char*)0xb7b1c8);
}
