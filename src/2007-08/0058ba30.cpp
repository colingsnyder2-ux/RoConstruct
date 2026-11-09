// from server: 100% by colin
struct SoundService {
    char pad[0xf4];
    void* field_f4;
    char pad2[0x120 - 0xf8];
    void* field_120;
    void sub_58b7e0();
    void sub_444710(void*);
    void destructor();
};

void __stdcall sub_62fc44(void*, int);

void SoundService::destructor() {
    if (field_f4) {
        sub_62fc44(field_f4, 1);
    }
    sub_58b7e0();
    if (field_120) {
        field_120 = 0;
        sub_444710((void*)0x8c33e8);
    }
}
