// from server: 100% by Xemicl
// roc 2012-06 0045f920  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0045f920
//
// 0045f920  6aff                 push -1
// 0045f922  6812f6a900           push 0xa9f612
// 0045f927  64a100000000         mov eax, dword ptr fs:[0]
// 0045f92d  50                   push eax
// 0045f92e  64892500000000       mov dword ptr fs:[0], esp
// 0045f935  83ec20               sub esp, 0x20
// 0045f938  56                   push esi
// 0045f939  8bf1                 mov esi, ecx
// 0045f93b  51                   push ecx
// 0045f93c  8d442438             lea eax, [esp + 0x38]
// 0045f940  8bcc                 mov ecx, esp
// 0045f942  89642408             mov dword ptr [esp + 8], esp
// 0045f946  50                   push eax
// 0045f947  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0045f94f  ff158047b200         call dword ptr [0xb24780]
// 0045f955  8bce                 mov ecx, esi
// 0045f957  e8b4265900           call 0x9f2010
// 0045f95c  8b16                 mov edx, dword ptr [esi]
// 0045f95e  8b92e4000000         mov edx, dword ptr [edx + 0xe4]
// 0045f964  8d442408             lea eax, [esp + 8]
// 0045f968  50                   push eax
// 0045f969  8bce                 mov ecx, esi
// 0045f96b  ffd2                 call edx
// 0045f96d  50                   push eax
// 0045f96e  8bce                 mov ecx, esi
// 0045f970  c644243001           mov byte ptr [esp + 0x30], 1
// 0045f975  e806b6ffff           call 0x45af80
// 0045f97a  8d4c2408             lea ecx, [esp + 8]
// 0045f97e  c644242c00           mov byte ptr [esp + 0x2c], 0
// 0045f983  ff153c26b200         call dword ptr [0xb2263c]
// 0045f989  8d4c2434             lea ecx, [esp + 0x34]
// 0045f98d  ff15d047b200         call dword ptr [0xb247d0]
// 0045f993  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0045f997  64890d00000000       mov dword ptr fs:[0], ecx
// 0045f99e  5e                   pop esi
// 0045f99f  83c42c               add esp, 0x2c
// 0045f9a2  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX00001b@@QAEXUHandle@2@@Z)

namespace ns_ROCX00001b {
// from server: 93% by king_originala
// roc 2008-06 004415d0  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004415d0
//
// 004415d0  6aff                 push -1
// 004415d2  68f20a7c00           push 0x7c0af2
// 004415d7  64a100000000         mov eax, dword ptr fs:[0]
// 004415dd  50                   push eax
// 004415de  64892500000000       mov dword ptr fs:[0], esp
// 004415e5  83ec20               sub esp, 0x20
// 004415e8  56                   push esi
// 004415e9  8bf1                 mov esi, ecx
// 004415eb  51                   push ecx
// 004415ec  8d442438             lea eax, [esp + 0x38]
// 004415f0  8bcc                 mov ecx, esp
// 004415f2  89642408             mov dword ptr [esp + 8], esp
// 004415f6  50                   push eax
// 004415f7  c744243400000000     mov dword ptr [esp + 0x34], 0
// 004415ff  ff15d43e8000         call dword ptr [0x803ed4]
// 00441605  8bce                 mov ecx, esi
// 00441607  e8b4042d00           call 0x711ac0
// 0044160c  8b16                 mov edx, dword ptr [esi]
// 0044160e  8b92e4000000         mov edx, dword ptr [edx + 0xe4]
// 00441614  8d442408             lea eax, [esp + 8]
// 00441618  50                   push eax
// 00441619  8bce                 mov ecx, esi
// 0044161b  ffd2                 call edx
// 0044161d  50                   push eax
// 0044161e  8bce                 mov ecx, esi
// 00441620  c644243001           mov byte ptr [esp + 0x30], 1
// 00441625  e8d6e5ffff           call 0x43fc00
// 0044162a  8d4c2408             lea ecx, [esp + 8]
// 0044162e  c644242c00           mov byte ptr [esp + 0x2c], 0
// 00441633  ff1568248000         call dword ptr [0x802468]
// 00441639  8d4c2434             lea ecx, [esp + 0x34]
// 0044163d  ff15143f8000         call dword ptr [0x803f14]
// 00441643  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00441647  64890d00000000       mov dword ptr fs:[0], ecx
// 0044164e  5e                   pop esi
// 0044164f  83c42c               add esp, 0x2c
// 00441652  c20400               ret 4

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