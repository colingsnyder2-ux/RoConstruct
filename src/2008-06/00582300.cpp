// from server: 100% by nuck16
// roc 2008-06 00582300  unit: RBX::CameraCenterCommand  size: 229 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00582300
//
// 00582300  6aff                 push -1
// 00582302  6818117d00           push 0x7d1118
// 00582307  64a100000000         mov eax, dword ptr fs:[0]
// 0058230d  50                   push eax
// 0058230e  64892500000000       mov dword ptr fs:[0], esp
// 00582315  83ec10               sub esp, 0x10
// 00582318  56                   push esi
// 00582319  57                   push edi
// 0058231a  8bf9                 mov edi, ecx
// 0058231c  8b470c               mov eax, dword ptr [edi + 0xc]
// 0058231f  8944240c             mov dword ptr [esp + 0xc], eax
// 00582323  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0058232b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00582333  6a01                 push 1
// 00582335  8d4c2410             lea ecx, [esp + 0x10]
// 00582339  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00582341  e83afaffff           call 0x581d80
// 00582346  8b884c010000         mov ecx, dword ptr [eax + 0x14c]
// 0058234c  2b8848010000         sub ecx, dword ptr [eax + 0x148]
// 00582352  8b742414             mov esi, dword ptr [esp + 0x14]
// 00582356  c1f902               sar ecx, 2
// 00582359  83f901               cmp ecx, 1
// 0058235c  0f9344240b           setae byte ptr [esp + 0xb]
// 00582361  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00582369  85f6                 test esi, esi
// 0058236b  742a                 je 0x582397
// 0058236d  8d5604               lea edx, [esi + 4]
// 00582370  83c8ff               or eax, 0xffffffff
// 00582373  f00fc102             lock xadd dword ptr [edx], eax
// 00582377  751e                 jne 0x582397
// 00582379  8b16                 mov edx, dword ptr [esi]
// 0058237b  8b4204               mov eax, dword ptr [edx + 4]
// 0058237e  8bce                 mov ecx, esi
// 00582380  ffd0                 call eax
// 00582382  8d4e08               lea ecx, [esi + 8]
// 00582385  83caff               or edx, 0xffffffff
// 00582388  f00fc111             lock xadd dword ptr [ecx], edx
// 0058238c  7509                 jne 0x582397
// 0058238e  8b06                 mov eax, dword ptr [esi]
// 00582390  8b5008               mov edx, dword ptr [eax + 8]
// 00582393  8bce                 mov ecx, esi
// 00582395  ffd2                 call edx
// 00582397  807c240b00           cmp byte ptr [esp + 0xb], 0
// 0058239c  7434                 je 0x5823d2
// 0058239e  8b7f0c               mov edi, dword ptr [edi + 0xc]
// 005823a1  8b8788020000         mov eax, dword ptr [edi + 0x288]
// 005823a7  8b5004               mov edx, dword ptr [eax + 4]
// 005823aa  8d8f88020000         lea ecx, [edi + 0x288]
// 005823b0  ffd2                 call edx
// 005823b2  85c0                 test eax, eax
// 005823b4  741c                 je 0x5823d2
// 005823b6  83b8d401000000       cmp dword ptr [eax + 0x1d4], 0
// 005823bd  7513                 jne 0x5823d2
// 005823bf  5f                   pop edi
// 005823c0  b001                 mov al, 1
// 005823c2  5e                   pop esi
// 005823c3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005823c7  64890d00000000       mov dword ptr fs:[0], ecx
// 005823ce  83c41c               add esp, 0x1c
// 005823d1  c3                   ret 
// 005823d2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005823d6  5f                   pop edi
// 005823d7  32c0                 xor al, al
// 005823d9  5e                   pop esi
// 005823da  64890d00000000       mov dword ptr fs:[0], ecx
// 005823e1  83c41c               add esp, 0x1c
// 005823e4  c3                   ret 

