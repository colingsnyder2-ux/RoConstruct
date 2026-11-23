// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::map/set-style tree erase(first, last) with checked iterators {container, node}.
struct TreeIter {
    void* cont;
    int* node;
};

struct TreeSelf {
    void* proxy;
    char pad[0x14]; // INFERRED: unused here
    int* head;
    int size;
};

extern "C" int __fastcall fn_0068fff0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0068d3e0(void* self, int unusedEdx);
extern "C" int __fastcall fn_00691f90(void* self, int unusedEdx, int a1, int a2, int a3);

extern "C" TreeIter* __fastcall fn_006939b0(TreeSelf* self, int unusedEdx, TreeIter* out,
                                            TreeIter first, TreeIter last)
{
    if ((int)first.node == self->head[0] && (int)last.node == (int)self->head) {
        fn_0068fff0(self, 0, self->head[1]);
        self->head[1] = (int)self->head;
        self->size = 0;
        self->head[0] = (int)self->head;
        self->head[2] = (int)self->head;
        out->cont = self->proxy;
        out->node = (int*)self->head[0];
        return out;
    }
    while (first.node != last.node) {
        int* cur = first.node;
        void* c = first.cont;
        fn_0068d3e0(&first, 0);
        TreeIter tmp;
        fn_00691f90(self, 0, (int)&tmp, (int)c, (int)cur);
    }
    out->cont = self->proxy;
    out->node = first.node;
    return out;
}
