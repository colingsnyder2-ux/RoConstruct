// from server: 74% by atomic.potato
extern "C" {
    unsigned long __stdcall GetLastError();
    void __stdcall Sleep(unsigned long);
    int __stdcall InternetQueryDataAvailable(int, unsigned long*, unsigned long, unsigned long);
    int __stdcall InternetReadFile(int, void*, unsigned long, unsigned long*);
}

extern int G_9ebd0c;
extern int G_9ebd10;
extern int G_9ea3a0;
extern int G_9ea288;

void __cdecl sub_5a0bd0(int, const char*, const char*);
void __cdecl sub_5a0f20(int);

struct S {
    int f(int, int);
};

int S::f(int a, int b)
{
    int* self = (int*)this;
    int* p = self + 1;
    if (*p == 0) {
        int h = *self;
        int (__stdcall* fn)(int, int, int*, int) = (int (__stdcall*)(int, int, int*, int))G_9ebd0c;
        int r = fn(h, 0, p, 0);
        if (r == 0) {
            int (__stdcall* geterr)() = (int (__stdcall*)())G_9ea3a0;
            for (;;) {
                int e = geterr();
                if (e == 0x3e5) {
                    ((void (__stdcall*)(int))G_9ea288)(100);
                } else {
                    sub_5a0bd0(e, (const char*)0xa40f5c, (const char*)0xa40f68);
                }
                int h2 = *self;
                r = fn(h2, 0, p, 0);
                if (r != 0)
                    break;
            }
        }
        if (*p == 0) {
            return -1;
        }
    }
    int v = b;
    int* q = &v;
    if ((unsigned)v >= (unsigned)*p)
        q = p;
    int n = *q;
    int h3 = *self;
    int ok = ((int (__stdcall*)(int, int, int, int*, const char*, const char*))G_9ebd10)(h3, a, n, &v, (const char*)0xa40f5c, (const char*)0xa40f48);
    sub_5a0f20(ok == 1);
    *p -= v;
    return 0;
}
