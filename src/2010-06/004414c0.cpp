// from server: 100% by Yeetserama
// roc 2010-06 004414c0  unit: HVCXTPPropertyGridItem::?$XItem  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004414c0
//
// 004414c0  6aff                 push -1
// 004414c2  6819119800           push 0x981119
// 004414c7  64a100000000         mov eax, dword ptr fs:[0]
// 004414cd  50                   push eax
// 004414ce  64892500000000       mov dword ptr fs:[0], esp
// 004414d5  51                   push ecx
// 004414d6  56                   push esi
// 004414d7  8bf1                 mov esi, ecx
// 004414d9  51                   push ecx
// 004414da  8d44241c             lea eax, [esp + 0x1c]
// 004414de  8bcc                 mov ecx, esp
// 004414e0  89642408             mov dword ptr [esp + 8], esp
// 004414e4  50                   push eax
// 004414e5  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004414ed  ff15c4ce9e00         call dword ptr [0x9ecec4]
// 004414f3  8bce                 mov ecx, esi
// 004414f5  e8867d3d00           call 0x819280
// 004414fa  8b16                 mov edx, dword ptr [esi]
// 004414fc  8b82e4000000         mov eax, dword ptr [edx + 0xe4]
// 00441502  8bce                 mov ecx, esi
// 00441504  ffd0                 call eax
// 00441506  8d4c2404             lea ecx, [esp + 4]
// 0044150a  51                   push ecx
// 0044150b  8bce                 mov ecx, esi
// 0044150d  89442408             mov dword ptr [esp + 8], eax
// 00441511  e81ad2ffff           call 0x43e730
// 00441516  8d4c2418             lea ecx, [esp + 0x18]
// 0044151a  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00441520  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00441524  64890d00000000       mov dword ptr fs:[0], ecx
// 0044152b  5e                   pop esi
// 0044152c  83c410               add esp, 0x10
// 0044152f  c20400               ret 4
// copied from an identical function in another client (function ?f@XItem@ns_ROCX000012@@QAEXUString@2@@Z)

namespace ns_ROCX000012 {
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
}
