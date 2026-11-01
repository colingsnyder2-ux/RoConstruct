// from server: 64% by colin
struct CXTIconHandle {
    char pad[0x18];
    int field_18;
    char pad2[0x14];
    int field_30;
    int field_34;
    int field_38;
    CXTIconHandle* CXTIconHandle_ctor();
    void CXTIconHandle_dtor();
};

extern "C" void __stdcall DeleteCriticalSection(void*);
extern "C" void __stdcall sub_4018b0(void*);
extern "C" void __stdcall sub_724e8e(void*);

CXTIconHandle* CXTIconHandle::CXTIconHandle_ctor() {
    sub_4018b0(&field_18);
    field_30 = 0;
    field_34 = 0;
    field_38 = 0;
    return this;
}

void CXTIconHandle::CXTIconHandle_dtor() {
    DeleteCriticalSection(&field_30);
    sub_724e8e(&field_18);
}
