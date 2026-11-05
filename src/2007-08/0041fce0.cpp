// from server: 100% by colin
struct CXTTreeCtrl {
    char pad[0x54];
    void* m_pSomething;
    int GetItem(void*);
};

extern "C" int __stdcall sub_63023e();

int CXTTreeCtrl::GetItem(void* p)
{
    int result = sub_63023e();
    if (result == -1)
        return result;
    void* pObj = *(void**)((char*)this + 0x54);
    void (__thiscall *fn)(void*) = *(void (__thiscall **)(void*))((char*)pObj + 0x44);
    fn((char*)this + 0x54);
    return 0;
}
