// from server: 100% by colin
struct CScriptEditor {
    void init();
};

struct Helper {
    int f1(int a, int b);
    int f2(int a, int b, int c);
};

extern "C" void* __cdecl sub_45D230();

void CScriptEditor::init()
{
    Helper* p = (Helper*)sub_45D230();
    if (p->f1(2, 1)) {
        p->f2(2, 0, 1);
    } else {
        p->f2(2, 0x10, 1);
    }
}
