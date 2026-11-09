// from server: 49% by atomic.potato
extern "C" {
    int __cdecl func_009222d0(void*, void*);
    int __cdecl func_00917430(void*, void*);
    int __cdecl func_007b9d40(void*);
    int __cdecl func_00963fc0(void*, void*);
    int __cdecl func_00972290(int, const char*);
}

extern unsigned char g_e580b3;
extern int (__cdecl *g_e5809c)(int, const char*, const char*);

struct TreeStage {
    char pad0[8];
    void* field8;
    char padC[4];
    void* field10;
    void addEntity(void* e);
};

void TreeStage::addEntity(void* e)
{
    if (g_e580b3) {
        if (!func_009222d0(*(void**)((char*)e + 0xc), this)) {
            if (g_e5809c) {
                if (g_e5809c(0x1a1, (const char*)0xbfb9a8, (const char*)0xbfbb78))
                    goto skip1;
            }
            func_00972290(g_e580b3, (const char*)0xbfbae8);
        }
    skip1:
        if (g_e580b3) {
            void* p = *(void**)((char*)e + 0x10);
            if (p) {
                if (!func_009222d0(p, this)) {
                    if (g_e5809c) {
                        if (g_e5809c(0x1a2, (const char*)0xbfb9a8, (const char*)0xbfbaa0))
                            goto skip2;
                    }
                    func_00972290(g_e580b3, (const char*)0xbfb9f8);
                }
            }
        }
    }
skip2:
    func_00917430(e, this);
    if (func_007b9d40(e)) {
        void* p = e ? (void*)((char*)e + 0x1c) : 0;
        func_00963fc0((char*)this + 0x10, p);
        int v = (*(int (__cdecl**)(void*))(*(int*)e + 0x10))(e);
        if (v == 0) {
            int w = (*(int (__cdecl**)(void*))(*(int*)e + 0x18))(e);
            if (w == 1 || w == 3 || w == 2)
                return;
        }
        v = (*(int (__cdecl**)(void*))(*(int*)e + 0x10))(e);
        if (v == 0) {
            int w = (*(int (__cdecl**)(void*))(*(int*)e + 0x18))(e);
            if (w == 0xb || w == 0)
                return;
        }
    }
    (*(void (__cdecl**)(void*, void*))(*(int*)field8 + 0xc))(field8, e);
}
