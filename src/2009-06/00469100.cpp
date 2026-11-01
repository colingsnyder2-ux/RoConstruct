// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned int size_t;
namespace std {
class __declspec(dllimport) string {
public:
    ~string();
    const char* c_str() const;
    char pad[0x1c];
};
}
class CXTPReportRecordItem {
public:
    static void* __stdcall operator new(size_t n);
    static void __stdcall operator delete(void* p);
    CXTPReportRecordItem();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void SetIconIndex(int i);
    virtual void w55();
    virtual void w56();
    virtual void w57();
    virtual void SetCaption(const char* s);
    char data[0x78];
};
class CXTPReportRecord {
public:
    CXTPReportRecordItem* AddItem(CXTPReportRecordItem* item);
};
CXTPReportRecordItem* AddItem(CXTPReportRecord* record, std::string caption, double icon)
{
    CXTPReportRecordItem* item = new CXTPReportRecordItem();
    item->SetCaption(caption.c_str());
    if (icon >= 0)
        item->SetIconIndex((int)icon);
    record->AddItem(item);
    return item;
}
