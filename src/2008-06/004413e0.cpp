// from server: 100% by colin
// from server: 22% by colin
// roc 2008-06 004413e0  unit: MVCXTPPropertyGridItem::?$XItem  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004413e0
//
// 004413e0  6aff                 push -1
// 004413e2  6899037c00           push 0x7c0399
// 004413e7  64a100000000         mov eax, dword ptr fs:[0]
// 004413ed  50                   push eax
// 004413ee  64892500000000       mov dword ptr fs:[0], esp
// 004413f5  51                   push ecx
// 004413f6  56                   push esi
// 004413f7  8bf1                 mov esi, ecx
// 004413f9  51                   push ecx
// 004413fa  8d44241c             lea eax, [esp + 0x1c]
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
    virtual float getValue();
    void assign(String name);
    void setValue(const float* v);
    void f(String name);
};
void XItem::f(String name)
{
    assign(name);
    float v = getValue();
    setValue(&v);
}
