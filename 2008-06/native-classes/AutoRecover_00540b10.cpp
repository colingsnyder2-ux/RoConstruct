// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: MSVC 2008 std::_Tree<set<int>>::_Insert-style multi-insert path (unique check constant-folded away).
extern "C" int __fastcall fn_005423f0(void* self, int unusedEdx);
extern "C" int fn_00541d90(int value);
extern "C" int* fn_00541d90_cdecl(int a1);
extern "C" int fn_0054c610(int a1);
extern "C" int* fn_0054c630(int a1);
extern "C" int* fn_00541da0(int a1);
extern "C" int __fastcall fn_00541f70(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
extern "C" bool __fastcall fn_00540ed0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0054e320(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_0054f140(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00542910(void* self, int unusedEdx);
extern "C" int __fastcall fn_0054bf70(void* self, int unusedEdx);
extern "C" bool __fastcall fn_005424e0(void* self, int unusedEdx, int a1, int a2);
extern "C" void* __fastcall fn_00550b20(void* self, int unusedEdx, int a1, int a2);

struct Tree { int pad0[2]; int cmp[4]; int head; };

extern "C" void* __fastcall fn_00540b10(Tree* self, int unusedEdx, void* ret, int* val)
{
    int node = *(int*)fn_005423f0(self, 0, 0);
    int where = self->head;
    bool addLeft = true;
    while (*(char*)fn_00541d90((void*)node, 0, 0) == 0) {
        where = node;
        addLeft = fn_005424e0(&self->cmp, 0, (int)fn_0054c630((int)val), fn_0054c610(node));
        if (addLeft)
            node = *fn_0054c630(node);
        else
            node = *fn_00541da0(node);
    }
    int iter;
    fn_0054e320(&iter, 0, where, (int)self);
    if (addLeft) {
        int tmp;
        if (fn_00540ed0(&iter, 0, fn_0054f140(self, 0, (int)&tmp))) {
            char flag = 1;
            int tmp2;
            fn_00550b20(ret, 0, fn_00541f70(self, 0, (int)&tmp2, 1, where, (int)val), (int)&flag);
            return ret;
        }
    } else {
        fn_00542910(&iter, 0);
    }
    if (fn_005424e0(&self->cmp, 0, fn_0054c610(fn_0054bf70(&iter, 0)), (int)fn_0054c630((int)val))) {
        char flag = 1;
        int tmp3;
        fn_00550b20(ret, 0, fn_00541f70(self, 0, (int)&tmp3, addLeft, where, (int)val), (int)&flag);
        return ret;
    }
    char flag = 0;
    fn_00550b20(ret, 0, (int)&iter, (int)&flag);
    return ret;
}
