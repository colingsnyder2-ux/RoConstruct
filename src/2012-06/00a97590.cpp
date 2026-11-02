// from server: 21% by Intel
struct AdornBillboarder {
    void* vftable;
    char pad[0x10];
    void* field_14;
    void* field_18;

    void __stdcall func_00a97590(void* arg1, int arg2, void* arg3, void* arg4);
};

extern "C" void* __cdecl _alloca(size_t);

void __stdcall AdornBillboarder::func_00a97590(void* arg1, int arg2, void* arg3, void* arg4) {
    if (!((bool (__thiscall*)(AdornBillboarder*))0xA96EC0)(this))
        return;

    void* buffer = _alloca(arg2 * 12);
    int* local_4 = (int*)buffer;
    int local_8 = 0;

    while (local_8 < arg2) {
        float x = ((float*)arg1)[local_8 * 2];
        float y = -((float*)arg1)[local_8 * 2 + 1];
        float z = 0.0f;

        int* dest = (int*)((char*)buffer + local_8 * 12);
        dest[0] = *(int*)&x;
        dest[1] = *(int*)&y;
        dest[2] = *(int*)&z;

        ++local_8;
    }

    void* field14 = *(void**)((char*)this + 0x14);
    void* field10 = *(void**)((char*)this + 0x10);
    void** vtable = *(void***)field10;
    ((void (__stdcall*)(void*, void*))vtable[0x4C/4])(field10, field14);

    vtable = *(void***)field10;
    ((void (__stdcall*)(void*, void*, void*, int, void*))vtable[0x70/4])(field10, arg4, arg3, arg2, buffer);
}
