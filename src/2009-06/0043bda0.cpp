// from server: 100% by EspClaude
// roc 2009-06 0043bda0  unit: G3D::VVector3::?$XItem  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043bda0
//
// 0043bda0  6aff                 push -1
// 0043bda2  68d9f88400           push 0x84f8d9
// 0043bda7  64a100000000         mov eax, dword ptr fs:[0]
// 0043bdad  50                   push eax
// 0043bdae  64892500000000       mov dword ptr fs:[0], esp
// 0043bdb5  83ec10               sub esp, 0x10
// 0043bdb8  56                   push esi
// 0043bdb9  8bf1                 mov esi, ecx
// 0043bdbb  51                   push ecx
// 0043bdbc  8d442428             lea eax, [esp + 0x28]
// 0043bdc0  8bcc                 mov ecx, esp
// 0043bdc2  89642408             mov dword ptr [esp + 8], esp
// 0043bdc6  50                   push eax
// 0043bdc7  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0043bdcf  ff15e4fc8900         call dword ptr [0x89fce4]
// 0043bdd5  8bce                 mov ecx, esi
// 0043bdd7  e8d4e43400           call 0x78a2b0
// 0043bddc  8b16                 mov edx, dword ptr [esi]
// 0043bdde  8b92e4000000         mov edx, dword ptr [edx + 0xe4]
// 0043bde4  8d442408             lea eax, [esp + 8]
// 0043bde8  50                   push eax
// 0043bde9  8bce                 mov ecx, esi
// 0043bdeb  ffd2                 call edx
// 0043bded  50                   push eax
// 0043bdee  8bce                 mov ecx, esi
// 0043bdf0  e8bbe6ffff           call 0x43a4b0
// 0043bdf5  8d4c2424             lea ecx, [esp + 0x24]
// 0043bdf9  ff1510fd8900         call dword ptr [0x89fd10]
// 0043bdff  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043be03  64890d00000000       mov dword ptr fs:[0], ecx
// 0043be0a  5e                   pop esi
// 0043be0b  83c41c               add esp, 0x1c
// 0043be0e  c20400               ret 4
// copied from an identical function in another client (function ?update@Item@ns_ROCX00001c@@QAEXUText@2@@Z)

namespace ns_ROCX00001c {
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
