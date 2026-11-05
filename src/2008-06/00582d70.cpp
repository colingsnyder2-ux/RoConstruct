// from server: 100% by nuck16
// roc 2008-06 00582d70  unit: RBX::AttachCameraCommand  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00582d70
//
// 00582d70  64a100000000         mov eax, dword ptr fs:[0]
// 00582d76  6aff                 push -1
// 00582d78  6818117d00           push 0x7d1118
// 00582d7d  50                   push eax
// 00582d7e  64892500000000       mov dword ptr fs:[0], esp
// 00582d85  83ec10               sub esp, 0x10
// 00582d88  56                   push esi
// 00582d89  8bf1                 mov esi, ecx
// 00582d8b  6a01                 push 1
// 00582d8d  8d4e14               lea ecx, [esi + 0x14]
// 00582d90  e82befffff           call 0x581cc0
// 00582d95  8b8054010000         mov eax, dword ptr [eax + 0x154]
// 00582d9b  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00582d9e  2b480c               sub ecx, dword ptr [eax + 0xc]
// 00582da1  c1f903               sar ecx, 3
// 00582da4  85c9                 test ecx, ecx
// 00582da6  7712                 ja 0x582dba
// 00582da8  32c0                 xor al, al
// 00582daa  5e                   pop esi
// 00582dab  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00582daf  64890d00000000       mov dword ptr fs:[0], ecx
// 00582db6  83c41c               add esp, 0x1c
// 00582db9  c3                   ret 
// 00582dba  8b5620               mov edx, dword ptr [esi + 0x20]
// 00582dbd  89542408             mov dword ptr [esp + 8], edx
// 00582dc1  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00582dc9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00582dd1  6a01                 push 1
// 00582dd3  8d4c240c             lea ecx, [esp + 0xc]
// 00582dd7  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00582ddf  e89cefffff           call 0x581d80
// 00582de4  8b884c010000         mov ecx, dword ptr [eax + 0x14c]
// 00582dea  2b8848010000         sub ecx, dword ptr [eax + 0x148]
// 00582df0  8b742410             mov esi, dword ptr [esp + 0x10]
// 00582df4  83e1fc               and ecx, 0xfffffffc
// 00582df7  83f904               cmp ecx, 4
// 00582dfa  0f94442407           sete byte ptr [esp + 7]
// 00582dff  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00582e07  85f6                 test esi, esi
// 00582e09  742a                 je 0x582e35
// 00582e0b  8d5604               lea edx, [esi + 4]
// 00582e0e  83c8ff               or eax, 0xffffffff
// 00582e11  f00fc102             lock xadd dword ptr [edx], eax
// 00582e15  751e                 jne 0x582e35
// 00582e17  8b16                 mov edx, dword ptr [esi]
// 00582e19  8b4204               mov eax, dword ptr [edx + 4]
// 00582e1c  8bce                 mov ecx, esi
// 00582e1e  ffd0                 call eax
// 00582e20  8d4e08               lea ecx, [esi + 8]
// 00582e23  83caff               or edx, 0xffffffff
// 00582e26  f00fc111             lock xadd dword ptr [ecx], edx
// 00582e2a  7509                 jne 0x582e35
// 00582e2c  8b06                 mov eax, dword ptr [esi]
// 00582e2e  8b5008               mov edx, dword ptr [eax + 8]
// 00582e31  8bce                 mov ecx, esi
// 00582e33  ffd2                 call edx
// 00582e35  807c240700           cmp byte ptr [esp + 7], 0
// 00582e3a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00582e3e  0f95c0               setne al
// 00582e41  5e                   pop esi
// 00582e42  64890d00000000       mov dword ptr fs:[0], ecx
// 00582e49  83c41c               add esp, 0x1c
// 00582e4c  c3                   ret 

