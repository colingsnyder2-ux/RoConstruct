// from server: 100% by tester
struct CXTPPropertyGridView
{
    int SendNotifyMessageA(int, int);
};

struct CXTPPropertyGridInplaceEdit
{
    char pad[0x9c];
    int field_9c;
    int field_a0;
    int field_a4;
    int field_a8;

    void func_006f6350();
};

void CXTPPropertyGridInplaceEdit::func_006f6350()
{
    if (field_a8 != 0 && field_a0 != 0 && field_9c != 0)
    {
        ((CXTPPropertyGridView*)field_9c)->SendNotifyMessageA(4, (int)this);
    }
}
