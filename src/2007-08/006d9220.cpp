// from server: 68% by colin
// roc 2007-08 006d9220  unit: CXTPDockingPaneSplitterContainer  size: 317 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d9220

extern "C" {
int __stdcall wsprintfA(char* lpOut, const char* lpFmt, ...);
}

struct CXTPDockingPaneSplitterContainer {
    int LoadState(int param);
};

struct CList {
    void* m_pHead;
    void* m_pTail;
};

extern "C" int __stdcall sub_6d7b90(int);
extern "C" int __stdcall sub_685780(int, const char*, void*, int);
extern "C" int __stdcall sub_685740(int, const char*, void*, int);
extern "C" int __stdcall sub_685720(int, const char*, void*, int, int);
extern "C" int __stdcall sub_6353a0(int, int);
extern "C" int __stdcall sub_6e4920(int, int, int, int);
extern "C" int __stdcall sub_630a1e(int, int);

int CXTPDockingPaneSplitterContainer::LoadState(int param)
{
    char buf[264];
    int count;
    int i;
    int* p;
    int node;
    int val;

    sub_6d7b90(param);
    sub_685780(param, (const char*)0x7d8d50, (void*)((char*)this + 0x70), 0);

    count = 0;
    if (*(int*)(param + 0x24) == 0) {
        val = *(int*)((char*)this + 0x44);
        sub_685740(param, (const char*)0x7d8bf4, &count, val);
        i = 1;
        node = *(int*)((char*)this + 0x3c);
        while (node != 0) {
            p = (int*)node;
            node = *p;
            wsprintfA(buf, (const char*)0x7d8bec, i);
            sub_685740(param, buf, (void*)((char*)p + 0x34), i);
            i++;
        }
        return 1;
    } else {
        sub_685720(param, (const char*)0x7d8bf4, &count, 0, 0);
        p = *(int**)(param + 0x20);
        i = 1;
        if (count >= 1) {
            do {
                wsprintfA(buf, (const char*)0x7d8bec, i);
                sub_685720(param, buf, &val, 0, 0);
                int* q = (int*)sub_6353a0((int)p, val);
                int r = *q;
                if (r != 0) {
                    sub_6e4920((int)((char*)this - 0x20), r, 0, 1);
                } else {
                    return 0;
                }
                i++;
            } while (i <= count);
        }
        return 1;
    }
}
