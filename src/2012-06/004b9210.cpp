// from server: 91% by atomic.potato
struct CSourceStream {
    int* field0;
};

extern "C" int __cdecl sub_41FCF0(void* a1, void* a2);

int __stdcall sub_4B9210(int arg1, int arg2, int* arg3) {
    if (!arg3) {
        return 0x80004003;
    }

    int result = sub_41FCF0((void*)arg2, (void*)0xC0CD08);
    if (result) {
        *arg3 = arg1;
        int* vtable = *(int**)arg1;
        ((void(__thiscall*)(int*))vtable[1])((int*)arg1);
        return 0;
    } else {
        *arg3 = 0;
        return 0x80004002;
    }
}
