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
