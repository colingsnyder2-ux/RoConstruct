// from server: 55% by Intel
struct Vout_of_range {
    void U_error_info_injector_clone_impl();
};

extern "C" void __stdcall sub_44D8D0(void* thisptr);
extern "C" void __cdecl sub_983144(int, void*, int);

void Vout_of_range::U_error_info_injector_clone_impl() {
    char buffer[0x40];
    sub_44D8D0(buffer + 4);
    *(int*)(buffer + 8) = 0xB531C8;
    *(int*)(buffer + 0x30) = 0xB531C0;
    *(int*)(buffer + 0x44) = 0xB531B0;
    sub_983144(0xCDD7D4, buffer + 4, 0x40);
}
