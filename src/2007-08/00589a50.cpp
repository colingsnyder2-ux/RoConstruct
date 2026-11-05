// from server: 51% by colin
struct VStockSound_FactoryProduct {
    void f();
};

extern "C" int __stdcall rand();
extern "C" void __stdcall _invalid_parameter_noinfo();

void VStockSound_FactoryProduct::f() {
    int local10;
    int local14;
    int local18;
    int local1c;
    int local20;
    int local24;
    int local28;
    int local2c;

    int* ebp = (int*)&local1c;
    int* edi = ebp;
    int* esi = (int*)*(int*)((char*)ebp + 4);
    local10 = (int)edi;
    local14 = (int)esi;

    while (1) {
        int* ebx;
        if (edi != 0 && edi != ebp) {
            _invalid_parameter_noinfo();
        }
        ebx = (int*)*(int*)((char*)ebp + 4);
        if (esi == ebx) {
            break;
        }
        if (edi == 0) {
            rand();
        }
        if (esi == (int*)*(int*)((char*)edi + 4)) {
            rand();
        }
        int* ecx = (int*)*(int*)((char*)esi + 0x2c);
        if (*(int*)((char*)ecx + 8) == 0) {
            int r = rand();
            local24 = r;
            float fv = (float)local24;
            fv = fv * *(float*)0x7acfc4;
            if (!(fv < *(float*)0x7acfc0)) {
                if (esi == (int*)*(int*)((char*)edi + 4)) {
                    rand();
                }
                int* ebx2 = (int*)*(int*)((char*)esi + 0x2c);
                int* eax = (int*)*ebx2;
                if (eax != 0) {
                    void* p = eax;
                    ((void (__cdecl*)(void*))0x62fc08)(p);
                    *ebx2 = 0;
                }
                int* edx = &local20;
                ((void (__thiscall*)(void*, int*, int*, int*))0x5895c0)(ebp, edx, esi, edi);
                edi = (int*)*(int*)eax;
                esi = (int*)*(int*)((char*)eax + 4);
                continue;
            }
        }
        ((void (__thiscall*)(void*, int*))0x587ae0)(&local10, &local10);
        esi = (int*)local14;
        edi = (int*)local10;
    }
}
