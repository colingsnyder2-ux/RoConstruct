// from server: 100% by Yeetserama
// roc 2011-06 0044d970  unit: HVCXTPPropertyGridItem::?$XItem  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0044d970
//
// 0044d970  6aff                 push -1
// 0044d972  68491a9d00           push 0x9d1a49
// 0044d977  64a100000000         mov eax, dword ptr fs:[0]
// 0044d97d  50                   push eax
// 0044d97e  64892500000000       mov dword ptr fs:[0], esp
// 0044d985  51                   push ecx
// 0044d986  56                   push esi
// 0044d987  8bf1                 mov esi, ecx
// 0044d989  51                   push ecx
// 0044d98a  8d44241c             lea eax, [esp + 0x1c]
// 0044d98e  8bcc                 mov ecx, esp
// 0044d990  89642408             mov dword ptr [esp + 8], esp
// 0044d994  50                   push eax
// 0044d995  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044d99d  ff15e42da400         call dword ptr [0xa42de4]
// 0044d9a3  8bce                 mov ecx, esi
// 0044d9a5  e8f6c04200           call 0x879aa0
// 0044d9aa  8b16                 mov edx, dword ptr [esi]
// 0044d9ac  8b82e4000000         mov eax, dword ptr [edx + 0xe4]
// 0044d9b2  8bce                 mov ecx, esi
// 0044d9b4  ffd0                 call eax
// 0044d9b6  8d4c2404             lea ecx, [esp + 4]
// 0044d9ba  51                   push ecx
// 0044d9bb  8bce                 mov ecx, esi
// 0044d9bd  89442408             mov dword ptr [esp + 8], eax
// 0044d9c1  e80aeeffff           call 0x44c7d0
// 0044d9c6  8d4c2418             lea ecx, [esp + 0x18]
// 0044d9ca  ff15082ea400         call dword ptr [0xa42e08]
// 0044d9d0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044d9d4  64890d00000000       mov dword ptr fs:[0], ecx
// 0044d9db  5e                   pop esi
// 0044d9dc  83c410               add esp, 0x10
// 0044d9df  c20400               ret 4
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
