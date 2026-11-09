// from server: 100% by why2
struct CXTPControls {
    int GetSomething() const;
};

int CXTPControls::GetSomething() const {
    int* p = *(int**)((char*)this + 0xd0);
    if (p)
        return *(int*)((char*)p + 0x24);
    return 0;
}
