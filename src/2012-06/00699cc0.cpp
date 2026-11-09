// from server: 39% by Intel
struct SoundChannel {
    char pad0[0xC8];
    char m_b8;
    int m_38;
    int m_C4;
    void f_00699cc0(void* a1);
    void f_00698de0();
    void f_006999d0(int);
    void f_00697a80();
    void f_00684660(void*);
};

extern "C" int __stdcall sub_983448(int, int, int, int, int);
extern "C" int __cdecl sub_4A01E0(int);
extern "C" int __cdecl sub_4BE3E0(int);
extern "C" int __cdecl sub_4E77F0();
extern "C" int __stdcall sub_6C8100(int, int);
extern "C" int __cdecl sub_972E20(int);
extern "C" int __cdecl sub_42A4F0(int);

void SoundChannel::f_00699cc0(void* a1) {
    int* v4 = (int*)a1;
    int v5 = v4[1];
    int v6 = 0;
    int v7 = 0;

    if (v5) {
        int v8 = *(int*)(v5 + 0x38);
        if (v8) {
            int v9 = *(int*)(v8 + 0x38);
            if (v9)
                sub_4A01E0(v9);
            else
                v6 = v8;
        }
        if (v6) {
            v6 = sub_983448(0, 0xD601E8, 0xD65108, 0, v6);
        }
    }

    int v10 = v4[2];
    if (v10) {
        int v11 = *(int*)(v10 + 0x38);
        if (v11) {
            int v12 = *(int*)(v11 + 0x38);
            if (v12)
                sub_4A01E0(v12);
            else
                v7 = v11;
        }
        if (v7) {
            v7 = sub_983448(0, 0xD601E8, 0xD65108, 0, v7);
        }
    }

    sub_972E20((int)this + 0xC8);
    f_00684660(a1);

    if (*(int*)a1 == (int)this) {
        int v13 = v4[2];
        if (v13) {
            int v14 = v13 + 0x1C;
            if (v14) {
                int v15 = *(int*)(v14 + 0xC);
                int v16 = sub_4E77F0();
                int v17 = sub_6C8100(v15, v16);
                if (v17) {
                    m_C4 = v13;
                    f_00698de0();
                    goto LABEL_14;
                }
            }
        }
        m_C4 = 0;
        f_00698de0();
    }

LABEL_14:
    if (v6) {
        int v18 = sub_4BE3E0(v6);
        if (v18) {
            int v19 = v4[1];
            if (v19 != v18) {
                int v20 = *(int*)(v19 + 0x38);
                if (v18 != v20) {
                    if (v20 && sub_42A4F0(v18)) {
                        if (v7) {
                            int v21 = sub_4BE3E0(v7);
                            if (v21) {
                                int v22 = v4[2];
                                if (v22 != v21) {
                                    if (sub_42A4F0(v21))
                                        goto LABEL_14;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (m_b8) {
        f_006999d0(m_38);
    }
    f_00697a80();
}
