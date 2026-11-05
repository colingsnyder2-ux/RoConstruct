// from server: 25% by Intel
typedef unsigned int DWORD;
typedef void* HDC;

struct Vector {
    void* data;
    DWORD size;
};

struct VModelInstance {
    void* m_vtable;
    char m_padding[80];
    void* m_offset84;
    DWORD m_offset88;

    void* FilteredSelection();
};

extern "C" void* call_0x4015a0(void*, void*, DWORD);
extern "C" void* call_0x6f3830();
extern "C" void call_0x864e70(Vector* out);
extern "C" char call_0x6f49f0();
extern "C" void call_0x67f480();
extern "C" void call_0x6f35a0();
extern "C" void* call_0x6ce510(VModelInstance* self, Vector* in);
extern "C" void call_0x4026a0(void* in, void* out, DWORD type);

DWORD global_0xb9d220;

void* VModelInstance::FilteredSelection() {
    call_0x4015a0(0, (void*)0xe3023c, 0x6f3e10);
    void* list = call_0x6f3830();
    
    DWORD count = this->m_offset88 - (DWORD)this->m_offset84;
    DWORD index = 1; 

    if (index > (count >> 3)) {
        Vector vec;
        vec.data = 0;
        vec.size = 0;
        call_0x864e70(&vec);
        return 0;
    }

    void* item = *(void**)((char*)this->m_offset84 + index * 8);
    if (item == 0) {
        return 0;
    }

    if (!call_0x6f49f0()) {
        return 0;
    }

    if (global_0xb9d220 != 0) {
        call_0x67f480();
    } else {
        call_0x4015a0(0, (void*)0xe30228, 0x6f3d80);
        call_0x6f35a0();
    }

    Vector vec;
    vec.data = (void*)index;
    vec.size = 0;
    call_0x6ce510(this, &vec);

    if (vec.data != 0) {
        void* target = *(void**)((char*)this->m_offset84 + (DWORD)vec.data * 8);
        Vector vec2;
        vec2.data = target;
        vec2.size = 0;
        call_0x4026a0(target, &vec2, 0xFFFFFFFF);
        return target;
    }

    return (void*)0;
}
