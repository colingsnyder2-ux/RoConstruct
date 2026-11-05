// from server: 21% by colin
struct Name;
struct DataModel;
struct IDataState;

struct Verb {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

struct EditSelectionVerb : Verb {
    char pad[0x14];
    void* field14;
    char pad2[0x8];
    void* field20;
    void* field24;
};

struct BoolPropertyVerb : EditSelectionVerb {
    void doIt(IDataState* dataState);
};

extern "C" void __stdcall sub_55E290();
extern "C" void __stdcall sub_55FAA0();
extern "C" void __stdcall sub_55FBD0();
extern "C" void __stdcall sub_560B40();
extern "C" void __stdcall sub_562300();
extern "C" void __stdcall sub_410BB0();
extern "C" void __stdcall sub_77E69C();
extern "C" void __stdcall sub_77E6D8();

void BoolPropertyVerb::doIt(IDataState* dataState)
{
    sub_55E290();
    bool checked = v3();
    sub_55FAA0();
    sub_562300();
    sub_562300();
    sub_560B40();
    sub_55FBD0();
    sub_77E69C();
    sub_410BB0();
    sub_55FBD0();
}
