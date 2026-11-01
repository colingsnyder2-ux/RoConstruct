// from server: 100% by colin
struct CXTPShadowsManager {
    void func_006efeb0(void*);
};

struct CShadowWnd {
    void func_0062ff4a(int);
};

struct CList {
    void* func_006a2dd0(void*, int);
    void func_006a2d90(void*);
};

void CXTPShadowsManager::func_006efeb0(void* p)
{
    CShadowWnd* w = (CShadowWnd*)p;
    if (w != 0 && *(int*)((char*)w + 0x20) != 0)
    {
        w->func_0062ff4a(0);
    }
    *(int*)((char*)w + 0x64) = 0;
    CList* list = (CList*)((char*)this + 4);
    void* v = list->func_006a2dd0(w, 0);
    list->func_006a2d90(v);
    void** vt = *(void***)w;
    ((void (__thiscall*)(void*))vt[0x68/4])(w);
    void** vt2 = *(void***)w;
    ((void (__thiscall*)(void*, int))vt2[1])(w, 1);
}
