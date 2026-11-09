// from server: 100% by Intel
struct OgreRbxMeshPartAdapter {
    int GetSomething();
};

int OgreRbxMeshPartAdapter::GetSomething() {
    void* obj = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x44);
    int (__thiscall *func)(void*) = *reinterpret_cast<int (__thiscall **)(void*)>(*reinterpret_cast<void***>(obj) + 0x30 / 4);
    return func(obj);
}
