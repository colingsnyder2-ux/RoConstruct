// from server: 70% by atomic.potato
typedef unsigned long DWORD;
typedef void *HDC;

extern "C" void *__cdecl sub_412F90(const char *);
extern "C" int (__stdcall *GetProcAddress)(void *, const char *);

struct CSettingsExplorer
{
    char padding[0x7c];
    DWORD field_7C;
    void SetValue(HDC *);
};

void CSettingsExplorer::SetValue(HDC *value)
{
    if (field_7C == 0)
    {
        field_7C = (DWORD)GetProcAddress(sub_412F90("ImageList_DragShowNolock"), 0);
    }
    *value = (HDC)field_7C;
}
