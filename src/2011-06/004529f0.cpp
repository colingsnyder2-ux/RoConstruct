// from server: 73% by atomic.potato
struct CRenderSettings_W4FrameRateManagerMode_EnumDesc {
    unsigned int field_24;
    int* field_88;

    bool __thiscall func(int arg1, int arg2, int* arg3);
};

extern "C" void* __cdecl func_80a05e(int);

bool CRenderSettings_W4FrameRateManagerMode_EnumDesc::func(int arg1, int arg2, int* arg3) {
    int value;
    bool result;
    if (arg1 < this->field_24) {
        value = this->field_88[arg1];
        result = true;
    } else {
        value = arg2;
        result = false;
    }

    void* allocated = func_80a05e(8);
    if (allocated) {
        *(int*)allocated = 0xA6CBDC;
        *(int*)((char*)allocated + 4) = value;
    } else {
        allocated = 0;
    }

    if (arg3 != &arg2) {
        int* temp = *(int**)arg3;
        *arg3 = (int)allocated;
        if (temp) {
            int* vtable = *(int**)temp;
            ((void(__stdcall*)(int))vtable[0])(1);
        }
    }

    return result;
}
