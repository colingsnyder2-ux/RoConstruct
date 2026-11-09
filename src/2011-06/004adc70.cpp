// from server: 45% by atomic.potato
extern "C" void* __cdecl sub_4adb70(void*);

struct VPlayerRefPropDescriptor {
    char pad[0x20];
    void* field20;
    void* method(void* a, void* b);
};

void* VPlayerRefPropDescriptor::method(void* a, void* b) {
    void* v = a ? sub_4adb70(a) : 0;
    void* p = v;
    void* ecx = field20;
    void* vt = *(void**)ecx;
    void* fn = *(void**)((char*)vt + 0xc);
    return ((void* (__thiscall*)(void*, void*, void*))fn)(ecx, b, p);
}
