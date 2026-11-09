// from server: 100% by tester
struct XTP_REPORTRECORDITEM_DRAWARGS {
    void f();
};

void XTP_REPORTRECORDITEM_DRAWARGS::f() {
    if (*(int*)((char*)this + 0x368) != 0) {
        void* p = (*(void*(__thiscall**)(void*))(*(void***)this + 0x194 / 4))(this);
        (*(void(__thiscall**)(void*))(*(void***)p + 0x184 / 4))(p);
    }
}
