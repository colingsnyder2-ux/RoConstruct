// from server: 32% by colin
struct QTextBrowser {
    void* vtable;
    QTextBrowser(void* parent);
};

struct DeclarationView : QTextBrowser {
    DeclarationView(void* parent);
};

extern "C" void* __cdecl operator_new(unsigned int size);

void* __cdecl sub_435660(void* p);

DeclarationView::DeclarationView(void* parent)
    : QTextBrowser(parent)
{
    void* mem = operator_new(0x110);
    if (mem) {
        sub_435660(mem);
    }
}
