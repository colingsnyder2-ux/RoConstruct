// from server: 100% by Yeetserama
// roc 2010-06 00441540  unit: G3D::VColor3::?$XItem  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00441540
//
// 00441540  6aff                 push -1
// 00441542  6819119800           push 0x981119
// 00441547  64a100000000         mov eax, dword ptr fs:[0]
// 0044154d  50                   push eax
// 0044154e  64892500000000       mov dword ptr fs:[0], esp
// 00441555  83ec10               sub esp, 0x10
// 00441558  56                   push esi
// 00441559  8bf1                 mov esi, ecx
// 0044155b  51                   push ecx
// 0044155c  8d442428             lea eax, [esp + 0x28]
// 00441560  8bcc                 mov ecx, esp
// 00441562  89642408             mov dword ptr [esp + 8], esp
// 00441566  50                   push eax
// 00441567  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0044156f  ff15c4ce9e00         call dword ptr [0x9ecec4]
// 00441575  8bce                 mov ecx, esi
// 00441577  e8047d3d00           call 0x819280
// 0044157c  8b16                 mov edx, dword ptr [esi]
// 0044157e  8b92f0000000         mov edx, dword ptr [edx + 0xf0]
// 00441584  8d442408             lea eax, [esp + 8]
// 00441588  50                   push eax
// 00441589  8bce                 mov ecx, esi
// 0044158b  ffd2                 call edx
// 0044158d  50                   push eax
// 0044158e  8bce                 mov ecx, esi
// 00441590  e80bd5ffff           call 0x43eaa0
// 00441595  8d4c2424             lea ecx, [esp + 0x24]
// 00441599  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0044159f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004415a3  64890d00000000       mov dword ptr fs:[0], ecx
// 004415aa  5e                   pop esi
// 004415ab  83c41c               add esp, 0x1c
// 004415ae  c20400               ret 4
// copied from an identical function in another client (function ?update@Item@ns_ROCX000013@@QAEXUText@2@@Z)

namespace ns_ROCX000013 {
// from server: 100% by colin
struct Text;

struct Text {
    void* data;
    __declspec(dllimport) Text(const Text&);
    __declspec(dllimport) ~Text() throw();
};





struct Vector {
    float x, y, z;
};

struct Item {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual Vector getVector();

    void setText(Text);
    void setVector(const Vector&);
    void update(Text);
};

void Item::update(Text value) {
    setText(value);
    setVector(getVector());
}
}
