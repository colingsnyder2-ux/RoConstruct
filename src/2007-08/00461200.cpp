// from server: 29% by colin
struct CScriptEditor {
    void construct();
};

extern "C" void* __cdecl operator_new(unsigned int size);

void* CScriptEditor_new()
{
    CScriptEditor* p = (CScriptEditor*)operator_new(0x150);
    if (p == 0) {
        p->construct();
    }
    return p;
}
