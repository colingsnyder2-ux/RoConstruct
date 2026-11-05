// from server: 45% by colin
struct bad_lexical_cast {
    void* vfptr0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    char field18[0x34];
    float field4C;
    bad_lexical_cast();
};

extern "C" void __stdcall sub_4F5B90(char*);
extern "C" void __stdcall sub_4F5B30();

extern unsigned char byte_8BFBD0;

bad_lexical_cast::bad_lexical_cast()
{
    vfptr0 = (void*)0x797984;
    field4 = 0;
    field8 = 0;
    vfptr0 = (void*)0x79F754;
    field10 = 0;
    field14 = 0;
    fieldC = 0;
    sub_4F5B90(field18);
    if (byte_8BFBD0 == 0) {
        sub_4F5B30();
        byte_8BFBD0 = 1;
    }
    field4C = 0.0f;
}
