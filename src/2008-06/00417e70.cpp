// from server: 100% by tester
struct VCContent_CComObject {
    int AddRefHelper();
};

int VCContent_CComObject::AddRefHelper() {
    return 0;
}

extern "C" int __stdcall VCContent_AddRef(void* p);

int __stdcall VCContent_AddRef(void* p) {
    int* q = (int*)p;
    ++q[2];
    return q[2];
}
