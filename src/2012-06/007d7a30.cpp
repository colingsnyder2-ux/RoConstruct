// from server: 100% by atomic.potato
extern "C" void __cdecl sub_9831F5(void*);

extern unsigned char byte_E4DFB4;
extern int dword_E4DFAC;
extern int dword_E4DFB0;

void sub_7D7A30() {
    int one = 1;
    if (!(byte_E4DFB4 & one)) {
        *(int*)&byte_E4DFB4 |= one;
        dword_E4DFAC = 0;
        dword_E4DFB0 = 0;
        sub_9831F5((void*)0xB1D0F0);
    }
}
