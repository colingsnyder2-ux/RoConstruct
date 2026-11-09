// from server: 100% by colin
struct CXTMaskEditT {
    char pad[0x9c];
    void* field_9c;
    void* field_a0;
    char pad2[0x8];
    int field_ac;
    void Invalidate();
};

extern "C" int (__stdcall *InvalidateRect)(void*, const void*, int);

extern "C" void __fastcall sub_00630004(void*);

void CXTMaskEditT::Invalidate()
{
    if (field_9c != 0) {
        InvalidateRect(*(void**)((char*)field_9c + 0x20), 0, 0);
        if (field_a0 != 0) {
            void** vtbl = *(void***)field_a0;
            int (__fastcall *fn)(void*) = (int (__fastcall *)(void*))vtbl[0x90 / 4];
            if (fn(field_a0) == 0) {
                sub_00630004(field_9c);
            }
        }
        field_ac = 1;
    }
}
