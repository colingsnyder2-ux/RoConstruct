// from server: 91% by Intel
extern "C" void __cdecl sub_972290(const char*, int);

unsigned char g_flag_e580b3;
int (*g_callback_e5809c)(int, const char*, const char*);

struct AsyncHttpCache {
    char pad[4];
    int field_4;
    void checkAndLog();
};

void AsyncHttpCache::checkAndLog()
{
    if (!g_flag_e580b3)
        return;

    if (field_4 == 0)
        return;

    if (g_callback_e5809c) {
        int result = g_callback_e5809c(0x21, (const char*)0xBABACAC, (const char*)0xBABACC0);
        if (result != 0)
            return;
    }

    int flagValue = g_flag_e580b3;
    sub_972290((const char*)0xBABC38, flagValue);
}
