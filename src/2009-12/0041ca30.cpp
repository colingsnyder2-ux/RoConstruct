// from server: 65% by atomic.potato
typedef unsigned long DWORD;

extern "C" DWORD __stdcall GetProcAddress(DWORD, const char *);

DWORD __cdecl CreateObject(DWORD);

struct CSettingsExplorer {
    DWORD field64;
    void GetImageList(DWORD *);
};

void CSettingsExplorer::GetImageList(DWORD *result)
{
    if (field64 == 0) {
        field64 = GetProcAddress(CreateObject(0x9a2fe0), "ImageList_BeginDrag");
    }
    *result = field64;
}
