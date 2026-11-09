// from server: 100% by Yeetserama
// roc 2011-06 0044def0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0044def0
//
// 0044def0  6aff                 push -1
// 0044def2  68491a9d00           push 0x9d1a49
// 0044def7  64a100000000         mov eax, dword ptr fs:[0]
// 0044defd  50                   push eax
// 0044defe  64892500000000       mov dword ptr fs:[0], esp
// 0044df05  51                   push ecx
// 0044df06  56                   push esi
// 0044df07  8bf1                 mov esi, ecx
// 0044df09  51                   push ecx
// 0044df0a  8d44241c             lea eax, [esp + 0x1c]
// 0044df0e  8bcc                 mov ecx, esp
// 0044df10  89642408             mov dword ptr [esp + 8], esp
// 0044df14  50                   push eax
// 0044df15  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044df1d  ff15e42da400         call dword ptr [0xa42de4]
// 0044df23  8bce                 mov ecx, esi
// 0044df25  e876bb4200           call 0x879aa0
// 0044df2a  8b16                 mov edx, dword ptr [esi]
// 0044df2c  8b82f4000000         mov eax, dword ptr [edx + 0xf4]
// 0044df32  8bce                 mov ecx, esi
// 0044df34  ffd0                 call eax
// 0044df36  8d4c2404             lea ecx, [esp + 4]
// 0044df3a  51                   push ecx
// 0044df3b  8bce                 mov ecx, esi
// 0044df3d  89442408             mov dword ptr [esp + 8], eax
// 0044df41  e8eaecffff           call 0x44cc30
// 0044df46  8d4c2418             lea ecx, [esp + 0x18]
// 0044df4a  ff15082ea400         call dword ptr [0xa42e08]
// 0044df50  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044df54  64890d00000000       mov dword ptr fs:[0], ecx
// 0044df5b  5e                   pop esi
// 0044df5c  83c410               add esp, 0x10
// 0044df5f  c20400               ret 4
// copied from an identical function in another client (function ?f@XItem@ns_ROCX000018@@QAEXUString@2@@Z)

namespace ns_ROCX000018 {
// from server: 100% by colin
// from server: 34% by colin
// roc 2008-06 00441770  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00441770
//
// 00441770  6aff                 push -1
// 00441772  6899037c00           push 0x7c0399
// 00441777  64a100000000         mov eax, dword ptr fs:[0]
// 0044177d  50                   push eax
// 0044177e  64892500000000       mov dword ptr fs:[0], esp
// 00441785  51                   push ecx
// 00441786  56                   push esi
// 00441787  8bf1                 mov esi, ecx
// 00441789  51                   push ecx
// 0044178a  8d44241c             lea eax, [esp + 0x1c]
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
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
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
