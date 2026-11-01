// from server: 100% by tester
struct XTP_REPORTRECORDITEM_DRAWARGS {
    void f();
};

void XTP_REPORTRECORDITEM_DRAWARGS::f() {
    void* p = (*(void*(__thiscall**)(void*))(*(void***)this + 0x194 / 4))(this);
    (*(void(__thiscall**)(void*))(*(void***)p + 0x188 / 4))(p);
}