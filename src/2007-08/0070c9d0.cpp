// from server: 100% by colin
struct CXTColorBase {
    char pad[0x20];
    void* hwnd;
    char pad2[0x3c];
    int field60;
    int field64;
    int field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    void SetColor(int a, int b);
};

extern "C" int (__stdcall *InvalidateRect)(void*, const void*, int);
extern "C" void __cdecl sub_70c650(int, int*, int*, int*);

void CXTColorBase::SetColor(int a, int b)
{
    if (field60 != -1)
    {
        field60 = a;
        sub_70c650(a, &field78, &field70, &field68);
        InvalidateRect(hwnd, 0, 1);
    }
}
