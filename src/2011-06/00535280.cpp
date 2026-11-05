// from server: 70% by colin
// roc 2011-06 00535280  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00535280

extern "C" void* __cdecl sub_80A340(unsigned int size);
extern "C" void __cdecl sub_537FA0(void* dst, int count, const void* src);
extern "C" int __cdecl sub_538CD0(int value);

struct VCXTPReportRow {
    void sub_534F20();
    bool Init(int a, int b, int c);
};

void VCXTPReportRow::sub_534F20() {
}

bool VCXTPReportRow::Init(int a, int b, int c) {
    sub_534F20();
    *(int*)((char*)this + 0x20) = c;
    *(int*)((char*)this + 0x2c) = b;
    void* p = 0;
    if (b != 0) {
        unsigned int sz = (unsigned int)b * 4;
        int ovf = 0;
        if (b != 0 && sz / 4 != (unsigned int)b) ovf = 1;
        p = sub_80A340(ovf ? (unsigned int)-1 : sz);
    }
    *(void**)((char*)this + 0x24) = p;
    if (p == 0) {
        return false;
    }
    sub_537FA0(p, *(int*)((char*)this + 0x2c), (const void*)a);
    int v = *(int*)(*(int*)((char*)this + 0x24));
    *(int*)((char*)this + 0x28) = sub_538CD0(v);
    return true;
}
