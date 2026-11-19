// from server: 100% by Intel_Inside
// variant e: like d but through an inline accessor taking the base pointer
// (mirrors sibling 0043bbe0: conversion at inline-call boundary)
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
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
struct Holder {
    char pad[0x18];
    Converter* converter;
    void forward(const Base1* object, const Value& value) { return converter->set(object, value); }
};
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
    holder->forward(name, value);
}
