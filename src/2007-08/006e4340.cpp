// from server: 40% by tester
// roc 2007-08 006e4340  unit: CXTPDockingPaneSplitterContainer  size: 207 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006e4340

struct CXTPDockingPaneSplitterContainer {
    int m_nLeft;
    int m_nTop;
    int m_nRight;
    int m_nBottom;
    int __cdecl Calc(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r);
};

extern "C" int __stdcall sub_6e40b0(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);

int CXTPDockingPaneSplitterContainer::Calc(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r)
{
    int* pThis = (int*)this;
    int v1 = a;
    int v2 = b;
    int v3 = c;
    int v4 = d;
    int v5 = e;
    int v6 = f;
    int v7 = g;
    int v8 = h;
    int v9 = i;
    int v10 = j;
    int v11 = k;
    int v12 = l;
    int v13 = m;
    int v14 = n;
    int v15 = o;
    int v16 = p;
    int v17 = q;
    int v18 = r;

    pThis[0] = v1;
    pThis[1] = v2;
    pThis[2] = v3;
    pThis[3] = v4;

    sub_6e40b0(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18);

    int* pOut = (int*)v5;
    pOut[0] = v1;
    pOut[1] = v2;
    pOut[2] = v3;
    pOut[3] = v4;

    int* pNode = (int*)v6;
    if (pNode == 0)
        return (int)this;

    int v19 = v7;
    int v20 = v8;

    while (pNode != 0) {
        int* pData = (int*)pNode[2];
        int v21 = pData[12];
        pNode = (int*)pNode[0];

        int v22 = v21;
        int v23 = -v21;
        if (v21 > 0) {
            if (v19 == 0) {
                v23 = 0;
            } else {
                v23 = v21 * v20 / v19;
            }
            v19 -= pData[12];
            v20 -= v23;
            if (v20 <= 0) {
                v20 = 0;
            }
        }

        if (v9 != 0) {
            int v24;
            if (pNode == 0) {
                v24 = v10;
            } else {
                v24 = pThis[0] + v23;
            }
            pThis[2] = v24;
            if (v11 == (int)pData) {
                return (int)this;
            }
            v24 += v12;
            pThis[0] = v24;
        } else {
            int v25;
            if (pNode == 0) {
                v25 = v13;
            } else {
                v25 = pThis[1] + v23;
            }
            pThis[3] = v25;
            if (v11 == (int)pData) {
                return (int)this;
            }
            v25 += v12;
            pThis[1] = v25;
        }
    }

    return (int)this;
}
