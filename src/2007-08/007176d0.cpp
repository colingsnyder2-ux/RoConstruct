// from server: 100% by tester
struct CXTPControlTabWorkspace
{
    int getValue();
};

int CXTPControlTabWorkspace::getValue()
{
    int* p = *(int**)((char*)this - 0x7c);
    int* vt = *(int**)p;
    int (*fn)(void*) = *(int (**)(void*))((char*)vt + 0x19c);
    return ((int (__fastcall*)(void*))fn)(p);
}