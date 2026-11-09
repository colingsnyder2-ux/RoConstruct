// from server: 69% by atomic.potato
struct VPlayerRefPropDescriptor {
    char pad0[0x20];
    void* field20;
    void sub_4FFF90(int, int);
};

extern "C" void* __cdecl sub_4FFDF0(void*);

void VPlayerRefPropDescriptor::sub_4FFF90(int a, int b) {
    void* v;
    if (b) {
        v = sub_4FFDF0((void*)b);
    } else {
        v = 0;
    }
    void* p = field20;
    void** pp = (void**)p;
    void* fn = *(void**)((char*)*pp + 0x10);
    void* arg = v;
    ((void (__stdcall*)(void*, void*))fn)(p, arg);
}
