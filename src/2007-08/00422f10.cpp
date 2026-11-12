// from server: 95% by EspClaude
// from server: 42% by colin
// roc 2007-08 00422f10  unit: CRobloxTreeCtrlNode  size: 325 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00422f10
//
// 00422f10  6aff                 push -1
// 00422f12  68c0bf7300           push 0x73bfc0
// 00422f17  64a100000000         mov eax, dword ptr fs:[0]
// 00422f1d  50                   push eax
// 00422f1e  83ec1c               sub esp, 0x1c
// 00422f21  53                   push ebx
// 00422f22  55                   push ebp
// 00422f23  56                   push esi
// 00422f24  57                   push edi
// 00422f25  a188518b00           mov eax, dword ptr [0x8b5188]
// 00422f2a  33c4                 xor eax, esp
// 00422f2c  50                   push eax
// 00422f2d  8d442430             lea eax, [esp + 0x30]
// 00422f31  64a300000000         mov dword ptr fs:[0], eax
// 00422f37  8bf1                 mov esi, ecx
// 00422f39  8b7e28               mov edi, dword ptr [esi + 0x28]
// 00422f3c  81c7b0000000         add edi, 0xb0
// 00422f42  8bcf                 mov ecx, edi
// 00422f44  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00422f4c  897c2428             mov dword ptr [esp + 0x28], edi
// 00422f50  e8fb273000           call 0x725750
// 00422f55  b001                 mov al, 1
// 00422f57  8844242c             mov byte ptr [esp + 0x2c], al
// 00422f5b  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 00422f5e  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 00422f62  88442438             mov byte ptr [esp + 0x38], al
// 00422f66  8d442414             lea eax, [esp + 0x14]
// 00422f6a  50                   push eax
// 00422f6b  81c198000000         add ecx, 0x98
// 00422f71  896c2418             mov dword ptr [esp + 0x18], ebp
// 00422f75  e8a642feff           call 0x407220
// 00422f7a  8d4c2414             lea ecx, [esp + 0x14]
// 00422f7e  896c2414             mov dword ptr [esp + 0x14], ebp
// 00422f82  51                   push ecx
// 00422f83  8d542420             lea edx, [esp + 0x20]
// 00422f87  8d6e0c               lea ebp, [esi + 0xc]
// 00422f8a  52                   push edx
// 00422f8b  8bcd                 mov ecx, ebp
// 00422f8d  e82ec50200           call 0x44f4c0
// 00422f92  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00422f96  85db                 test ebx, ebx
// 00422f98  8b4504               mov eax, dword ptr [ebp + 4]
// 00422f9b  89442418             mov dword ptr [esp + 0x18], eax
// 00422f9f  7404                 je 0x422fa5
// 00422fa1  3bdd                 cmp ebx, ebp
// 00422fa3  7406                 je 0x422fab
// 00422fa5  ff15d8e67700         call dword ptr [0x77e6d8]
// 00422fab  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00422faf  3b6c2418             cmp ebp, dword ptr [esp + 0x18]
// 00422fb3  7426                 je 0x422fdb
// 00422fb5  85db                 test ebx, ebx
// 00422fb7  7506                 jne 0x422fbf
// 00422fb9  ff15d8e67700         call dword ptr [0x77e6d8]
// 00422fbf  3b6b04               cmp ebp, dword ptr [ebx + 4]
// 00422fc2  7506                 jne 0x422fca
// 00422fc4  ff15d8e67700         call dword ptr [0x77e6d8]
// 00422fca  83c510               add ebp, 0x10
// 00422fcd  55                   push ebp
// 00422fce  8d4c2420             lea ecx, [esp + 0x20]
// 00422fd2  51                   push ecx
// 00422fd3  8d4e18               lea ecx, [esi + 0x18]
// 00422fd6  e885660800           call 0x4a9660
// 00422fdb  8d542444             lea edx, [esp + 0x44]
// 00422fdf  52                   push edx
// 00422fe0  8d4e30               lea ecx, [esi + 0x30]
// 00422fe3  e8e8efffff           call 0x421fd0
// 00422fe8  8bcf                 mov ecx, edi
// 00422fea  c644243800           mov byte ptr [esp + 0x38], 0
// 00422fef  e87c273000           call 0x725770
// 00422ff4  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 00422ff7  8b01                 mov eax, dword ptr [ecx]
// 00422ff9  8b9054010000         mov edx, dword ptr [eax + 0x154]
// 00422fff  83c6f8               add esi, -8
// 00423002  56                   push esi
// 00423003  ffd2                 call edx
// 00423005  8b742448             mov esi, dword ptr [esp + 0x48]
// 00423009  85f6                 test esi, esi
// 0042300b  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 00423013  742a                 je 0x42303f
// 00423015  8d4604               lea eax, [esi + 4]
// 00423018  83c9ff               or ecx, 0xffffffff
// 0042301b  f00fc108             lock xadd dword ptr [eax], ecx
// 0042301f  751e                 jne 0x42303f
// 00423021  8b16                 mov edx, dword ptr [esi]
// 00423023  8b4204               mov eax, dword ptr [edx + 4]
// 00423026  8bce                 mov ecx, esi
// 00423028  ffd0                 call eax
// 0042302a  8d4e08               lea ecx, [esi + 8]
// 0042302d  83caff               or edx, 0xffffffff
// 00423030  f00fc111             lock xadd dword ptr [ecx], edx
// 00423034  7509                 jne 0x42303f
// 00423036  8b06                 mov eax, dword ptr [esi]
// 00423038  8b5008               mov edx, dword ptr [eax + 8]
// 0042303b  8bce                 mov ecx, esi
// 0042303d  ffd2                 call edx
// 0042303f  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00423043  64890d00000000       mov dword ptr fs:[0], ecx
// 0042304a  59                   pop ecx
// 0042304b  5f                   pop edi
// 0042304c  5e                   pop esi
// 0042304d  5d                   pop ebp
// 0042304e  5b                   pop ebx
// 0042304f  83c428               add esp, 0x28
// 00423052  c20c00               ret 0xc

