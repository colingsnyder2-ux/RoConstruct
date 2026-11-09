// from server: 28% by atomic.potato
struct UDimItem {
    bool f(const char*);
};

extern "C" void* __stdcall sub_b24798();
extern "C" void* __stdcall sub_b22648();
extern "C" void __stdcall sub_b2263c();
extern "C" bool __cdecl sub_745c30(void*, void*);

struct FakeString {
    char pad[0x1c];
};

bool UDimItem::f(const char* s) {
    FakeString str;
    void* p = sub_b24798();
    sub_b22648();
    bool r = sub_745c30(&str, &p);
    sub_b2263c();
    return r;
}
