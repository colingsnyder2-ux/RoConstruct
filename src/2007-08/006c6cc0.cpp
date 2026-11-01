// from server: 100% by colin
extern "C" void __stdcall sub_00635af0(void*);
extern "C" void __fastcall sub_0063094c(void*);

struct CXTPCustomizeSheet_CCustomizeEdit
{
    char pad[0x5c];
    void* field_5c;
    void sub_006c6cc0();
};

void CXTPCustomizeSheet_CCustomizeEdit::sub_006c6cc0()
{
    if (field_5c != 0)
    {
        sub_00635af0((char*)field_5c + 0x18c);
    }
    sub_0063094c(this);
}
