// from server: 100% by atomic.potato
extern "C" int __declspec(dllimport) __stdcall PostMessageA(void *, unsigned int, unsigned int, long);

struct CRobloxWnd
{
    char pad_1d0[0x1d0];
    unsigned char field_1d0;
    char pad_1d1[3];
    void *field_1d4;
    int RenderRequestJob(int);
};

int CRobloxWnd::RenderRequestJob(int)
{
    field_1d0 = 0;
    PostMessageA(field_1d4, 0x484, 0, 0);
    return 1;
}
