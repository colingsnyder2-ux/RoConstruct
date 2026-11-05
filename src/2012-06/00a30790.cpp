// from server: 95% by atomic.potato
extern "C" void __stdcall RaiseError(unsigned long);

struct CXTPArrayT {
    void* vftable;
    int GetArraySize();
    void GetAt(int, void*);
};

int CXTPArrayT::GetArraySize() {
    return ((int (__thiscall *)(CXTPArrayT*))(*(void***)this)[22])(this);
}

void CXTPArrayT::GetAt(int index, void* value) {
    if (index < 0 || index >= GetArraySize())
        RaiseError(0x8002000bUL);
    else
        ((void (__thiscall *)(CXTPArrayT*, int, void*))(*(void***)this)[25])(this, index, value);
}
