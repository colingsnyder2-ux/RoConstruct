// from server: 93% by atomic.potato
struct S {
    char pad0[0x2c];
    unsigned int count;
    char pad1[0x90 - 0x30];
    int* data;
    bool get(unsigned int index, int* out);
};

extern "C" void __stdcall sub_4015a0(void*, void*);
extern "C" void* __stdcall sub_770f90();
extern "C" void __stdcall sub_76e140(int*, int*);

bool S::get(unsigned int index, int* out) {
    int value;
    bool ok;
    if (index < count) {
        value = data[index];
        ok = true;
    } else {
        ok = false;
    }
    sub_4015a0((void*)0x770ff0, (void*)0xe48604);
    void* p = sub_770f90();
    *out = (int)p;
    sub_76e140(out + 1, &value);
    return ok;
}
