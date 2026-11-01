// from server: 82% by atomic.potato
struct PartInstance {
    char pad[0x168];
    void* ptr;
    void method(const char* name);
};

extern "C" int __cdecl sub_598AA0(void* a, const char* b);
extern "C" int __stdcall sub_9EA458(const char* a, const char* b);
extern "C" void __stdcall sub_677980(void* p, int v);

void PartInstance::method(const char* name) {
    sub_598AA0(this, name);
    int r = sub_9EA458(name, "Torso");
    void* p = *(void**)((char*)this + 0x168);
    if (r) {
        sub_677980(p, 1);
    } else {
        sub_677980(p, 0);
    }
}
