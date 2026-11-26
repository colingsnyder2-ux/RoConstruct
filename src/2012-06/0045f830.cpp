// from server: 100% by Xemicl
// roc 2012-06 0045f830  unit: G3D::VColor3::?$XItem  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0045f830
//
// 0045f830  6aff                 push -1
// 0045f832  68e9f5a900           push 0xa9f5e9
// 0045f837  64a100000000         mov eax, dword ptr fs:[0]
// 0045f83d  50                   push eax
// 0045f83e  64892500000000       mov dword ptr fs:[0], esp
// 0045f845  83ec10               sub esp, 0x10
// 0045f848  56                   push esi
// 0045f849  8bf1                 mov esi, ecx
// 0045f84b  51                   push ecx
// 0045f84c  8d442428             lea eax, [esp + 0x28]
// 0045f850  8bcc                 mov ecx, esp
// 0045f852  89642408             mov dword ptr [esp + 8], esp
// 0045f856  50                   push eax
// 0045f857  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0045f85f  ff158047b200         call dword ptr [0xb24780]
// 0045f865  8bce                 mov ecx, esi
// 0045f867  e8a4275900           call 0x9f2010
// 0045f86c  8b16                 mov edx, dword ptr [esi]
// 0045f86e  8b92f0000000         mov edx, dword ptr [edx + 0xf0]
// 0045f874  8d442408             lea eax, [esp + 8]
// 0045f878  50                   push eax
// 0045f879  8bce                 mov ecx, esi
// 0045f87b  ffd2                 call edx
// 0045f87d  50                   push eax
// 0045f87e  8bce                 mov ecx, esi
// 0045f880  e8abb2ffff           call 0x45ab30
// 0045f885  8d4c2424             lea ecx, [esp + 0x24]
// 0045f889  ff15d047b200         call dword ptr [0xb247d0]
// 0045f88f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0045f893  64890d00000000       mov dword ptr fs:[0], ecx
// 0045f89a  5e                   pop esi
// 0045f89b  83c41c               add esp, 0x1c
// 0045f89e  c20400               ret 4
// copied from an identical function in another client (function ?update@Item@ns_ROCX000019@@QAEXUText@2@@Z)

namespace ns_ROCX000019 {
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