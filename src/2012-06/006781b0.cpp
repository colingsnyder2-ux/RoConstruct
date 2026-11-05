// from server: 100% by Intel
extern "C" void __stdcall func(unsigned char);

void __stdcall func(unsigned char value) {
    *(unsigned char*)0xe581b0 = value;
}
