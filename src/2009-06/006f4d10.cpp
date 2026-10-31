// from server: 100% by EspClaude
// roc 2009-06 00839230  unit: Ogre::RbxSubEntity::RbxSubEntityShadowRenderable  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00839230
//
// 00839230  8b496c               mov ecx, dword ptr [ecx + 0x8]
// 00839233  8b01                 mov eax, dword ptr [ecx]
// 00839235  8b4010               mov eax, dword ptr [eax + 0x10]
// 00839238  ffe0                 jmp eax

struct OgreRbxMeshPartAdapter {
    int getSomething();
};

int OgreRbxMeshPartAdapter::getSomething() {
    void* obj = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x8);
    void* vtable = *reinterpret_cast<void**>(obj);
    int (__thiscall *func)(void*) = *reinterpret_cast<int (__thiscall**)(void*)>(reinterpret_cast<char*>(vtable) + 0xc);
    return func(obj);
}
