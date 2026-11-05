// from server: 59% by atomic.potato
extern unsigned char g_e580b3;
extern int g_e5809c;
extern void G1_func_00921920();
extern unsigned char G1_func_00921990();
extern void G1_func_00972290(unsigned char, const char*);
extern void* G1_func_00964080();
extern void G1_func_00963f50(void*, void*, int);

struct EdgeStage
{
    void func_009641b0(void* arg);
};

void EdgeStage::func_009641b0(void* arg)
{
    if (g_e580b3 != 0)
    {
        if (!G1_func_00921990())
        {
            if (g_e5809c != 0)
            {
                if (!((unsigned char (__stdcall*)(const char*, const char*, int))g_e5809c)((const char*)0xc06f4c, (const char*)0xc06978, 0x4a))
                {
                    G1_func_00972290(g_e580b3, (const char*)0xc06ed0);
                }
            }
            else
            {
                G1_func_00972290(g_e580b3, (const char*)0xc06ed0);
            }
        }
    }
    int local = 0;
    G1_func_00921920();
    void* r = G1_func_00964080();
    G1_func_00963f50(arg, r, local);
}
