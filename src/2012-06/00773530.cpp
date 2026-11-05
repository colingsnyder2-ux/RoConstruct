// from server: 34% by tester
struct Name;

struct CreatorBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

struct CreatorsMap {
    void insert(Name* key, void* value);
};

struct FactoryProduct {
    void* field0;
    CreatorsMap map;

    void registerCreator(Name* name, void* creator);
};

void __stdcall sub_75A4E0(void* a, void* b, void* c);
void __stdcall sub_7734A0(void* a, void* b, void* c);

void FactoryProduct::registerCreator(Name* name, void* creator) {
    this->field0 = creator;
    sub_7734A0(&this->map, name, creator);
    void* p = 0;
    if (name != 0) {
        p = (char*)name + 0x20;
    }
    sub_75A4E0(&this->map, p, name);
}
