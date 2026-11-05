// from server: 2% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Scale9Frame {
    char pad[0x90];
    void* ptr90;
    RefCounted* ptr94;
    char pad2[4];
    void* ptr98;
    void getRect(void* out);
    void setRect(float, float);
    void update(float, float);
};

void Scale9Frame::update(float a, float b) {
    void* local;
    Scale9Frame* self = this;
    char* base = (char*)self;
    void* p = 0;
    void* q = 0;
    void* r = 0;
    void* s = 0;
    void* t = 0;
    void* u = 0;
    void* v = 0;
    void* w = 0;
    void* x = 0;
    void* y = 0;
    void* z = 0;
    void* aa = 0;
    void* bb = 0;
    void* cc = 0;
    void* dd = 0;
    void* ee = 0;
    void* ff = 0;
    void* gg = 0;
    void* hh = 0;
    void* ii = 0;
    void* jj = 0;
    void* kk = 0;
    void* ll = 0;
    void* mm = 0;
    void* nn = 0;
    void* oo = 0;
    void* pp = 0;
    void* qq = 0;
    void* rr = 0;
    void* ss = 0;
    void* tt = 0;
    void* uu = 0;
    void* vv = 0;
    void* ww = 0;
    void* xx = 0;
    void* yy = 0;
    void* zz = 0;
    void* aaa = 0;
    void* bbb = 0;
    void* ccc = 0;
    void* ddd = 0;
    void* eee = 0;
    void* fff = 0;
    void* ggg = 0;
    void* hhh = 0;
    void* iii = 0;
    void* jjj = 0;
    void* kkk = 0;
    void* lll = 0;
    void* mmm = 0;
    void* nnn = 0;
    void* ooo = 0;
    void* ppp = 0;
    void* qqq = 0;
    void* rrr = 0;
    void* sss = 0;
    void* ttt = 0;
    void* uuu = 0;
    void* vvv = 0;
    void* www = 0;
    void* xxx = 0;
    void* yyy = 0;
    void* zzz = 0;
    (void)local; (void)base; (void)p; (void)q; (void)r; (void)s; (void)t; (void)u; (void)v; (void)w; (void)x; (void)y; (void)z;
    (void)aa; (void)bb; (void)cc; (void)dd; (void)ee; (void)ff; (void)gg; (void)hh; (void)ii; (void)jj; (void)kk; (void)ll; (void)mm; (void)nn; (void)oo; (void)pp; (void)qq; (void)rr; (void)ss; (void)tt; (void)uu; (void)vv; (void)ww; (void)xx; (void)yy; (void)zz;
    (void)aaa; (void)bbb; (void)ccc; (void)ddd; (void)eee; (void)fff; (void)ggg; (void)hhh; (void)iii; (void)jjj; (void)kkk; (void)lll; (void)mmm; (void)nnn; (void)ooo; (void)ppp; (void)qqq; (void)rrr; (void)sss; (void)ttt; (void)uuu; (void)vvv; (void)www; (void)xxx; (void)yyy; (void)zzz;
}
