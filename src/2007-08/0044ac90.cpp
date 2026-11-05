// from server: 49% by colin
struct CRobloxCommandLineInfo {
    void* field0;
    CRobloxCommandLineInfo* Construct(int arg);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

CRobloxCommandLineInfo* CRobloxCommandLineInfo::Construct(int arg)
{
    void* p;
    this->field0 = 0;
    p = sub_62FEF6(0x10);
    if (p != 0) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x7905bc;
        *(int*)((char*)p + 0xc) = arg;
    } else {
        p = 0;
    }
    this->field0 = p;
    return this;
}
