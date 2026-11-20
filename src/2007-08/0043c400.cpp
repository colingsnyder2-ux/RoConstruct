// from server: 100% by Intel_Inside
// from server: 100% by EspClaude (twin: 0043cff0)
// roc 2007-08 0043c400  XItem: lock the data model, then forward to a virtual converter
struct DataModel;
struct Lock {
    Lock(DataModel* dm);
    ~Lock();
    int m_data[3];
};

struct Result {
    Result(const Result&);
    int m_v;
};

struct Base0 { int m_base0; };
struct Base1 { int m_base4; };
struct Name : Base0, Base1 { };   // base at +4

struct Converter {
    virtual void v00();
    virtual Result Convert(Base1* pItem);   // vtable +4, returns via hidden pointer
};
struct Holder {
    char pad[0x18];
    Converter* m_pConverter;   // +0x18
    Result Get(Base1* p) { return m_pConverter->Convert(p); }
};
struct View {
    char pad[0x188];
    DataModel* m_p188;             // +0x188
};

struct XItem {
    char pad[0x120];
    View* m_pPanel;         // +0x120
    Holder* m_pOwner;       // +0x124
    Result get(Name* pItem);
};

Result XItem::get(Name* pItem)
{
    Lock lock(m_pPanel->m_p188);
    return m_pOwner->Get(pItem);
}