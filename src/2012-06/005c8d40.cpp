// from server: 27% by atomic.potato
// roc 2012-06 005c8d40  unit: RBX::AdornRbxGfx  size: 314 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c8d40

extern "C" {
    int __stdcall sub_5c87c0(int);
    int __stdcall sub_5c8a00(int, int, int, int, int);
    int __stdcall sub_56c4f0(int, int);
    int __stdcall sub_810dd0(int, int);
    int __stdcall sub_972290(int, int);
    int __stdcall sub_983144(int, int);
    int __stdcall sub_40c0a0(int);
    void* __stdcall sub_b22648(int);
}

extern float g_b4c440;
extern char g_b80a20[];
extern char g_cd806c[];
extern char g_b80970[];
extern char g_b809c0[];
extern char g_b460cc[];
extern char g_e580b3;
extern int g_e5809c;

struct S {
    int __cdecl f(int);
};

int S::f(int a) {
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int r;
    r = sub_5c87c0(a);
    v0 = 0;
    v1 = 0;
    v2 = 0;
    v3 = *(int*)&g_b4c440;
    if (r != 0) {
        if (r > 0 && r <= 2) {
            if (sub_5c8a00((int)this, (int)&v3, (int)&v2, (int)&v1, (int)&v0)) {
                goto end;
            }
            sub_b22648((int)g_b80a20);
            v4 = 0;
            sub_40c0a0((int)&v4);
            sub_983144((int)&v4, (int)g_cd806c);
        }
        if (g_e580b3 != 0) {
            int fn = g_e5809c;
            if (fn != 0) {
                if (((char (__stdcall*)(int, int, int))fn)(0x7f, (int)g_b80970, (int)g_b460cc)) {
                    goto end;
                }
            }
            sub_972290((int)g_e580b3, (int)g_b809c0);
        }
    } else {
        sub_56c4f0(a, (int)&v3);
        sub_56c4f0(a, (int)&v2);
        sub_56c4f0(a, (int)&v1);
        sub_56c4f0(a, (int)&v0);
    }
end:
    sub_810dd0((int)&v0, a);
    return 0;
}
