// from server: 100% by why2
struct CXTPControlTabWorkspace
{
    int getValue();
};

int CXTPControlTabWorkspace::getValue()
{
    int* p = *(int**)((char*)this - 0x78);
    int* vt = *(int**)p;
    int (*fn)(void*) = *(int (**)(void*))((char*)vt + 0x1ac);
    return ((int (__fastcall*)(void*))fn)(p);
}
