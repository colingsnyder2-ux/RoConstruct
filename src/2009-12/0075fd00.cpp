// from server: 67% by atomic.potato
struct VPVAdornmentRefPropDescriptor {
    char pad0[0x20];
    void* field20;
    void SetValue(void* value, void* out);
};

extern "C" void* __stdcall sub_75FCB0(void* p);

void VPVAdornmentRefPropDescriptor::SetValue(void* value, void* out) {
    void* v;
    if (value) {
        v = sub_75FCB0(value);
    } else {
        v = 0;
    }
    void** obj = (void**)field20;
    void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))obj[4];
    fn(field20, v, out);
}
