// from server: 65% by atomic.potato
extern "C" void* __stdcall sub_7a8bea(void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_63c320(void*, float);
extern "C" void __stdcall sub_468c50(void*, void*);

void sub_66e030(void* self) {
    void* p = sub_7a8bea(self, 0, (void*)0xb78e40, (void*)0xb7c8c0, 0);
    if (p) {
        sub_63c320(p, 1.0f);
        return;
    }
    void* q = sub_7a8bea(self, 0, (void*)0xb78e40, (void*)0xb84678, 0);
    if (q) {
        sub_468c50(q, (void*)0x66e030);
    }
}
