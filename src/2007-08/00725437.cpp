// from server: 41% by colin
struct CXTIconHandle {
    int field_0;
    char pad_4[4];
    int* field_8;
    int* field_c;
    char pad_10[0x10];
    void destroy();
};

extern "C" void __stdcall DeleteCriticalSection(void*);

void CXTIconHandle::destroy() {
    if (field_0 != 0) {
        int* p = field_8;
        if (p < field_c) {
            do {
                int* q = (int*)*p;
                if (q != 0) {
                    int* r = (int*)q[4];
                    if (r != 0) {
                        (*(void (__stdcall**)(int*))(*(int*)r + 8))(r);
                    }
                    q[4] = 0;
                }
                p++;
            } while (p < field_c);
        }
        DeleteCriticalSection((void*)((char*)this + 0x10));
        field_0 = 0;
    }
}
