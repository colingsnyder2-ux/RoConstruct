// from server: 35% by atomic.potato
struct MegaTextureProxy {
    char pad0[0x58];
    int field58;
    int field5c;
    int func(int a, int b, int c, int d, int e);
};

extern "C" {
    int __stdcall sub_7ADBE0(int a, double b);
    void* __stdcall sub_802458(const char* s);
    void __stdcall sub_802468(void* p);
    void* __stdcall sub_8023E4(void* dst, void* src, int n);
    void* __stdcall sub_8024A8(void* dst, void* a, void* b);
    void* __stdcall sub_804E74(int a, int b, int c);
    void __stdcall sub_804E78(void* p);
    int __stdcall sub_8043C8(void* p);
    int __stdcall sub_8043C4(void* p);
    int __stdcall sub_8043C0(void* p);
    void* __stdcall sub_804C44();
}

int MegaTextureProxy::func(int a, int b, int c, int d, int e)
{
    char buf1[0x58];
    char buf2[0x2c];
    char buf3[0x74];
    char buf4[0xc8];
    char buf5[0xac];
    char buf6[0x90];
    char buf7[0xe4];
    char buf8[0x58];
    int r3;
    int r4;

    int r1 = sub_8043C8(buf8);
    if ((unsigned)r1 > 0x200) goto fail;
    int r2 = sub_8043C4(buf8);
    if ((unsigned)r2 > 0x200) goto fail;

    {
        void* s1 = sub_802458((const char*)0x874c34);
        void* s2 = sub_8023E4(buf2, s1, d);
        void* s3 = sub_804E74(0, 2, (int)s2);
        sub_804E78(s3);
        sub_802468(buf2);
        sub_802468(s1);
    }
    return 0x7ae7bf;

fail:
    {
        void* tm = sub_804C44();
        int v = *(int*)((char*)this + 0x58);
        v = *(int*)((char*)v + 0x5c);
        void** vt = *(void***)tm;
        int (*fn)(void*, int) = (int (*)(void*, int))vt[0x3c/4];
        fn(tm, v);
    }
    {
        sub_8043C4(buf8);
        int w = sub_8043C4(buf8) >> 1;
        int h = sub_8043C8(buf8) >> 1;
        sub_8043C0(buf8);
        (void)w; (void)h;
    }
    {
        double d1 = (double)a;
        r3 = sub_7ADBE0((int)buf6, d1);
        double d2 = (double)b;
        r4 = sub_7ADBE0((int)buf7, d2);
    }
    {
        void* s1 = sub_802458((const char*)0x874c0c);
        void* s2 = sub_8024A8(buf4, s1, (void*)r3);
        void* s3 = sub_8023E4(buf5, s2, 0x80f0cc);
        void* s4 = sub_8024A8(buf1, s3, (void*)r4);
        void* s5 = sub_8023E4(buf2, s4, 0x874bfc);
        void* s6 = sub_804E74(0, 2, (int)s5);
        sub_804E78(s6);
        sub_802468(buf2);
        sub_802468(buf1);
        sub_802468(buf5);
        sub_802468(buf4);
        sub_802468(s1);
        sub_802468(buf7);
        sub_802468(buf6);
    }
    return 0x7aea33;
}
