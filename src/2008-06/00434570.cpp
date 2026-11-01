// from server: 100% by king_originala
struct Interface;

struct InterfaceTable {
    void* reserved[2];
    unsigned long (__stdcall *release)(Interface*);
};

struct Interface {
    InterfaceTable* table;
};

extern void* declarationViewTable[];

struct Base {
    void** volatile table;
    char storage[0xF0];
    void cleanup();
};

struct CDeclarationView : Base {
    Interface* pF4;
    Interface* pF8;
    Interface* pFC;
    Interface* p100;
    Interface* p104;
    Interface* p108;
    Interface* p10C;
    Interface* volatile p110;

    void cleanup();
};

void CDeclarationView::cleanup()
{
    table = declarationViewTable;
    Interface* p = p110;
    if (p) p->table->release(p);
    if (p10C) p10C->table->release(p10C);
    if (p108) p108->table->release(p108);
    if (p104) p104->table->release(p104);
    if (p100) p100->table->release(p100);
    if (pFC) pFC->table->release(pFC);
    if (pF8) pF8->table->release(pF8);
    if (pF4) pF4->table->release(pF4);
    Base::cleanup();
}
