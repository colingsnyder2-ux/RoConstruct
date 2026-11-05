// from server: 85% by Intel
struct VCBrowserViewExternal {
    void* vftable;
    void* vftable2;
    void* vftable3;
    int refCount;
    void* vftable4;
    int field_18;

    long Release(int a1);
};

extern "C" long __stdcall QueryInterface(void* thisPtr, int a2, int a3);
extern "C" void __stdcall sub_62FC62(void* ptr);

long VCBrowserViewExternal::Release(int a1) {
    int* thisPtr = (int*)a1;
    int ref = --thisPtr[6];
    int result = ref;
    if (ref == 0) {
        if (thisPtr != 0) {
            int* vftablePtr = thisPtr + 2;
            thisPtr[0] = 0x785BC0;
            thisPtr[1] = 0x785BA8;
            *vftablePtr = 0x785B84;
            thisPtr[5] = 0x785B5C;
            thisPtr[6] = 0xC0000001;
            QueryInterface(vftablePtr, 0, 0);
            sub_62FC62(thisPtr);
        }
    }
    return result;
}
