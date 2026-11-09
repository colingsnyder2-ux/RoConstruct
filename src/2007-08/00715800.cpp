// from server: 100% by colin
struct CXTCaptionButton {
    void OnLButtonDown();
    void* GetParent();
};

extern "C" int (__stdcall *InvalidateRect)(void*, const void*, int);

void CXTCaptionButton::OnLButtonDown()
{
    if (((int (__thiscall*)(void*))*(void**)(*(int*)this + 0x164))(this) != 0)
    {
        void* p = GetParent();
        if (((int (__thiscall*)(void*))*(void**)(*(int*)p + 0x18))(p) != 0)
        {
            void* q = GetParent();
            ((void (__thiscall*)(void*, int))*(void**)(*(int*)q + 0x1c))(q, 0);
        }
        else
        {
            void* q = GetParent();
            ((void (__thiscall*)(void*, int))*(void**)(*(int*)q + 0x1c))(q, 1);
        }
        InvalidateRect(*(void**)((char*)this + 0x20), 0, 1);
    }
}
