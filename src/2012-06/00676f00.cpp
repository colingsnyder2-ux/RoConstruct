// from server: 37% by Intel
extern "C" int __stdcall sub_E5809C(int, int, int);
int __cdecl sub_972290(int, int);

struct XVGfxBinding {
    int* vftable;
    int vftable_func(int);
};

int XVGfxBinding::vftable_func(int index) {
    int this_ptr = (int)this;
    unsigned char global_flag = *(unsigned char*)0xE580B3;
    if (global_flag) {
        int zero = 0;
        if (zero != 0) {}
        int zero2 = 0;
        if (zero2 != 0) {}
        int vftable = *(int*)this_ptr;
        int* array_ptr = (int*)(vftable + index * 4);
        int array_size = *(int*)(*array_ptr + 0xC);
        if (array_size != index) {
            if (*(int*)0xE5809C) {
                sub_E5809C(0xB7B524, 0xB8D8B8, 0x71);
                if (*(unsigned char*)0xE580B3) {
                    return *(int*)(vftable + index * 4);
                }
            }
            sub_972290(0xB8DAB0, *(unsigned char*)0xE580B3);
        }
    }
    int zero3 = 0;
    if (zero3 != 0) {}
    int zero4 = 0;
    if (zero4 != 0) {}
    int vftable2 = *(int*)this_ptr;
    return *(int*)(vftable2 + index * 4);
}
