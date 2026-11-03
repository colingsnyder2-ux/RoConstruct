// from server: 91% by EspClaude
// roc 2007-08 0043c400  XItem: lock the data model, then forward to a virtual converter
struct DataModel;
struct Lock {
    void* a; void* b; void* c;
    explicit Lock(DataModel* dm);
    ~Lock();
};
struct Result {
    void* p;
    void* q;
    void* r;
    Result(const Result&);
};
struct Base0 { void* v; };
struct Base1 { int x; };
struct Name : Base0, Base1 {};
struct Converter {
    virtual void slot0();
    virtual Result convert(const Base1* value) = 0;
};
struct Holder { char pad[0x18]; Converter* converter; };
struct View { char pad[0x188]; DataModel* dataModel; };

struct XItem {
    char pad[0x120];
    View* view;
    Holder* holder;
    Result get(const Name* name);
};

Result XItem::get(const Name* name)
{
    Lock lock(view->dataModel);
    const Base1* value = 0;
    if (name)
        value = name;
    return holder->converter->convert(value);
}
