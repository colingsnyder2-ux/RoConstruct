// from server: 100% by EspClaude
// roc 2009-06 0043bfb0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043bfb0
//
// 0043bfb0  6aff                 push -1
// 0043bfb2  68d9f88400           push 0x84f8d9
// 0043bfb7  64a100000000         mov eax, dword ptr fs:[0]
// 0043bfbd  50                   push eax
// 0043bfbe  64892500000000       mov dword ptr fs:[0], esp
// 0043bfc5  51                   push ecx
// 0043bfc6  56                   push esi
// 0043bfc7  8bf1                 mov esi, ecx
// 0043bfc9  51                   push ecx
// 0043bfca  8d44241c             lea eax, [esp + 0x1c]
// 0043bfce  8bcc                 mov ecx, esp
// 0043bfd0  89642408             mov dword ptr [esp + 8], esp
// 0043bfd4  50                   push eax
// 0043bfd5  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0043bfdd  ff15e4fc8900         call dword ptr [0x89fce4]
// 0043bfe3  8bce                 mov ecx, esi
// 0043bfe5  e8c6e23400           call 0x78a2b0
// 0043bfea  8b16                 mov edx, dword ptr [esi]
// 0043bfec  8b82f4000000         mov eax, dword ptr [edx + 0xf4]
// 0043bff2  8bce                 mov ecx, esi
// 0043bff4  ffd0                 call eax
// 0043bff6  8d4c2404             lea ecx, [esp + 4]
// 0043bffa  51                   push ecx
// 0043bffb  8bce                 mov ecx, esi
// 0043bffd  89442408             mov dword ptr [esp + 8], eax
// 0043c001  e88aebffff           call 0x43ab90
// 0043c006  8d4c2418             lea ecx, [esp + 0x18]
// 0043c00a  ff1510fd8900         call dword ptr [0x89fd10]
// 0043c010  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043c014  64890d00000000       mov dword ptr fs:[0], ecx
// 0043c01b  5e                   pop esi
// 0043c01c  83c410               add esp, 0x10
// 0043c01f  c20400               ret 4
// copied from an identical function in another client (function ?f@XItem@ns_ROCX00001e@@QAEXUString@2@@Z)

namespace ns_ROCX00001e {
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
