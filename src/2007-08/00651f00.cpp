// from server: 100% by colin
struct XTP_REPORTRECORDITEM_DRAWARGS {
    void f();
};

void XTP_REPORTRECORDITEM_DRAWARGS::f() {
    if (*(int*)((char*)this + 0x2c0) != 0) {
        void* p = (*(void*(__thiscall**)(void*))(*(void***)this + 0x18c / 4))(this);
        (*(void(__thiscall**)(void*))(*(void***)p + 0x170 / 4))(p);
    }
}
