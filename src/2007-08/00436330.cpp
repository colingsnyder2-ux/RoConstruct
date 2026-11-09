// from server: 32% by Intel
extern "C" void* __stdcall sub_4345F0();
extern "C" void __stdcall sub_4360A0();
extern "C" void __stdcall sub_725750();
extern "C" void __stdcall sub_725770();
extern "C" void* __stdcall GetProcAddress(void* hModule, const char* lpProcName);
extern "C" void* __stdcall LoadLibraryA(const char* lpLibFileName);
extern "C" unsigned int __stdcall SendMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);
extern "C" void __cdecl _invalid_parameter_noinfo();

void* g_77ecd8 = (void*)0x77ecd8;
void* g_77e6d8 = (void*)0x77e6d8;
void* g_8b5188 = (void*)0x8b5188;
void* g_434c20 = (void*)0x434c20;
void* g_434340 = (void*)0x434340;

struct CDeclarationView {
    void* vtable;
    char pad_004[0x1c];
    void* m_handle;
    char pad_008[0x88];
    void* m_item;
    char pad_012[0x4];
    int m_count;
    int m_capacity;
    int m_end;
    void updateDeclarationView(void* item);
};

void CDeclarationView::updateDeclarationView(void* item)
{
    void* v_4345f0 = sub_4345F0();
    SendMessageA(m_handle, 0x1101, 0, 0xffff0000);
    m_item = item;
    sub_725750();
    int count = m_count;
    int* begin = (int*)((char*)item + 0x10);
    if (begin[1] > count)
        _invalid_parameter_noinfo();
    int end = begin[1];
    if (end > begin[2])
        _invalid_parameter_noinfo();
    sub_4360A0();
    SendMessageA(m_handle, 0x1115, 0, (long)g_434340);
    sub_725770();
}
