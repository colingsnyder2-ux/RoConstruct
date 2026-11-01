// from server: 100% by colin
struct CScriptEditor {
    void* field0;

    void sub_45FFD0();
};

extern "C" void* __cdecl sub_45D230();

struct Helper {
    void* sub_45BF60(int);
    void* sub_45CA50(void*, int);
    void* sub_45C290(void*, int, int);
};

void CScriptEditor::sub_45FFD0()
{
    Helper* p = (Helper*)sub_45D230();
    void* a = p->sub_45BF60(1);
    void* b = p->sub_45CA50(a, 1);
    p->sub_45C290(b, 0, 1);
}
