// from server: 36% by colin
struct Instance {
    char pad[0x11c];
    unsigned char flags11c;
    unsigned char flags11d;
    int field120;
    int field124;
};

struct SoundChannel {
    char pad[0xe8];
    int fieldE8;
    char pad2[0x10];
    char fieldF8[0x20];
    char pad3[0x4];
    unsigned char flags11c;
    unsigned char flags11d;
    int field120;
    int field124;

    void sub_58ba70();
    void sub_588c50();
    void sub_58b7e0();
    void sub_58c1b0(Instance*);
    void sub_541960(void*);
    void sub_58c870(void*);
};

struct ArgStruct {
    SoundChannel* field0;
    Instance* field4;
    Instance* field8;
};

extern "C" {
    int __cdecl sub_486830(int);
    int __cdecl sub_450d00();
    int __cdecl sub_432530();
    int __cdecl sub_55a920();
    int __cdecl sub_48cbe0();
    int __cdecl sub_4200c0();
    int __cdecl sub_630d36(int, int, int, int, int);
    int __cdecl sub_408740();
    int __cdecl sub_549320();
    int __cdecl sub_492360();
    void __stdcall sub_77e69c();
}

void SoundChannel::sub_58c870(void* arg) {
    ArgStruct* args = (ArgStruct*)arg;
    int v1 = sub_486830((int)args->field4);
    int v2 = sub_486830((int)args->field8);
    SoundChannel* ebx = this ? (SoundChannel*)((char*)this + 0xe8) : 0;
    if (v1) {
        int r = sub_450d00();
        if (r) {
            sub_432530();
        }
        if (this->flags11d & 2) {
            this->sub_58ba70();
        }
        this->sub_588c50();
    }
    this->sub_541960(arg);
    if (args->field0 == this) {
        int r = sub_630d36((int)args->field8, 0, 0x881f4c, 0x884a28, 0);
        this->field124 = r;
        this->sub_58b7e0();
    }
    if (v2) {
        int r = sub_55a920();
        if (r && *(int*)(r + 0xec)) {
            this->flags11d &= ~4;
            char buf[0x20];
            sub_77e69c();
            *(int*)(buf + 0x1c) = *(int*)((char*)this + 0xf8 + 0x1c);
            int tmp = 0;
            sub_408740();
            sub_549320();
            sub_492360();
            this->sub_58b7e0();
            if (this->field120 > 0) {
                this->sub_58c1b0((Instance*)this);
            }
        }
    }
    if (v1) {
        int r = sub_48cbe0();
        if (r) {
            if (args->field4 != (Instance*)r) {
                if (!sub_4200c0()) {
                    goto skip;
                }
            }
            if (v2) {
                int r2 = sub_48cbe0();
                if (r2) {
                    if (args->field8 != (Instance*)r2) {
                        if (!sub_4200c0()) {
                            goto skip;
                        }
                    }
                }
            }
            if (this->flags11c) {
                this->sub_58c1b0(args->field4);
            }
            this->sub_588c50();
        }
    }
skip:
    ;
}
