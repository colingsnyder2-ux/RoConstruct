// from server: 100% by tester
extern "C" long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);

struct CXTPCustomizeSheet_CCustomizeEdit {
    char pad[0x168];
    void* field_0x168;
    char pad2[0x4];
    int field_0x170;
    void SetValue(int value);
};

void CXTPCustomizeSheet_CCustomizeEdit::SetValue(int value)
{
    field_0x170 = value;
    if (field_0x168 != 0) {
        if (*(int*)((char*)field_0x168 + 0x20) != 0) {
            SendMessageA(*(void**)((char*)field_0x168 + 0x20), 0xcf, value, 0);
        }
    }
}
