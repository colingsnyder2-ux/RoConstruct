// from server: 100% by colin
struct CXTPControlPopup {
    char pad[0x16c];
    void* field_16c;
    void SetPtr(void* p);
};

extern "C" void __fastcall sub_6301e4(void* p);
extern "C" long (__stdcall *InterlockedIncrement)(long volatile* p);

void CXTPControlPopup::SetPtr(void* p)
{
    void* old = field_16c;
    if (old != 0) {
        sub_6301e4(old);
    }
    field_16c = p;
    if (p != 0) {
        InterlockedIncrement((long*)((char*)p + 4));
    }
}
