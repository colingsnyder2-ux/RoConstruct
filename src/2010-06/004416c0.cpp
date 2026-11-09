// from server: 100% by Yeetserama
// roc 2010-06 004416c0  unit: G3D::VVector3::?$XItem  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004416c0
//
// 004416c0  6aff                 push -1
// 004416c2  6819119800           push 0x981119
// 004416c7  64a100000000         mov eax, dword ptr fs:[0]
// 004416cd  50                   push eax
// 004416ce  64892500000000       mov dword ptr fs:[0], esp
// 004416d5  83ec10               sub esp, 0x10
// 004416d8  56                   push esi
// 004416d9  8bf1                 mov esi, ecx
// 004416db  51                   push ecx
// 004416dc  8d442428             lea eax, [esp + 0x28]
// 004416e0  8bcc                 mov ecx, esp
// 004416e2  89642408             mov dword ptr [esp + 8], esp
// 004416e6  50                   push eax
// 004416e7  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004416ef  ff15c4ce9e00         call dword ptr [0x9ecec4]
// 004416f5  8bce                 mov ecx, esi
// 004416f7  e8847b3d00           call 0x819280
// 004416fc  8b16                 mov edx, dword ptr [esi]
// 004416fe  8b92e4000000         mov edx, dword ptr [edx + 0xe4]
// 00441704  8d442408             lea eax, [esp + 8]
// 00441708  50                   push eax
// 00441709  8bce                 mov ecx, esi
// 0044170b  ffd2                 call edx
// 0044170d  50                   push eax
// 0044170e  8bce                 mov ecx, esi
// 00441710  e8bbddffff           call 0x43f4d0
// 00441715  8d4c2424             lea ecx, [esp + 0x24]
// 00441719  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0044171f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00441723  64890d00000000       mov dword ptr fs:[0], ecx
// 0044172a  5e                   pop esi
// 0044172b  83c41c               add esp, 0x1c
// 0044172e  c20400               ret 4
// copied from an identical function in another client (function ?update@Item@ns_ROCX000016@@QAEXUText@2@@Z)

namespace ns_ROCX000016 {
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
