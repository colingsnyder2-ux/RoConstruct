// from server: 79% by Intel
extern "C" void __stdcall sub_4055F0(void*);

int* g_pGlobal = 0;

int __stdcall sub_416470(int, int, int, int** ppvObject) {
    if (!ppvObject) {
        return 0x80004003;
    }

    if (!g_pGlobal) {
        int arg = 0;
        sub_4055F0(&arg);
    }

    *ppvObject = g_pGlobal;

    if (g_pGlobal) {
        (*(void (__stdcall**)(int*))(*g_pGlobal + 4))(g_pGlobal);
    }

    return 0;
}
