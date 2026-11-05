// from server: 67% by colin
struct CRobloxControlColorSelector {
    char pad[0xc0];
    void* m_pData;
    char pad2[4];
    void* m_pData2;
    int HitTest(int x, int y);
};

extern "C" int __stdcall PtInRect(const void* rect, int x, int y);

extern void* g_8bbebc;
extern void* g_8bbec0;

int CRobloxControlColorSelector::HitTest(int x, int y) {
    int count;
    if (g_8bbebc == 0) {
        count = 0;
    } else {
        int diff = (int)g_8bbec0 - (int)g_8bbebc;
        count = diff / 24;
    }
    if (PtInRect(&m_pData, x, y)) {
        if (count > 0) {
            int i = 0;
            do {
                int row = i / 8;
                int col = i % 8;
                int offset1 = row * 32;
                int offset2 = col * 32;
                int r1 = offset1 + (int)m_pData + 2;
                int r2 = offset2 + (int)m_pData2 + 2;
                int rect1[4];
                rect1[0] = r1;
                rect1[1] = r1 + 32;
                rect1[2] = r2;
                rect1[3] = r2 + 32;
                if (PtInRect(rect1, x, y)) {
                    return i;
                }
                i++;
            } while (i < count);
        }
    }
    return -1;
}
