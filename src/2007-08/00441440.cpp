// from server: 100% by Yeetserama
// roc 2007-08 00441440  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00441440
//
// 00441440  6aff                 push -1
// 00441442  6899ef7300           push 0x73ef99
// 00441447  64a100000000         mov eax, dword ptr fs:[0]
// 0044144d  50                   push eax
// 0044144e  51                   push ecx
// 0044144f  56                   push esi
// 00441450  a188518b00           mov eax, dword ptr [0x8b5188]
// 00441455  33c4                 xor eax, esp
// 00441457  50                   push eax
// 00441458  8d44240c             lea eax, [esp + 0xc]
// 0044145c  64a300000000         mov dword ptr fs:[0], eax
// 00441462  8bf1                 mov esi, ecx
// 00441464  51                   push ecx
// 00441465  8d442420             lea eax, [esp + 0x20]
// 00441469  8bcc                 mov ecx, esp
// 0044146b  8964240c             mov dword ptr [esp + 0xc], esp
// 0044146f  50                   push eax
// 00441470  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00441478  ff1574dd7700         call dword ptr [0x77dd74]
// 0044147e  8bce                 mov ecx, esi
// 00441480  e87b722500           call 0x698700
// 00441485  8b16                 mov edx, dword ptr [esi]
// 00441487  8b82f4000000         mov eax, dword ptr [edx + 0xf4]
// 0044148d  8bce                 mov ecx, esi
// 0044148f  ffd0                 call eax
// 00441491  8d4c2408             lea ecx, [esp + 8]
// 00441495  51                   push ecx
// 00441496  8bce                 mov ecx, esi
// 00441498  8944240c             mov dword ptr [esp + 0xc], eax
// 0044149c  e88ff3ffff           call 0x440830
// 004414a1  8d4c241c             lea ecx, [esp + 0x1c]
// 004414a5  ff15bcdd7700         call dword ptr [0x77ddbc]
// 004414ab  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004414af  64890d00000000       mov dword ptr fs:[0], ecx
// 004414b6  59                   pop ecx
// 004414b7  5e                   pop esi
// 004414b8  83c410               add esp, 0x10
// 004414bb  c20400               ret 4
// copied from an identical function in another client (function ?f@XItem@ns_ROCX000009@@QAEXUString@2@@Z)

namespace ns_ROCX000009 {
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
