// from server: 72% by Intel
struct ModelInstance {
    void func(void* p);
};

void __thiscall ModelInstance::func(void* p) {
    ((void(__thiscall*)(void*, void*))0x6847d0)(this, p);
    ((void(__thiscall*)(void*))0x675c40)((char*)this + 0x90);
    *(int*)((char*)this + 0xC4) = 0;
}
