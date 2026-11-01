// from server: 100% by king_originala
struct Dialog
{
    char storage[0x12C];
    Dialog(void *, int);
    virtual ~Dialog();
    int DoModal();
};

struct CRobloxDoc
{
    char padding[0x94];
    void *context;
    void func_0044fc50();
};

void CRobloxDoc::func_0044fc50()
{
    Dialog dialog(context, 0);
    dialog.DoModal();
}
