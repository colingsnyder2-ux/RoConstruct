// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base {
    Base();
    virtual ~Base();
    char padding[0x50];
};

struct CScriptDoc : Base {
    virtual ~CScriptDoc();
    int field54;
    int field58;
    static CScriptDoc* Create();
};

CScriptDoc* CScriptDoc::Create()
{
    CScriptDoc* p = new CScriptDoc;
    if (p) {
        p->field54 = 0;
        p->field58 = 0;
    }
    return p;
}
