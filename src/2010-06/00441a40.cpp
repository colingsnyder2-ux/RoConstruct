// from server: 100% by Yeetserama
// roc 2010-06 00441a40  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00441a40
//
// 00441a40  6aff                 push -1
// 00441a42  6819119800           push 0x981119
// 00441a47  64a100000000         mov eax, dword ptr fs:[0]
// 00441a4d  50                   push eax
// 00441a4e  64892500000000       mov dword ptr fs:[0], esp
// 00441a55  51                   push ecx
// 00441a56  56                   push esi
// 00441a57  8bf1                 mov esi, ecx
// 00441a59  51                   push ecx
// 00441a5a  8d44241c             lea eax, [esp + 0x1c]
// 00441a5e  8bcc                 mov ecx, esp
// 00441a60  89642408             mov dword ptr [esp + 8], esp
// 00441a64  50                   push eax
// 00441a65  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00441a6d  ff15c4ce9e00         call dword ptr [0x9ecec4]
// 00441a73  8bce                 mov ecx, esi
// 00441a75  e806783d00           call 0x819280
// 00441a7a  8b16                 mov edx, dword ptr [esi]
// 00441a7c  8b82f4000000         mov eax, dword ptr [edx + 0xf4]
// 00441a82  8bce                 mov ecx, esi
// 00441a84  ffd0                 call eax
// 00441a86  8d4c2404             lea ecx, [esp + 4]
// 00441a8a  51                   push ecx
// 00441a8b  8bce                 mov ecx, esi
// 00441a8d  89442408             mov dword ptr [esp + 8], eax
// 00441a91  e80ae8ffff           call 0x4402a0
// 00441a96  8d4c2418             lea ecx, [esp + 0x18]
// 00441a9a  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00441aa0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00441aa4  64890d00000000       mov dword ptr fs:[0], ecx
// 00441aab  5e                   pop esi
// 00441aac  83c410               add esp, 0x10
// 00441aaf  c20400               ret 4
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
