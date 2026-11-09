// from server: 45% by colin
struct Tool {
    char pad0[4];
    int field4;
    int field8;
    char padC[0x160];
    int field16C;
    char pad170[0x40];
    int field1B0;
    int field1B4;

    void sub_5D4650(int, int);
    void sub_5D2200();
    void sub_541960(void*);

    void sub_5D4760(void* arg);
};

extern "C" int __cdecl sub_486830(int);
extern "C" char __stdcall sub_4915F0(int, int);
extern "C" void __stdcall sub_4B0360(int, void*);
extern "C" int __stdcall sub_570270(int, void*);
extern "C" void __stdcall sub_57CE80(int);

void Tool::sub_5D4760(void* arg) {
    int v1 = sub_486830(this->field4);
    int v2 = sub_486830(this->field8);
    if (v1 != 0) {
        if (sub_4915F0(v1, 1)) {
            sub_5D4650(0, v1);
            goto end;
        }
        if (this->field16C == 6) {
            int r = sub_570270(0x8C6914, &this->field4);
            if (r != 0) {
                sub_4B0360(r + 0x10, (char*)&arg + 0x10);
            }
        }
        if (this->field16C >= 5) {
            int r = sub_570270(0x8C6938, &this->field4);
            if (r != 0) {
                sub_4B0360(r + 0x10, (char*)&arg + 0x10);
            }
            if (this->field1B0 != 0) {
                int ecx = this->field1B4;
                this->field1B0 = 0;
                sub_57CE80(ecx);
                this->field1B4 = 0;
            }
        }
        this->field16C = 0;
    }
end:
    sub_541960(arg);
    if (v2 != 0) {
        if (sub_4915F0(v2, 1)) {
            sub_5D2200();
        }
    }
}
