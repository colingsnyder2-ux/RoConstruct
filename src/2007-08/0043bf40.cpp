// from server: 91% by EspClaude
// roc 2007-08 0043bf40  XItem setter: lock the data model, then forward to a virtual setter
struct DataModel;
struct Lock {
    void* a; void* b; void* c;
    explicit Lock(DataModel* dm);
    ~Lock();
};
struct Value;
struct Base0 { void* v; };
struct Base1 { int x; };
struct Name : Base0, Base1 {};
struct Converter {
    virtual void slot0();
    virtual void slot1();
    virtual void set(const Base1* object, const Value& value) = 0;
};
struct Holder { char pad[0x18]; Converter* converter; };
struct View { char pad[0x188]; DataModel* dataModel; };

struct XItem {
    char pad[0x114];
    View* view;
    Holder* holder;
    void set(const Name* name, const Value& value);
};

void XItem::set(const Name* name, const Value& value)
{
    Lock lock(view->dataModel);
    const Base1* object = 0;
    if (name)
        object = name;
    holder->converter->set(object, value);
}
