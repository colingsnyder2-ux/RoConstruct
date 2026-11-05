// from server: 35% by colin
struct Sky;

struct Lighting {
    char pad[0x30];
    int field30;
    void* clone(Sky* sky, int unused1, int unused2);
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __stdcall sub_474f70(void* dst, void* src);
extern "C" void __stdcall sub_4fa640(void* dst, void* src);

void* Lighting::clone(Sky* sky, int unused1, int unused2) {
    void* result = 0;
    void* mem = operator_new(0x4c);
    if (mem) {
        void* tmp = 0;
        sub_474f70(&tmp, *(void**)sky);
        sub_4fa640(mem, &tmp);
        result = mem;
    }
    *(int*)((char*)result + 0x30) = this->field30;
    sub_474f70((char*)result + 0x38, *(void**)sky);
    float* f = (float*)sky;
    *(float*)((char*)result + 0x40) = *(float*)f;
    *(float*)((char*)result + 0x44) = *(float*)((char*)f + 4);
    *(float*)((char*)result + 0x48) = *(float*)((char*)f + 8);
    sub_474f70((char*)result + 0x3c, (void*)this);
    return result;
}
