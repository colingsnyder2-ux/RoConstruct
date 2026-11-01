// from server: 100% by tester
struct CXTMaskEditT {
    char pad[0x9c];
    void* field_9c;
    void* field_a0;
    void Invalidate();
};

extern "C" int (__stdcall *InvalidateRect)(void*, const void*, int);

void CXTMaskEditT::Invalidate()
{
    if (field_9c != 0 && field_a0 != 0) {
        (*(void (__thiscall**)(void*))(*(int*)field_a0 + 0x9c))(field_a0);
        void* p = field_9c;
        if (p != 0) {
            InvalidateRect(*(void**)((char*)p + 0x20), 0, 0);
        }
    }
}
