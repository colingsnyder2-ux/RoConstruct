// from server: 54% by atomic.potato
struct RBX_MotorFeature;

extern "C" void* __cdecl sub_4287B0(unsigned int);
extern "C" void __cdecl sub_428700(void*);

struct RBX_MotorFeature {
    void sub_4A1C10(void*);
    void* sub_89AF40(void** out, const int* src);
};

void* RBX_MotorFeature::sub_89AF40(void** out, const int* src) {
    void* obj = 0;
    void* mem = sub_4287B0(0x28);
    if (mem) {
        *(int*)((char*)mem + 8) = 0xb607a8;
        *(int*)((char*)mem + 0xc) = 0;
        *(int*)((char*)mem) = 0xbdbee0;
        *(int*)((char*)mem + 8) = 0xbdbed8;
        *(void**)((char*)mem + 0x10) = this;
        *(int*)((char*)mem + 0x18) = src[0];
        *(int*)((char*)mem + 0x1c) = src[1];
        *(int*)((char*)mem + 0x20) = src[2];
        *(int*)((char*)mem + 0x24) = src[3];
        *(int*)((char*)mem) = 0xbdbf9c;
        *(int*)((char*)mem + 8) = 0xbdbf94;
        obj = mem;
    }
    sub_4A1C10(obj);
    *out = obj;
    if (obj) {
        sub_428700((char*)obj + 5);
    }

    return this;
}
