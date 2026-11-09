// from server: 100% by colin
struct CXTColorSelectorCtrl {
    char pad[0xc0];
    char field_c0[0x20];
    int field_e0;
    void sub_63026e(int);
    void method(int);
};

extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

void CXTColorSelectorCtrl::method(int arg)
{
    char* p = (char*)this + 0xc0;
    if (p != 0 && *(int*)(p + 0x20) != 0)
    {
        SendMessageA((void*)field_e0, 0x407, 0, arg);
    }
    sub_63026e(arg);
}
