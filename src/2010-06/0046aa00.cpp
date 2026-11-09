// from server: 24% by atomic.potato
extern "C" void* __cdecl sub_7A79A0(unsigned int);

struct Inner {
    void init(int);
};

struct CRobloxWnd_FrameRateManagerStatsItem {
    void __cdecl construct(int);
    void assign(void*, void*);
};

void CRobloxWnd_FrameRateManagerStatsItem::construct(int arg) {
    Inner* p = (Inner*)sub_7A79A0(0x108);
    Inner* q = 0;
    if (p) {
        p->init(arg);
        q = p;
    }
    assign(q, 0);
}
