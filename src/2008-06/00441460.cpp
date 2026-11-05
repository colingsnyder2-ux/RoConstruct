// from server: 100% by colin
// from server: 21% by colin
// roc 2008-06 00441460  unit: HVCXTPPropertyGridItem::?$XItem  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00441460
//
// 00441460  6aff                 push -1
// 00441462  6899037c00           push 0x7c0399
// 00441467  64a100000000         mov eax, dword ptr fs:[0]
// 0044146d  50                   push eax
// 0044146e  64892500000000       mov dword ptr fs:[0], esp
// 00441475  51                   push ecx
// 00441476  56                   push esi
// 00441477  8bf1                 mov esi, ecx
// 00441479  51                   push ecx
// 0044147a  8d44241c             lea eax, [esp + 0x1c]
struct String {
    char* data;
    __declspec(dllimport) String(const String&);
    __declspec(dllimport) ~String() throw();
};
struct XItem {
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
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual int getValue();
    void assign(String name);
    void setValue(const int* v);
    void f(String name);
};
void XItem::f(String name)
{
    assign(name);
    int v = getValue();
    setValue(&v);
}