// roc 2008-06 00582d70  unit: RBX::AttachCameraCommand  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00582d70
//
// 00582d70  64a100000000         mov eax, dword ptr fs:[0]
// 00582d76  6aff                 push -1
// 00582d78  6818117d00           push 0x7d1118
// 00582d7d  50                   push eax
// 00582d7e  64892500000000       mov dword ptr fs:[0], esp
// 00582d85  83ec10               sub esp, 0x10
// 00582d88  56                   push esi
// 00582d89  8bf1                 mov esi, ecx
// 00582d8b  6a01                 push 1
// 00582d8d  8d4e14               lea ecx, [esi + 0x14]
// 00582d90  e82befffff           call 0x581cc0
// 00582d95  8b8054010000         mov eax, dword ptr [eax + 0x154]
// 00582d9b  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00582d9e  2b480c               sub ecx, dword ptr [eax + 0xc]
// 00582da1  c1f903               sar ecx, 3
// 00582da4  85c9                 test ecx, ecx
// 00582da6  7712                 ja 0x582dba
// 00582da8  32c0                 xor al, al
// 00582daa  5e                   pop esi
// 00582dab  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00582daf  64890d00000000       mov dword ptr fs:[0], ecx
// 00582db6  83c41c               add esp, 0x1c
// 00582db9  c3                   ret 
// 00582dba  8b5620               mov edx, dword ptr [esi + 0x20]
// 00582dbd  89542408             mov dword ptr [esp + 8], edx
// 00582dc1  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00582dc9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00582dd1  6a01                 push 1
// 00582dd3  8d4c240c             lea ecx, [esp + 0xc]
// 00582dd7  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00582ddf  e89cefffff           call 0x581d80
// 00582de4  8b884c010000         mov ecx, dword ptr [eax + 0x14c]
// 00582dea  2b8848010000         sub ecx, dword ptr [eax + 0x148]
// 00582df0  8b742410             mov esi, dword ptr [esp + 0x10]
// 00582df4  83e1fc               and ecx, 0xfffffffc
// 00582df7  83f904               cmp ecx, 4
// 00582dfa  0f94442407           sete byte ptr [esp + 7]
// 00582dff  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00582e07  85f6                 test esi, esi
// 00582e09  742a                 je 0x582e35
// 00582e0b  8d5604               lea edx, [esi + 4]
// 00582e0e  83c8ff               or eax, 0xffffffff
// 00582e11  f00fc102             lock xadd dword ptr [edx], eax
// 00582e15  751e                 jne 0x582e35
// 00582e17  8b16                 mov edx, dword ptr [esi]
// 00582e19  8b4204               mov eax, dword ptr [edx + 4]
// 00582e1c  8bce                 mov ecx, esi
// 00582e1e  ffd0                 call eax
// 00582e20  8d4e08               lea ecx, [esi + 8]
// 00582e23  83caff               or edx, 0xffffffff
// 00582e26  f00fc111             lock xadd dword ptr [ecx], edx
// 00582e2a  7509                 jne 0x582e35
// 00582e2c  8b06                 mov eax, dword ptr [esi]
// 00582e2e  8b5008               mov edx, dword ptr [eax + 8]
// 00582e31  8bce                 mov ecx, esi
// 00582e33  ffd2                 call edx
// 00582e35  807c240700           cmp byte ptr [esp + 7], 0
// 00582e3a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00582e3e  0f95c0               setne al
// 00582e41  5e                   pop esi
// 00582e42  64890d00000000       mov dword ptr fs:[0], ecx
// 00582e49  83c41c               add esp, 0x1c
// 00582e4c  c3                   ret 

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Entry {
    void* object;
    void* control;
};

struct EntryList {
    char padding[0xC];
    Entry* first;
    Entry* last;
};

struct Result {
    char padding[0x148];
    void** first;
    void** last;
    void* reserved;
    EntryList* entries;
};

struct ReferenceCount {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;

    void release();
};

inline void ReferenceCount::release() {
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Source {
    void* object;
    void* cached;
    ReferenceCount* control;

    Result* get(bool);
};

struct Temporary {
    void* object;
    void* cached;
    ReferenceCount* volatile control;

    Temporary(void*);
    ~Temporary();
    Result* get(bool);
};

inline Temporary::Temporary(void* value)
    : object(value), cached(0), control(0) {
}

inline Temporary::~Temporary() {
    ReferenceCount* p = control;
    if (p)
        p->release();
}

struct AttachCameraCommand {
    char padding[0x14];
    Source source;
    void* object;

    bool execute();
};

bool AttachCameraCommand::execute() {
    EntryList* entries = source.get(true)->entries;
    if (!((unsigned)(entries->last - entries->first) > 0))
        return false;

    bool ok;
    {
        Temporary temporary(object);
        Result* result = temporary.get(true);
        ok = (unsigned)(result->last - result->first) == 1;
    }
    if (ok) return true;
    return false;
}
