// from server: 39% by atomic.potato
struct S {
    char pad0[8];
    int len;
    char pad1[4];
    int f(int, int, int, int, int);
};

extern "C" void __stdcall sub_7a7c82(int);
extern "C" void __stdcall sub_7a8e26(void*, void*, void*);
extern "C" void __stdcall sub_4aaf80(void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_4a3e50(void*);
extern "C" void __stdcall invalid_parameter_noinfo();

int S::f(int a1, int a2, int a3, int a4, int a5) {
    int buf[3];
    buf[0] = 0;
    buf[2] = len;
    void* p;
    if (len <= 8) {
        p = buf;
    } else {
        sub_7a7c82(len);
        buf[0] = (int)p;
        p = (void*)buf[0];
    }
    sub_7a8e26(p, (void*)buf[2], (void*)buf[0]);
    int tmp[5];
    sub_4aaf80(tmp, &a1, &a2, &a3, &a4);
    int ebx = tmp[1];
    if (ebx != -4 && ebx != 0 && ebx != tmp[5]) {
        invalid_parameter_noinfo();
    }
    int ecx = tmp[0];
    int esi = tmp[4];
    if (esi == ecx) {
        int* out = (int*)a5;
        out[0] = tmp[5];
        out[1] = ecx;
        out[2] = tmp[5];
        out[3] = ecx;
        return 0;
    }
    int edi = ebx;
    int local14 = edi;
    int local18 = esi;
    if (*(int*)((char*)this + 12) != 0) {
        sub_4a3e50(&local14);
        edi = local14;
    } else {
        while (1) {
            if (edi != -4 && edi != 0 && edi != tmp[5]) {
                invalid_parameter_noinfo();
            }
            if (esi == tmp[0]) break;
            if (edi != -4 && edi != 0) {
                if (edi == 0) invalid_parameter_noinfo();
                char* base;
                if (*(int*)((char*)edi + 0x18) >= 0x10) {
                    base = *(char**)((char*)edi + 4);
                } else {
                    base = (char*)edi + 4;
                }
                int off = *(int*)((char*)edi + 0x14);
                if (esi >= (int)(base + off)) {
                    invalid_parameter_noinfo();
                }
            }
            char bl = *(char*)esi;
            char* start;
            if (len <= 8) {
                start = (char*)this;
            } else {
                start = *(char**)this;
            }
            char* end = start + len;
            char* cur = start;
            int cnt = (int)(end - start);
            while (cnt > 0) {
                int mid = cnt / 2;
                if (start[mid] < bl) {
                    cur = start + mid + 1;
                    cnt = cnt - mid - 1;
                } else {
                    cnt = mid;
                }
            }
            if (cur == end || bl < *cur) break;
            if (edi != -4 && edi != 0) {
                if (edi == 0) invalid_parameter_noinfo();
                char* base;
                if (*(int*)((char*)edi + 0x18) >= 0x10) {
                    base = *(char**)((char*)edi + 4);
                } else {
                    base = (char*)edi + 4;
                }
                int off = *(int*)((char*)edi + 0x14);
                if (local18 >= (int)(base + off)) {
                    invalid_parameter_noinfo();
                }
            }
            local18++;
            esi = local18;
        }
    }
    int* out = (int*)a5;
    out[0] = ebx;
    out[1] = tmp[4];
    out[2] = edi;
    out[3] = esi;
    return 0;
}
