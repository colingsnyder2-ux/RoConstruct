// from server: 95% by tajop
struct StringBase {
    char storage[28];
};

extern void (StringBase::*string_ctor_import)(const char* s);

struct String : StringBase {
    String(const char* s) { (this->*string_ctor_import)(s); }
    String(const String& o);
    ~String();
};

struct DataModel;

struct EditSelectionVerb {
    EditSelectionVerb(String name, DataModel* dataModel);
    virtual ~EditSelectionVerb();
    virtual void doIt(void* dataState);
};

struct CopyVerb : EditSelectionVerb {
    CopyVerb(DataModel* dataModel);
    virtual void doIt(void* dataState);
};

CopyVerb::CopyVerb(DataModel* dataModel) : EditSelectionVerb("Copy", dataModel) {
}
