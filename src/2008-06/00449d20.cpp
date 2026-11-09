// from server: 100% by king_originala
struct Dialog {
    char storage[0x12c];

    Dialog(void* parent);
    virtual ~Dialog();
    virtual int DoModal();
};

struct CIDEDocManager {
    void OnAppAbout();
};

void CIDEDocManager::OnAppAbout()
{
    Dialog dialog(0);
    dialog.DoModal();
}
