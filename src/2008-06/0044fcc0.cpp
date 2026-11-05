// from server: 100% by king_originala
struct Dialog
{
    char storage[0x130];

    Dialog(void* owner, int flags);
    ~Dialog();
    int run();
};

struct CRobloxDoc
{
    char padding[0x94];
    void* owner;

    void func_0044fcc0();
};

void CRobloxDoc::func_0044fcc0()
{
    Dialog dialog(owner, 0);
    dialog.run();
}
