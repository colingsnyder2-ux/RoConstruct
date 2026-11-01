// from server: 100% by Yeetserama
// roc 2007-08 004410d0  unit: HVCXTPPropertyGridItem::?$XItem  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004410d0
//
// 004410d0  6aff                 push -1
// 004410d2  6899ef7300           push 0x73ef99
// 004410d7  64a100000000         mov eax, dword ptr fs:[0]
// 004410dd  50                   push eax
// 004410de  51                   push ecx
// 004410df  56                   push esi
// 004410e0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004410e5  33c4                 xor eax, esp
// 004410e7  50                   push eax
// 004410e8  8d44240c             lea eax, [esp + 0xc]
// 004410ec  64a300000000         mov dword ptr fs:[0], eax
// 004410f2  8bf1                 mov esi, ecx
// 004410f4  51                   push ecx
// 004410f5  8d442420             lea eax, [esp + 0x20]
// 004410f9  8bcc                 mov ecx, esp
// 004410fb  8964240c             mov dword ptr [esp + 0xc], esp
// 004410ff  50                   push eax
// 00441100  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00441108  ff1574dd7700         call dword ptr [0x77dd74]
// 0044110e  8bce                 mov ecx, esi
// 00441110  e8eb752500           call 0x698700
// 00441115  8b16                 mov edx, dword ptr [esi]
// 00441117  8b82e4000000         mov eax, dword ptr [edx + 0xe4]
// 0044111d  8bce                 mov ecx, esi
// 0044111f  ffd0                 call eax
// 00441121  8d4c2408             lea ecx, [esp + 8]
// 00441125  51                   push ecx
// 00441126  8bce                 mov ecx, esi
// 00441128  8944240c             mov dword ptr [esp + 0xc], eax
// 0044112c  e80ff3ffff           call 0x440440
// 00441131  8d4c241c             lea ecx, [esp + 0x1c]
// 00441135  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0044113b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044113f  64890d00000000       mov dword ptr fs:[0], ecx
// 00441146  59                   pop ecx
// 00441147  5e                   pop esi
// 00441148  83c410               add esp, 0x10
// 0044114b  c20400               ret 4
// copied from an identical function in another client (function ?f@XItem@ns_ROCX000003@@QAEXUString@2@@Z)

namespace ns_ROCX000003 {
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
