// from server: 100% by Yeetserama
// roc 2007-08 00441050  unit: MVCXTPPropertyGridItem::?$XItem  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00441050
//
// 00441050  6aff                 push -1
// 00441052  6899ef7300           push 0x73ef99
// 00441057  64a100000000         mov eax, dword ptr fs:[0]
// 0044105d  50                   push eax
// 0044105e  51                   push ecx
// 0044105f  56                   push esi
// 00441060  a188518b00           mov eax, dword ptr [0x8b5188]
// 00441065  33c4                 xor eax, esp
// 00441067  50                   push eax
// 00441068  8d44240c             lea eax, [esp + 0xc]
// 0044106c  64a300000000         mov dword ptr fs:[0], eax
// 00441072  8bf1                 mov esi, ecx
// 00441074  51                   push ecx
// 00441075  8d442420             lea eax, [esp + 0x20]
// 00441079  8bcc                 mov ecx, esp
// 0044107b  8964240c             mov dword ptr [esp + 0xc], esp
// 0044107f  50                   push eax
// 00441080  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00441088  ff1574dd7700         call dword ptr [0x77dd74]
// 0044108e  8bce                 mov ecx, esi
// 00441090  e86b762500           call 0x698700
// 00441095  8b16                 mov edx, dword ptr [esi]
// 00441097  8b82e4000000         mov eax, dword ptr [edx + 0xe4]
// 0044109d  8bce                 mov ecx, esi
// 0044109f  ffd0                 call eax
// 004410a1  d95c2408             fstp dword ptr [esp + 8]
// 004410a5  8d4c2408             lea ecx, [esp + 8]
// 004410a9  51                   push ecx
// 004410aa  8bce                 mov ecx, esi
// 004410ac  e88ff3ffff           call 0x440440
// 004410b1  8d4c241c             lea ecx, [esp + 0x1c]
// 004410b5  ff15bcdd7700         call dword ptr [0x77ddbc]
// 004410bb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004410bf  64890d00000000       mov dword ptr fs:[0], ecx
// 004410c6  59                   pop ecx
// 004410c7  5e                   pop esi
// 004410c8  83c410               add esp, 0x10
// 004410cb  c20400               ret 4
// copied from an identical function in another client (function ?f@XItem@ns_ROCX000002@@QAEXUString@2@@Z)

namespace ns_ROCX000002 {
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
}
