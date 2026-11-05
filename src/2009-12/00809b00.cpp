// from server: 70% by atomic.potato
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void*, const char*);

extern "C" void* __stdcall sub_412f90(const char*);

struct CXTPCommandBar {
    char pad[0x9c];
    void* m_pImageList;
    void GetImageInfo(void** out);
};

void CXTPCommandBar::GetImageInfo(void** out)
{
    if (m_pImageList == 0)
    {
        m_pImageList = GetProcAddress((void*)sub_412f90("ImageList_GetImageInfo"), "ImageList_GetImageInfo");
    }
    *out = m_pImageList;
}
