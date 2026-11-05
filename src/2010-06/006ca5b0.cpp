// from server: 27% by atomic.potato
struct RBX_VHandles_EventDesc {
    void construct(char *a, char *b, int c, int d, int e, int f, int g, int h, int i, int j);
    char pad[4];
    void *field4;
};

extern "C" void __stdcall sub_4b3f00(void *, int);
extern "C" void __stdcall sub_6ca270(void *, int, int);

void RBX_VHandles_EventDesc::construct(char *a, char *b, int c, int d, int e, int f, int g, int h, int i, int j) {
    int local0 = 0;
    int local1 = 1;
    char local2 = 1;
    void *p = field4;
    if (p) {
        sub_4b3f00((void *)0x66ed30, local1);
    }
    void *arr[8];
    arr[0] = 0;
    void *q = *(void **)((char *)&local0 + 0x44);
    if (q) {
        arr[0] = q;
        void **vt = *(void ***)q;
        void *r = (char *)&arr[0] + 8;
        ((void (__thiscall *)(void *, void *, int))vt[0])((char *)&local0 + 0x4c, r, 0);
    }
    int x = *(int *)((char *)&local0 + 0x40);
    int y = *(int *)((char *)&local0 + 0x3c);
    sub_6ca270(this, y, x);
    void *s = *(void **)((char *)&local0 + 0x24);
    local0 = 1;
    local2 = 0;
    if (s) {
        void *t = *(void **)s;
        if (t) {
            ((void (__stdcall *)(void *, void *, int))t)((char *)&local0 + 0x2c, (char *)&local0 + 0x2c, 2);
        }
    }
}
