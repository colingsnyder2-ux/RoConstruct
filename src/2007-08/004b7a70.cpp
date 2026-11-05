// from server: 60% by colin
struct Exposer {
    char pad0[0xc];
    int field_c;
    int field_10;
    char field_14;
    char pad15[3];
    bool sub_4b7650(int* out, char* flag);
    int* sub_4b7820(int* out);
    bool sub_49fa50(int* out, int a, int b);
    int sub_4c3db0(int* a, int b, int c, int d);
    bool func(int a, int b, char* out, int d);
};

bool Exposer::func(int a, int b, char* out, int d) {
    if (field_14 != 0) {
        if (a >= field_10) {
            if (a == field_10) {
                goto do_work;
            }
        }
    }
    {
        char flag;
        int tmp;
        if (!sub_4b7650(&tmp, &flag)) {
            return false;
        }
        if (flag == 0) {
            return false;
        }
        field_c = tmp;
        field_10 = a;
        field_14 = 1;
    }
do_work:
    {
        int tmp2;
        int* p = sub_4b7820(&tmp2);
        int ebp = *p;
        int edi = b;
        char* esi = out;
        int local;
        *esi = 0;
        if (!sub_49fa50(&local, 0x20, 1)) {
            return false;
        }
        {
            int ecx = *(int*)edi;
            ecx -= *(int*)(edi + 8);
            if (ecx < (unsigned)local) {
                return false;
            }
        }
        {
            int ebx = d;
            int r = sub_4c3db0(&local, edi, local, ebx);
            if (r < ebx) {
                esi[r] = 0;
                return true;
            }
            esi[ebx - 1] = 0;
            return true;
        }
    }
}
