// from server: 100% by colin
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);

extern "C" int __fastcall sub_6465D0(void*);
extern "C" void __fastcall sub_643750(void*);

struct CXTPCustomizeSheet_CCustomizeEdit
{
    char pad[0x84];
    unsigned int field_84;
    char pad2[0xfc - 0x88];
    void* field_fc;

    void func_00675040();
};

void CXTPCustomizeSheet_CCustomizeEdit::func_00675040()
{
    int v1 = sub_6465D0(this->field_fc);
    sub_643750(this->field_fc);

    unsigned int a = this->field_84;
    struct { unsigned int a; unsigned int b; unsigned int c; unsigned int d; } local;
    local.c = 0x64;
    local.b = a;
    local.a = 0;
    local.d = (unsigned int)this;

    void* hWnd = *(void**)(v1 + 0x20);
    SendMessageA(hWnd, 0x2862, a, (long)&local);
}
