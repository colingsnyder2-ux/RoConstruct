// from server: 100% by why2
struct CXTPPropertyGridInplaceEdit
{
    char pad[0x20];
    void* field_20;
    void Release();
    void sub_718d20(int);
};

void CXTPPropertyGridInplaceEdit::Release()
{
    if (field_20 != 0)
        sub_718d20(0);
}
