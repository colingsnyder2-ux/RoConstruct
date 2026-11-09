// from server: 72% by atomic.potato
extern "C" {
    extern int g_00be2a58;
    int __cdecl sub_722e10(int, int, int);
    int __cdecl sub_721700(int, int);
}

struct S {
};

int __cdecl f(int a) {
    int v = g_00be2a58;
    int esi = sub_722e10(a, 2, v);
    int ecx = sub_722e10(a, 1, g_00be2a58);
    int r;
    if (*(float*)ecx == *(float*)esi && *(float*)(ecx + 4) == *(float*)(esi + 4))
        r = 1;
    else
        r = 0;
    sub_721700(a, r & 0xff);
    return 1;
}
