// from server: 100% by colin
struct Helper {
    int f1(int a, int b);
    int f2(int a, int b, int c);
};

extern "C" void* __cdecl sub_45D230();

struct CScriptEditor {
    void init();
};

void CScriptEditor::init()
{
    Helper* p = (Helper*)sub_45D230();
    if (p->f1(0, 1)) {
        p->f2(0, 0, 1);
    } else {
        p->f2(0, 0x20, 1);
    }
}
