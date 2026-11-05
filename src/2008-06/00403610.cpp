// from server: 100% by colin
// roc 2008-06 00403610  unit: ATL::CRegObject  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403610

extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall RaiseException(unsigned long, unsigned long, unsigned long, const unsigned long*);

struct CRegObject {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int Find(const char* name);
    int GetAt(int index);
};

int CRegObject::GetAt(int index) {
    int* self = &this->field4;
    int result = ((CRegObject*)self)->Find((const char*)&index);
    if (result == -1) {
        return 0;
    }
    if (result < 0 || result >= self[2]) {
        RaiseException(0xc000008c, 1, 0, 0);
    }
    return ((int*)self[1])[result];
}
