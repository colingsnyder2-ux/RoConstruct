// from server: 69% by atomic.potato
struct VCXTPReportRows {
    char pad0[0x30];
    int* m_pData;
    int m_nCount;
    int Sum();
};

int VCXTPReportRows::Sum() {
    int total = 0;
    int i = 0;
    int n = m_nCount;
    if (n > 0) {
        do {
            if (i < 0 || i >= n) {
                __declspec(noreturn) void fail();
                fail();
            }
            int* p = m_pData;
            total += p[i * 2 + 1] - p[i * 2];
            i++;
        } while (i < n);
    }
    return total;
}
