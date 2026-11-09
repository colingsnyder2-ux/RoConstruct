// from server: 74% by atomic.potato
extern "C" void __cdecl sub_004a7270(int*, int, int);
extern "C" void __cdecl sub_004a76e0(int, int, int, int);
extern "C" void __cdecl sub_004a7720(int, int, int);
extern "C" void __cdecl sub_004a95b0(int, int);
void __cdecl sub_004aadf0(int, int, int);

void __cdecl sub_004aadf0(int a, int b, int c)
{
    int lo = a;
    int hi = b;
    int n = c;
    while (hi - lo > 0x20) {
        if (n <= 0) {
            if (hi - lo > 0x20) {
                if (hi - lo > 1)
                    sub_004a76e0(0, 0, hi, lo);
                sub_004a95b0(hi, lo);
            }
            return;
        }
        int tmp;
        sub_004a7270(&tmp, lo, hi);
        int mid = tmp;
        int half = n;
        int q = half / 2;
        half = q;
        q = half / 2;
        half += q;
        int m = half;
        if (mid - lo < hi - mid) {
            sub_004aadf0(lo, mid, m);
            lo = mid;
        } else {
            sub_004aadf0(mid, hi, m);
            hi = mid;
        }
        n = m;
    }
    if (hi - lo > 1)
        sub_004a7720(lo, hi, 0);
}
