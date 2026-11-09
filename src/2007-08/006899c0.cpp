// from server: 100% by colin
struct CXTPControlTabWorkspace {
    int field_0x0;
    int getValue();
};

int CXTPControlTabWorkspace::getValue()
{
    int* p = *(int**)((char*)this - 0x6c);
    int* vt = *(int**)p;
    return ((int (__thiscall*)(int*))vt[0x19c / 4])(p);
}
