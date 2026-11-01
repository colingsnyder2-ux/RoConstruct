// from server: 100% by colin
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct VCSecureHtmlView_CXTPCommandBarsSiteBase
{
    char pad[0x16c];
    void* field_16c;
    void f(unsigned int arg);
};

void VCSecureHtmlView_CXTPCommandBarsSiteBase::f(unsigned int arg)
{
    void* hwnd = *(void**)((char*)field_16c + 0x20);
    long result = SendMessageA(hwnd, 0x18b, 0, 0);
    if ((int)arg < result)
    {
        SendMessageA(*(void**)((char*)field_16c + 0x20), 0x182, arg, 0);
    }
}
