// from server: 100% by Yeetserama
// roc 2011-06 0044dae0  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0044dae0
//
// 0044dae0  6aff                 push -1
// 0044dae2  68721a9d00           push 0x9d1a72
// 0044dae7  64a100000000         mov eax, dword ptr fs:[0]
// 0044daed  50                   push eax
// 0044daee  64892500000000       mov dword ptr fs:[0], esp
// 0044daf5  83ec20               sub esp, 0x20
// 0044daf8  56                   push esi
// 0044daf9  8bf1                 mov esi, ecx
// 0044dafb  51                   push ecx
// 0044dafc  8d442438             lea eax, [esp + 0x38]
// 0044db00  8bcc                 mov ecx, esp
// 0044db02  89642408             mov dword ptr [esp + 8], esp
// 0044db06  50                   push eax
// 0044db07  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0044db0f  ff15e42da400         call dword ptr [0xa42de4]
// 0044db15  8bce                 mov ecx, esi
// 0044db17  e884bf4200           call 0x879aa0
// 0044db1c  8b16                 mov edx, dword ptr [esi]
// 0044db1e  8b92e4000000         mov edx, dword ptr [edx + 0xe4]
// 0044db24  8d442408             lea eax, [esp + 8]
// 0044db28  50                   push eax
// 0044db29  8bce                 mov ecx, esi
// 0044db2b  ffd2                 call edx
// 0044db2d  50                   push eax
// 0044db2e  8bce                 mov ecx, esi
// 0044db30  c644243001           mov byte ptr [esp + 0x30], 1
// 0044db35  e8a6e3ffff           call 0x44bee0
// 0044db3a  8d4c2408             lea ecx, [esp + 8]
// 0044db3e  c644242c00           mov byte ptr [esp + 0x2c], 0
// 0044db43  ff15d004a400         call dword ptr [0xa404d0]
// 0044db49  8d4c2434             lea ecx, [esp + 0x34]
// 0044db4d  ff15082ea400         call dword ptr [0xa42e08]
// 0044db53  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0044db57  64890d00000000       mov dword ptr fs:[0], ecx
// 0044db5e  5e                   pop esi
// 0044db5f  83c42c               add esp, 0x2c
// 0044db62  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000015@@QAEXUHandle@2@@Z)

namespace ns_ROCX000015 {
struct Handle;
struct Text;

extern void (__thiscall *copyHandle)(Handle*, const Handle&);
extern void (__thiscall *destroyHandle)(Handle*);
extern void (__thiscall *destroyText)(Text*);

struct Handle {
    void* value;
    __declspec(dllimport) Handle(const Handle&);
    __declspec(dllimport) ~Handle() throw();
};

struct Text {
    unsigned char data[28];
    ~Text();
};

struct S {
    virtual void v0();  virtual void v1();  virtual void v2();
    virtual void v3();  virtual void v4();  virtual void v5();
    virtual void v6();  virtual void v7();  virtual void v8();
    virtual void v9();  virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26();
    virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56();
    virtual Text getText();

    void setHandle(Handle);
    void setText(const Text&);
    void f(Handle);
};

__forceinline Text::~Text()
{
    destroyText(this);
}

void S::f(Handle handle)
{
    setHandle(handle);
    setText(getText());
}
}
