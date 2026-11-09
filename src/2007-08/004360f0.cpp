// from server: 8% by colin
struct QTextBrowser {
    void setOpenLinks(bool);
    void setOpenExternalLinks(bool);
};

struct DeclarationView : QTextBrowser {
    DeclarationView(void* parent);
};

DeclarationView::DeclarationView(void* parent)
{
    setOpenLinks(true);
    setOpenExternalLinks(true);
}
