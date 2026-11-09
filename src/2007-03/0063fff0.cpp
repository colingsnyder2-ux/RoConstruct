// from server: 100% by tester
struct XTP_REPORTRECORDITEM_DRAWARGS {
    void f();
};

void XTP_REPORTRECORDITEM_DRAWARGS::f() {
    void* p = (*(void*(__thiscall**)(void*))(*(void***)this + 0x18c / 4))(this);
    (*(void(__thiscall**)(void*))(*(void***)p + 0x160 / 4))(p);
}