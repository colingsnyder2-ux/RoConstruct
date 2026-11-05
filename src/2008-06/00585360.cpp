// from server: 100% by tester
struct RefPropDescriptor {
    void* getset;
    void* getValue(void* object);
};

void* RefPropDescriptor::getValue(void* object) {
    void* gs = *(void**)((char*)this + 0x1c);
    void** vtbl = *(void***)gs;
    void* fn = vtbl[2];
    void* result = ((void* (__thiscall*)(void*, void*))fn)(gs, object);
    if (result) {
        return (char*)result + 0x14;
    }
    return 0;
}
