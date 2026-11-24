// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::set<int>-style _Tree::insert(hint-less) body; types are guesses from the disassembly.
extern "C" int* __fastcall fn_005423f0(void* self, int unusedEdx);
extern "C" char* __cdecl fn_00542e00(int node);
extern "C" int __cdecl fn_0054c610(int node);
extern "C" int __cdecl fn_0054c630(int key);
extern "C" int __cdecl fn_00541da0(int node);
extern "C" void* __fastcall fn_00543100(TreeImpl* self, int unusedEdx, void* ret, bool addLeft, TreeNode* where, int val);
extern "C" int __fastcall fn_00540ed0(void* self, int unusedEdx, int a1);
extern "C" void __fastcall fn_00550b20(void* self, int unusedEdx, int a1, void* a2);
extern "C" void __fastcall fn_0054e320(void* self, int unusedEdx, int where, void* tree);
extern "C" int __fastcall fn_0054f140(void* self, int unusedEdx, void* out);
extern "C" void __fastcall fn_00545710(void* self, int unusedEdx);
extern "C" int __fastcall fn_0054bf70(void* self, int unusedEdx);
extern "C" char __fastcall fn_00541d70(void* cmp, int unusedEdx, int a, int b);

extern "C" int* __fastcall fn_00542e10(char* self, int unusedEdx, int* ret, int key)
{
    int node = *fn_005423f0(self, 0);
    int where = *(int*)(self + 0x18);
    char addLeft = 1;
    while (*fn_00542e00(node) == 0) {
        where = node;
        addLeft = fn_00541d70(self + 8, 0, fn_0054c630(key), fn_0054c610(node));
        node = addLeft ? *(int*)fn_0054c630(node) : *(int*)fn_00541da0(node);
    }
    char yes;
    char tmp[0x20];
    char it[0x10];
    fn_0054e320(it, 0, where, self);
    if (addLeft) {
        char b[0x10];
        if (fn_00540ed0(it, 0, fn_0054f140(self, 0, b)) & 0xff) {
            yes = 1;
            fn_00550b20(ret, 0, fn_00543100(self, 0, tmp, 1, where, key, &yes), 0);
            return ret;
        }
    } else {
        fn_00545710(it, 0);
    }
    if (fn_00541d70(self + 8, 0, fn_0054c610(fn_0054bf70(it, 0)), fn_0054c630(key)) & 0xff) {
        yes = 1;
        fn_00550b20(ret, 0, fn_00543100(self, 0, tmp, addLeft, where, key, &yes), 0);
        return ret;
    }
    char no = 0;
    fn_00550b20(ret, 0, (int)it, &no);
    return ret;
}
