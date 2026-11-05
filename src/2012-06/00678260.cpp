// from server: 100% by Intel
extern "C" unsigned char __stdcall set_global_byte(unsigned char value);

unsigned char __stdcall set_global_byte(unsigned char value) {
    *(unsigned char*)0xe58bc0 = value;
    return value;
}
