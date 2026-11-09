// from server: 40% by Intel
struct GenericJob {
    int run();
};

extern "C" int __stdcall sub_6E23F0(void* thisptr, int* out);
extern "C" int __stdcall sub_6E2310(void* thisptr, int* in);
extern "C" double* __stdcall sub_6E2180(void* thisptr, double* out);

int GenericJob::run() {
    int v18 = 0;
    int* ebx = *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x23C);
    if (ebx <= 0)
        goto LABEL_14;

    void* ebp = reinterpret_cast<char*>(this) + 0x220;
    int edi = 0;

    while (true) {
        if (!sub_6E23F0(ebp, &v18))
            break;
        sub_6E2310(this, &v18);
        ++edi;

        if (*reinterpret_cast<int*>(0xE0215C) == 2) {
            double local10;
            double* val = sub_6E2180(ebp, &local10);
            double cmp = *reinterpret_cast<double*>(0xB68560);
            if (*val <= cmp) {
                if (edi >= *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x23C))
                    break;
                continue;
            }
        }
        break;
    }

LABEL_14:
    int eax = v18;
    if (eax) {
        int* ptr = *reinterpret_cast<int**>(eax);
        if (ptr) {
            int(__stdcall* func)(int*, int, int*) = reinterpret_cast<int(__stdcall*)(int*, int, int*)>(ptr[1]);
            int local20[2] = {0};
            func(local20, 2, local20);
        }
    }
    return 0;
}
