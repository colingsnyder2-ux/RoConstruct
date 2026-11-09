// from server: 100% by tester
struct S {
    char pad[4];
    void* field_0x4;
    bool field_0x8;
    S* m();
};

struct StreamBuf {
    int sbumpc();
};

extern "C" int (__stdcall *sbumpc_ptr)();

S* S::m()
{
    StreamBuf* p = (StreamBuf*)field_0x4;
    if (p != 0) {
        int r = ((int (__thiscall*)(StreamBuf*))sbumpc_ptr)(p);
        if (r != -1) {
            field_0x8 = false;
            return this;
        }
    }
    field_0x4 = 0;
    field_0x8 = true;
    return this;
}
