// from server: 83% by colin
struct VCFrameWnd {
    char pad[0x20];
    void* m_hWnd;
    int sub_6305c8(int);
    void* sub_6302f8(void*);
    void* sub_6302fe(void*, int, int);
    void sub_6303b8(void*, int, int, int);
    void sub_630214(void*, int, int, int);
    void sub_63046c(void*);
    int Method(int);
};

extern "C" void* __stdcall GetMenu(void*);
extern "C" int __stdcall IsMenu(void*);
extern "C" int __stdcall SetMenu(void*, void*);

int VCFrameWnd::Method(int a1)
{
    int result = sub_6305c8(a1);
    if (result == -1)
        return result;

    void* menu = GetMenu(m_hWnd);
    void* menu2 = sub_6302f8(menu);
    if (menu2 != 0)
    {
        if (IsMenu(*(void**)((char*)menu2 + 4)) != 0)
        {
            sub_63046c(menu2);
            SetMenu(m_hWnd, 0);
        }
    }

    void* obj = sub_6302fe(m_hWnd, 0xe900, 1);
    sub_6303b8(obj, 0x800000, 0, 0x20);
    sub_630214(obj, 0x200, 0, 0x20);
    return 0;
}
