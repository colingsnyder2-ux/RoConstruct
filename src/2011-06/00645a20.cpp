// from server: 80% by atomic.potato
extern "C" int __cdecl sub_006459D0(int a, int b);

int sub_00645A20(int a, int b, int c, int d, int e, int f) {
    int esi = sub_006459D0(a, b);
    int ebp = sub_006459D0(c, d);
    int ecx = (esi > 0) ? a : b;
    int eax = (ebp > 0) ? e : f;
    int r = sub_006459D0(ecx, eax);
    if (r == 0) {
        int edi = (esi > 0) ? b : a;
        int eax2 = (ebp > 0) ? f : e;
        r = sub_006459D0(edi, eax2);
    }
    return r;
}
