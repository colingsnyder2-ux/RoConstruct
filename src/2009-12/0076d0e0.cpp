// from server: 89% by atomic.potato
extern "C" void* __cdecl sub_7f4aaa(const char*, const char*, int, int, int);

struct RBX_GuiBase {
    virtual bool isA(const char*);
};

bool __stdcall check(const char* name) {
    RBX_GuiBase* p = (RBX_GuiBase*)sub_7f4aaa(name, ".?AVGuiBase@RBX@@", 0, (int)".?AVInstance@RBX@@", 0);
    if (p) {
        return p->isA(".?AVInstance@RBX@@") == false;
    }
    return false;
}
