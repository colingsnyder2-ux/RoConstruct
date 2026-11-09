// from server: 100% by Yeetserama
// roc 2007-08 004412f0  unit: G3D::VVector3::?$XItem  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004412f0
//
// 004412f0  6aff                 push -1
// 004412f2  68f9ef7300           push 0x73eff9
// 004412f7  64a100000000         mov eax, dword ptr fs:[0]
// 004412fd  50                   push eax
// 004412fe  83ec10               sub esp, 0x10
// 00441301  56                   push esi
// 00441302  a188518b00           mov eax, dword ptr [0x8b5188]
// 00441307  33c4                 xor eax, esp
// 00441309  50                   push eax
// 0044130a  8d442418             lea eax, [esp + 0x18]
// 0044130e  64a300000000         mov dword ptr fs:[0], eax
// 00441314  8bf1                 mov esi, ecx
// 00441316  51                   push ecx
// 00441317  8d44242c             lea eax, [esp + 0x2c]
// 0044131b  8bcc                 mov ecx, esp
// 0044131d  8964240c             mov dword ptr [esp + 0xc], esp
// 00441321  50                   push eax
// 00441322  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0044132a  ff1574dd7700         call dword ptr [0x77dd74]
// 00441330  8bce                 mov ecx, esi
// 00441332  e8c9732500           call 0x698700
// 00441337  8b16                 mov edx, dword ptr [esi]
// 00441339  8b92e4000000         mov edx, dword ptr [edx + 0xe4]
// 0044133f  8d44240c             lea eax, [esp + 0xc]
// 00441343  50                   push eax
// 00441344  8bce                 mov ecx, esi
// 00441346  ffd2                 call edx
// 00441348  50                   push eax
// 00441349  8bce                 mov ecx, esi
// 0044134b  e8f0f0ffff           call 0x440440
// 00441350  8d4c2428             lea ecx, [esp + 0x28]
// 00441354  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0044135a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044135e  64890d00000000       mov dword ptr fs:[0], ecx
// 00441365  59                   pop ecx
// 00441366  5e                   pop esi
// 00441367  83c41c               add esp, 0x1c
// 0044136a  c20400               ret 4
// copied from an identical function in another client (function ?update@Item@ns_ROCX000007@@QAEXUText@2@@Z)

namespace ns_ROCX000007 {
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
