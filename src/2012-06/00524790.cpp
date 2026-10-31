// from server: 26% by Intel
extern "C" void __stdcall sub_4015a0(int, int);
extern "C" void* __stdcall make_value_0051bfa0();
extern "C" void __cdecl sub_51de00();
extern "C" void* __cdecl sub_51faa0(void*);
extern "C" char __cdecl sub_5206d0();
extern "C" void __cdecl sub_6ce510();
extern "C" void __cdecl sub_6dde00();
extern "C" void __cdecl sub_864e70(int);
extern "C" void __cdecl sub_4026a0();

struct W4CameraMode {
    char pad_00[0x80];
    void* vec_begin;
    void* vec_end;
    void* __cdecl method(int);
};

void* W4CameraMode::method(int idx) {
    sub_4015a0(0xe1e190, 0x51d510);
    void* val = make_value_0051bfa0();
    int count = ((char*)vec_end - (char*)vec_begin) >> 3;
    int need = (int)val + 1;
    if (need > count) {
        void* tmp[2];
        tmp[0] = 0;
        tmp[1] = 0;
        sub_864e70(need);
    } else {
        void* existing = ((void**)vec_begin)[(int)val];
        if (existing == 0) {
            return existing;
        }
    }
    if (sub_5206d0() != 0) {
        return 0;
    }
    sub_51de00();
    void* p = sub_51faa0(0);
    void* out;
    sub_6ce510();
    return out;
}
