// from server: 59% by atomic.potato
struct DecalTool {
    void* field_38;
};

extern "C" void* __cdecl sub_4A01E0(void*);
extern "C" void* __stdcall sub_983448(void*, int, int, int, int);
extern "C" void __fastcall sub_4BE3E0(void*);

void* __cdecl func_722DC0(DecalTool* obj) {
    if (!obj) {
        return 0;
    }

    void* v1 = obj->field_38;
    if (!v1) {
        v1 = obj;
    } else {
        void* v2 = *(void**)((char*)v1 + 0x38);
        if (v2) {
            v1 = sub_4A01E0(v2);
        } else {
            v1 = v2;
        }
    }

    if (!v1) {
        return 0;
    }

    void* result = sub_983448(v1, 0, 0xD601E8, 0xD65108, 0);
    if (result != 0) {
        sub_4BE3E0(result);
    }
    return result;
}
