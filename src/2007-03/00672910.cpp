// from server: 100% by tester
struct CXTPControls
{
    int GetAt(int nIndex);
};

int CXTPControls::GetAt(int nIndex)
{
    int result;
    if (nIndex >= 0 && nIndex < *(int*)((char*)this + 0x2c))
        result = *(int*)(*(int*)((char*)this + 0x28) + nIndex * 4);
    else
        result = 0;
    return (*(int (__thiscall**)(void*, int))((*(int*)this) + 0x58))(this, result);
}
