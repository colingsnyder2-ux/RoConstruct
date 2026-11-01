// from server: 100% by colin
struct CXTPCustomizeSheet_CCustomizeEdit {
    CXTPCustomizeSheet_CCustomizeEdit* construct();
    int field_0;
    char pad[0x58];
    int field_5c;
};

void __fastcall base_ctor(void* p);

CXTPCustomizeSheet_CCustomizeEdit* CXTPCustomizeSheet_CCustomizeEdit::construct()
{
    base_ctor(this);
    *(int*)this = 0x7d760c;
    field_5c = 0;
    return this;
}
