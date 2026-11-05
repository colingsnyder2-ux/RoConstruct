// from server: 86% by atomic.potato
extern "C" int __cdecl sub_412f90(const char *);

extern "C" void *__stdcall GetProcAddress(void *, const char *);

struct CSettingsExplorer
{
    char padding[0x74];
    int field_74;
    void *f(void *);
};

void *CSettingsExplorer::f(void *out)
{
    if (field_74 == 0)
        field_74 = (int)GetProcAddress(0, (const char *)sub_412f90("ImageList_DragMove"));
    *(int *)out = field_74;
    return out;
}
