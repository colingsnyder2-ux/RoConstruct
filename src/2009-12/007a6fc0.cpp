// from server: 100% by atomic.potato
struct RBX_AnchorTool {
    char pad[0x18];
    void* field_18;
    void SetParent(void*);
};

extern "C" void* __cdecl sub_7f4aaa(void*, int, int, int, int);

void RBX_AnchorTool::SetParent(void* p)
{
    void* v = field_18;
    if (v) {
        void* r = sub_7f4aaa(v, 0, 0xaffe40, 0xb1c3ec, 0);
        if (r) {
            void** vt = *(void***)r;
            typedef void (__thiscall *Fn)(void*, void*, int);
            Fn fn = (Fn)vt[4];
            fn(r, p, 0);
        }
    }
}
