// from server: 69% by atomic.potato
struct GeoPairConnector {
    char pad0[0x64];
    float f64;
    float f68;
    float f6c;
    GeoPairConnector(const void*, int, int);
};

extern "C" void __stdcall sub_8944d0(const void*, int, int);

GeoPairConnector::GeoPairConnector(const void* a, int b, int c) {
    sub_8944d0(a, b, c);
    *(int*)this = 0xbdb190;
    f64 = 0.0f;
    f68 = 0.0f;
    f6c = 0.0f;
}