#include <map>
#include <set>

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;

    volatile long strong;
    volatile long weak;

    void release();
    void releaseWeak();
};

inline void Control::releaseWeak()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        releaseWeak();
    }
}

struct Object {};
struct Instance : Object {};

struct InstancePtr
{
    Instance* px;
    Control* pn;
    ~InstancePtr()
    {
        if (pn)
            pn->release();
    }
    Instance* get() const { return px; }
};

bool operator<(const InstancePtr&, const InstancePtr&);

struct Mutex
{
    void do_lock();
    void do_unlock();
};

struct ScopedLock
{
    Mutex& m;
    bool locked;

    explicit ScopedLock(Mutex& mx) : m(mx), locked(false)
    {
        lock();
    }
    ~ScopedLock()
    {
        if (locked)
            unlock();
    }
    void lock()
    {
        m.do_lock();
        locked = true;
    }
    void unlock()
    {
        m.do_unlock();
        locked = false;
    }
};

struct CRobloxTreeCtrlNode;
struct TreeItem;

struct TreeCtrl
{
    void* vtable_pad[0x154 / 4];
};

struct Primary
{
    virtual ~Primary();
    int pad;
};

struct Model
{
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
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void notify(CRobloxTreeCtrlNode*);
    char pad[0x94];
    std::set<Object*> instances;
    char pad2[0xb0 - 0x98 - sizeof(std::set<Object*>)];
    Mutex mutex;
};

struct ChildObserver
{
    virtual void onChildRemoved(int, InstancePtr) = 0;
};

struct CRobloxTreeCtrlNode;


struct CRobloxTreeCtrlNode : Primary, ChildObserver
{
    char pad[8];
    std::map<Object*, TreeItem*> items;
    std::set<TreeItem*> dirty;
    char pad3[4];
    Model* model;
    char pad4[4];
    std::set<InstancePtr> children;

    virtual void onChildRemoved(int, InstancePtr);
};

struct ModelWithVirtual;

void CRobloxTreeCtrlNode::onChildRemoved(int, InstancePtr child)
{
    {
        Instance* instance = child.get();
        ScopedLock lock(model->mutex);
        model->instances.erase(instance);
        std::map<Object*, TreeItem*>::iterator it = items.find(instance);
        if (it != items.end())
            dirty.insert(it->second);
        children.erase(child);
    }
    model->notify(this);
}
