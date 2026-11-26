// from server: 100% by Xemicl
// roc 2012-06 0045f7b0  unit: HVCXTPPropertyGridItem::?$XItem  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0045f7b0
//
// 0045f7b0  6aff                 push -1
// 0045f7b2  68e9f5a900           push 0xa9f5e9
// 0045f7b7  64a100000000         mov eax, dword ptr fs:[0]
// 0045f7bd  50                   push eax
// 0045f7be  64892500000000       mov dword ptr fs:[0], esp
// 0045f7c5  51                   push ecx
// 0045f7c6  56                   push esi
// 0045f7c7  8bf1                 mov esi, ecx
// 0045f7c9  51                   push ecx
// 0045f7ca  8d44241c             lea eax, [esp + 0x1c]
// 0045f7ce  8bcc                 mov ecx, esp
// 0045f7d0  89642408             mov dword ptr [esp + 8], esp
// 0045f7d4  50                   push eax
// 0045f7d5  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0045f7dd  ff158047b200         call dword ptr [0xb24780]
// 0045f7e3  8bce                 mov ecx, esi
// 0045f7e5  e826285900           call 0x9f2010
// 0045f7ea  8b16                 mov edx, dword ptr [esi]
// 0045f7ec  8b82e4000000         mov eax, dword ptr [edx + 0xe4]
// 0045f7f2  8bce                 mov ecx, esi
// 0045f7f4  ffd0                 call eax
// 0045f7f6  8d4c2404             lea ecx, [esp + 4]
// 0045f7fa  51                   push ecx
// 0045f7fb  8bce                 mov ecx, esi
// 0045f7fd  89442408             mov dword ptr [esp + 8], eax
// 0045f801  e80ab1ffff           call 0x45a910
// 0045f806  8d4c2418             lea ecx, [esp + 0x18]
// 0045f80a  ff15d047b200         call dword ptr [0xb247d0]
// 0045f810  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0045f814  64890d00000000       mov dword ptr fs:[0], ecx
// 0045f81b  5e                   pop esi
// 0045f81c  83c410               add esp, 0x10
// 0045f81f  c20400               ret 4
// copied from an identical function in another client (function ?f@XItem@ns_ROCX000018@@QAEXUString@2@@Z)

namespace ns_ROCX000018 {
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