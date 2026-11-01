// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

extern char* __cdecl func_0040df70();
extern char* __cdecl func_0040dfa0();
extern char* __cdecl func_00412af0();
extern char* __cdecl func_00412b80();
extern char* __cdecl func_004332e0();
extern char* __cdecl func_00433410();
extern char* __cdecl func_0044f200();
extern char* __cdecl func_00455d40();
extern char* __cdecl func_00458e70();
extern char* __cdecl func_004638a0();
extern char* __cdecl func_004638c0();
extern char* __cdecl func_006a0d2e();

extern void* vtable_00816684[];
extern void* vtable_0081671c[];
extern void* vtable_0081685c[];
extern void (__thiscall* imported_00803f04)(void*);

struct Document {
    void** vptr;
    char padding[0x8c];

    Document(int, char*, char*, char*);
};

struct SimpleDocument : Document {
    SimpleDocument(int, char*, char*, char*);
};

struct ExtendedDocument : Document {
    int field_90;
    unsigned int field_94;

    ExtendedDocument(int, char*, char*, char*);
};

struct TemplateBase {
    void** vptr;
    char padding[0x1c];

    TemplateBase();
    ~TemplateBase();
    void attach(Document*);
};

struct CRbxPlayDocTemplate : TemplateBase {
    SimpleDocument* field_20;
    ExtendedDocument* field_24;
    SimpleDocument* field_28;
    SimpleDocument* field_2c;

    CRbxPlayDocTemplate(bool);
};

__forceinline SimpleDocument::SimpleDocument(
    int id, char* a, char* b, char* c)
    : Document(id, a, b, c)
{
    vptr = vtable_00816684;
}

__forceinline ExtendedDocument::ExtendedDocument(
    int id, char* a, char* b, char* c)
    : Document(id, a, b, c)
{
    vptr = vtable_0081671c;
    field_90 = 0;
    imported_00803f04(&field_94);
}

CRbxPlayDocTemplate::CRbxPlayDocTemplate(bool play)
    : TemplateBase()
{
    vptr = vtable_0081685c;

    field_24 = new ExtendedDocument(
        0x81,
        func_0044f200(),
        func_00412b80(),
        play ? func_00455d40() : func_00458e70());
    attach(field_24);

    field_20 = new SimpleDocument(
        0xb9,
        func_0040dfa0(),
        func_00412af0(),
        func_0040df70());
    attach(field_20);

    field_28 = new SimpleDocument(
        0xcf,
        func_004638a0(),
        func_006a0d2e(),
        func_004638c0());
    attach(field_28);

    field_2c = new SimpleDocument(
        0x8a,
        func_004332e0(),
        func_006a0d2e(),
        func_00433410());
    attach(field_2c);
}
