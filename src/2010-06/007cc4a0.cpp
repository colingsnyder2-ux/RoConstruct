// from server: 100% by atomic.potato
struct XTP_REPORTRECORDITEM_DRAWARGS {
    void* f();
};

void* XTP_REPORTRECORDITEM_DRAWARGS::f() {
    void* p = (*(void*(__thiscall**)(void*))(*(void***)this + 0x194 / 4))(this);
    return (*(void*(__thiscall**)(void*))(*(void***)p + 0x188 / 4))(p);
}
