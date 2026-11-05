// from server: 12% by colin
extern "C" {
    __declspec(dllimport) void* __stdcall SendMessageA(void*, unsigned int, unsigned int, long);
    __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();
}

struct QTextBrowser {
    void* vtable;
    char pad[0x1c];
    void* m_handle;
};

struct ObjectBrowserItem {
    char pad[0x10];
    int m_count;
    int m_capacity;
    int m_end;
};

struct DeclarationView : QTextBrowser {
    char pad2[0x8c];
    ObjectBrowserItem* m_item;
    void updateDeclarationView(ObjectBrowserItem* item);
};

void* __stdcall sub_4345F0();
void __stdcall sub_4360A0();
void __stdcall sub_725750();
void __stdcall sub_725770();
void __stdcall sub_434340();

void DeclarationView::updateDeclarationView(ObjectBrowserItem* item)
{
    SendMessageA(m_handle, 0x1101, 0, 0xffff0000);
    m_item = item;
    void* p = sub_4345F0();
    sub_725750();
    int count = item->m_count;
    int* begin = (int*)((char*)item + 0x10);
    if (begin[1] > count)
        _invalid_parameter_noinfo();
    int end = begin[1];
    if (end > begin[2])
        _invalid_parameter_noinfo();
    sub_4360A0();
    SendMessageA(m_handle, 0x1115, 0, (long)&sub_434340);
    sub_725770();
}
