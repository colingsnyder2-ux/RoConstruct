// from server: 28% by atomic.potato
extern "C" void* __cdecl sub_7F3860(unsigned int);

struct Inner {
    void init(int);
};

struct CRobloxWnd_FrameRateManagerStatsItem {
    void __cdecl construct(int);
};

void Inner::init(int a) {
    sub_7F3860(0x108);
}

void CRobloxWnd_FrameRateManagerStatsItem::construct(int a) {
    void* p = sub_7F3860(0x108);
    void* q = 0;
    if (p) {
        ((Inner*)p)->init(a);
        q = p;
    }
    ((Inner*)this)->init((int)q);
}
