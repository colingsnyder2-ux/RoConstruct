// from server: 37% by atomic.potato
struct MegaTextureProxy {
    char pad0[0x5c];
    void* field5c;
    void* field60;
    void __cdecl func(int a, int b, int c, int d, int e, int f, int g, int hh, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t);
};

extern "C" {
    void* __stdcall sub_89E4B4(const char* s);
    void* __stdcall sub_89E448(void* a, void* b, void* c);
    void* __stdcall sub_8A0754(void* a, int b, int c);
    void* __stdcall sub_8A0750(void* a);
    void* __stdcall sub_89E4C4(void* a);
    void* __stdcall sub_8A07C8();
    void* __stdcall sub_8A0DC0(void* a);
    void* __stdcall sub_8A0DBC(void* a);
    void* __stdcall sub_8A0DC8(void* a, int b, int c, int d);
    void* __stdcall sub_89E50C(void* a, void* b, void* c);
    void* __stdcall sub_835350(void* a, double b);
}

void MegaTextureProxy::func(int a, int b, int c, int d, int e, int f, int g, int hh, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t)
{
    char buf78[0x78];
    char bufB0[0x60];
    char buf48[0x30];
    char bufCC[0x38];
    char buf94[0x38];
    char bufE8[0x1c];
    char buf104[0x30];
    char buf2C[0x1c];

    sub_8A0DC0(buf78);
    if ((unsigned int)sub_8A0DBC(buf78) > 0x200)
        goto fail;
    if ((unsigned int)sub_8A0DBC(buf78) > 0x200)
        goto fail;

    sub_89E4B4((const char*)0x923924);
    sub_89E448((void*)0x923924, bufB0, buf48);
    sub_8A0754(buf48, 2, 0);
    sub_8A0750(buf48);
    sub_89E4C4(buf48);
    sub_89E4C4(bufB0);
    return;

fail:
    sub_8A07C8();
    {
        void* p = *(void**)((char*)this + 0x60);
        void* q = *(void**)((char*)p + 0x5c);
        void* r2 = *(void**)p;
        void* fn = *(void**)((char*)r2 + 0x3c);
        ((void(__thiscall*)(void*, void*))fn)(p, q);
    }
    sub_8A0DBC(buf78);
    unsigned int w = (unsigned int)sub_8A0DC0(buf78) >> 1;
    unsigned int h = (unsigned int)sub_8A0DBC(buf78) >> 1;
    sub_8A0DC8(buf78, 2, w, h);
    int iw = (int)sub_8A0DBC(buf78);
    double dw = (double)iw;
    if (iw < 0) dw += 4294967296.0;
    sub_835350(bufCC, dw);
    int ih = (int)sub_8A0DC0(buf78);
    double dh = (double)ih;
    if (ih < 0) dh += 4294967296.0;
    sub_835350(buf94, dh);

    sub_89E4B4((const char*)0x9238fc);
    sub_89E50C(bufE8, buf104, buf94);
    sub_89E448((void*)0x8b5054, buf104, buf2C);
    sub_89E50C(buf2C, buf48, bufCC);
    sub_89E448((void*)0x9238ec, buf48, bufB0);
    sub_8A0754(bufB0, 2, 0);
    sub_8A0750(bufB0);
    sub_89E4C4(bufB0);
    sub_89E4C4(buf48);
    sub_89E4C4(buf2C);
    sub_89E4C4(buf104);
    sub_89E4C4(bufE8);
    sub_89E4C4(buf94);
    sub_89E4C4(bufCC);
}
