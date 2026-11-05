// from server: 54% by colin
// roc 2007-08 004cd670  unit: G3D::_WeakPtr  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004cd670
//
// 004cd670  8b01                 mov eax, dword ptr [ecx]
// 004cd672  ff6020               jmp dword ptr [eax + 0x20]

struct G3D__WeakPtr {
    char pad0[32];
    int m_ptr;
    int f();
};

int G3D__WeakPtr::f() {
    return *(int*)(*(int*)this + 0x20);
}