// roc 2008-06 00582300  unit: RBX::CameraCenterCommand  size: 229 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00582300
//
// 00582300  6aff                 push -1
// 00582302  6818117d00           push 0x7d1118
// 00582307  64a100000000         mov eax, dword ptr fs:[0]
// 0058230d  50                   push eax
// 0058230e  64892500000000       mov dword ptr fs:[0], esp
// 00582315  83ec10               sub esp, 0x10
// 00582318  56                   push esi
// 00582319  57                   push edi
// 0058231a  8bf9                 mov edi, ecx
// 0058231c  8b470c               mov eax, dword ptr [edi + 0xc]
// 0058231f  8944240c             mov dword ptr [esp + 0xc], eax
// 00582323  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0058232b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00582333  6a01                 push 1
// 00582335  8d4c2410             lea ecx, [esp + 0x10]
// 00582339  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00582341  e83afaffff           call 0x581d80
// 00582346  8b884c010000         mov ecx, dword ptr [eax + 0x14c]
// 0058234c  2b8848010000         sub ecx, dword ptr [eax + 0x148]
// 00582352  8b742414             mov esi, dword ptr [esp + 0x14]
// 00582356  c1f902               sar ecx, 2
// 00582359  83f901               cmp ecx, 1
// 0058235c  0f9344240b           setae byte ptr [esp + 0xb]
// 00582361  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00582369  85f6                 test esi, esi
// 0058236b  742a                 je 0x582397
// 0058236d  8d5604               lea edx, [esi + 4]
// 00582370  83c8ff               or eax, 0xffffffff
// 00582373  f00fc102             lock xadd dword ptr [edx], eax
// 00582377  751e                 jne 0x582397
// 00582379  8b16                 mov edx, dword ptr [esi]
// 0058237b  8b4204               mov eax, dword ptr [edx + 4]
// 0058237e  8bce                 mov ecx, esi
// 00582380  ffd0                 call eax
// 00582382  8d4e08               lea ecx, [esi + 8]
// 00582385  83caff               or edx, 0xffffffff
// 00582388  f00fc111             lock xadd dword ptr [ecx], edx
// 0058238c  7509                 jne 0x582397
// 0058238e  8b06                 mov eax, dword ptr [esi]
// 00582390  8b5008               mov edx, dword ptr [eax + 8]
// 00582393  8bce                 mov ecx, esi
// 00582395  ffd2                 call edx
// 00582397  807c240b00           cmp byte ptr [esp + 0xb], 0
// 0058239c  7434                 je 0x5823d2
// 0058239e  8b7f0c               mov edi, dword ptr [edi + 0xc]
// 005823a1  8b8788020000         mov eax, dword ptr [edi + 0x288]
// 005823a7  8b5004               mov edx, dword ptr [eax + 4]
// 005823aa  8d8f88020000         lea ecx, [edi + 0x288]
// 005823b0  ffd2                 call edx
// 005823b2  85c0                 test eax, eax
// 005823b4  741c                 je 0x5823d2
// 005823b6  83b8d401000000       cmp dword ptr [eax + 0x1d4], 0
// 005823bd  7513                 jne 0x5823d2
// 005823bf  5f                   pop edi
// 005823c0  b001                 mov al, 1
// 005823c2  5e                   pop esi
// 005823c3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005823c7  64890d00000000       mov dword ptr fs:[0], ecx
// 005823ce  83c41c               add esp, 0x1c
// 005823d1  c3                   ret 
// 005823d2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005823d6  5f                   pop edi
// 005823d7  32c0                 xor al, al
// 005823d9  5e                   pop esi
// 005823da  64890d00000000       mov dword ptr fs:[0], ecx
// 005823e1  83c41c               add esp, 0x1c
// 005823e4  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Selection {
    char padding[0x148];
    void** first;
    void** last;
};

struct Camera {
    char padding[0x1d4];
    int state;
};

struct CameraSource {
    virtual void unused();
    virtual Camera* get();
};

struct World {
    char padding[0x288];
    CameraSource camera;
};

struct SelectionAccess {
    World* world;
    Selection* object;
    Control* volatile control;

    SelectionAccess(World*);
    ~SelectionAccess();
    Selection* get(bool);
};

inline SelectionAccess::SelectionAccess(World* value)
    : world(value), object(0), control(0) {
}

inline SelectionAccess::~SelectionAccess() {
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct CameraCenterCommand {
    char padding[12];
    World* world;
    bool enabled();
};

bool CameraCenterCommand::enabled() {
    bool selected;
    {
        SelectionAccess access(world);
        Selection* selection = access.get(true);
        selected = static_cast<unsigned int>(
            selection->last - selection->first) >= 1;
    }

    if (selected) {
        Camera* camera = world->camera.get();
        if (camera && camera->state == 0)
            return true;
    }
    return false;
}
