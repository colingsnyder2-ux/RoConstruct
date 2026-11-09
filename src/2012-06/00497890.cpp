// from server: 56% by atomic.potato
struct CRobloxWnd_RenderJob {
};

void __cdecl f_00497890(void* a, void* b, int c, int d, int e, int f)
{
    char* p = (char*)a;
    char* end = (char*)b;
    while (p != end) {
        int (*fn)(int, int, int);
        int v = *(int*)p + c;
        fn = *(int (**)(int, int, int))((char*)&fn + 0);
        fn(v, d, e);
        p += 8;
    }
    int* out = (int*)a;
    out[0] = c;
    out[1] = d;
    out[2] = e;
    out[3] = f;
}
