// from server: 100% by Yeetserama
// roc 2010-06 004415c0  unit: RBX::VBrickColor::?$XItem  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004415c0
//
// 004415c0  6aff                 push -1
// 004415c2  6819119800           push 0x981119
// 004415c7  64a100000000         mov eax, dword ptr fs:[0]
// 004415cd  50                   push eax
// 004415ce  64892500000000       mov dword ptr fs:[0], esp
// 004415d5  51                   push ecx
// 004415d6  56                   push esi
// 004415d7  8bf1                 mov esi, ecx
// 004415d9  51                   push ecx
// 004415da  8d44241c             lea eax, [esp + 0x1c]
// 004415de  8bcc                 mov ecx, esp
// 004415e0  89642408             mov dword ptr [esp + 8], esp
// 004415e4  50                   push eax
// 004415e5  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004415ed  ff15c4ce9e00         call dword ptr [0x9ecec4]
// 004415f3  8bce                 mov ecx, esi
// 004415f5  e8867c3d00           call 0x819280
// 004415fa  8b16                 mov edx, dword ptr [esi]
// 004415fc  8b92f0000000         mov edx, dword ptr [edx + 0xf0]
// 00441602  8d442404             lea eax, [esp + 4]
// 00441606  50                   push eax
// 00441607  8bce                 mov ecx, esi
// 00441609  ffd2                 call edx
// 0044160b  50                   push eax
// 0044160c  8bce                 mov ecx, esi
// 0044160e  e8edd7ffff           call 0x43ee00
// 00441613  8d4c2418             lea ecx, [esp + 0x18]
// 00441617  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0044161d  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00441621  64890d00000000       mov dword ptr fs:[0], ecx
// 00441628  5e                   pop esi
// 00441629  83c410               add esp, 0x10
// 0044162c  c20400               ret 4
// copied from an identical function in another client (function ?update@Item@ns_ROCX000014@@QAEXUText@2@@Z)

namespace ns_ROCX000014 {
// from server: 100% by colin
// from server: 60% by colin
// roc 2008-06 00441560  unit: RBX::VBrickColor::?$XItem  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00441560
//
// 00441560  6aff                 push -1
// 00441562  6899037c00           push 0x7c0399
// 00441567  64a100000000         mov eax, dword ptr fs:[0]
// 0044156d  50                   push eax
// 0044156e  64892500000000       mov dword ptr fs:[0], esp
// 00441575  51                   push ecx
// 00441576  56                   push esi
// 00441577  8bf1                 mov esi, ecx
// 00441579  51                   push ecx
// 0044157a  8d44241c             lea eax, [esp + 0x1c]
// 0044157e  8bcc                 mov ecx, esp
// 00441580  89642408             mov dword ptr [esp + 8], esp
// 00441584  50                   push eax
// 00441585  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044158d  ff15d43e8000         call dword ptr [0x803ed4]
// 00441593  8bce                 mov ecx, esi
// 00441595  e826052d00           call 0x711ac0
// 0044159a  8b16                 mov edx, dword ptr [esi]
// 0044159c  8b92f0000000         mov edx, dword ptr [edx + 0xf0]
// 004415a2  8d442404             lea eax, [esp + 4]
// 004415a6  50                   push eax
// 004415a7  8bce                 mov ecx, esi
// 004415a9  ffd2                 call edx
// 004415ab  50                   push eax
// 004415ac  8bce                 mov ecx, esi
// 004415ae  e8dde2ffff           call 0x43f890
// 004415b3  8d4c2418             lea ecx, [esp + 0x18]
// 004415b7  ff15143f8000         call dword ptr [0x803f14]
// 004415bd  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004415c1  64890d00000000       mov dword ptr fs:[0], ecx
// 004415c8  5e                   pop esi
// 004415c9  83c410               add esp, 0x10
// 004415cc  c20400               ret 4
// from server: 59% by colin
// roc 2008-06 00441560  unit: RBX::VBrickColor::?$XItem  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00441560
//
// 00441560  6aff                 push -1
// 00441562  6899037c00           push 0x7c0399
// 00441567  64a100000000         mov eax, dword ptr fs:[0]
// 0044156d  50                   push eax
// 0044156e  64892500000000       mov dword ptr fs:[0], esp
// 00441575  51                   push ecx
// 00441576  56                   push esi
// 00441577  8bf1                 mov esi, ecx
// 00441579  51                   push ecx
// 0044157a  8d44241c             lea eax, [esp + 0x1c]
struct Text {
    void* data;
    __declspec(dllimport) Text(const Text&);
    __declspec(dllimport) ~Text() throw();
};
struct Color { int value; };
struct Item {
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
    virtual Color getColor();
    void setText(Text);
    void setColor(const Color&);
    void update(Text);
};
void Item::update(Text value) {
    setText(value);
    setColor(getColor());
}
}
