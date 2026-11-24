// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: types are guesses from the disassembly. The names in the callee comments are mislabeled symbols.
struct Iter { int a; int b; };
struct Holder { int v; };

extern "C" int __fastcall fn_00541c70(void* self, int unusedEdx, Iter* out, int key);
extern "C" int __fastcall fn_005409b0(void* self, int unusedEdx, Iter* out);
extern "C" int __fastcall fn_00540ed0(void* self, int unusedEdx, int a1);
extern "C" int fn_0054c610(int a1);
extern "C" int __fastcall fn_00542680(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_005411e0(void* self, int unusedEdx);
extern "C" int __fastcall fn_00541d70(void* self, int unusedEdx, int key, int val);
extern "C" int __fastcall fn_005410b0(void* self, int unusedEdx);
extern "C" int __fastcall fn_00540e20(void* self, int unusedEdx);
extern "C" Iter* __fastcall fn_00541650(void* self, int unusedEdx, Iter* out, int a, int b, int c);
extern "C" int __fastcall fn_00541e00(void* self, int unusedEdx, int key);
extern "C" int __fastcall fn_0054bf70(void* self, int unusedEdx);
extern "C" int __fastcall fn_00542640(void* self, int unusedEdx);

extern "C" void __fastcall fn_00540830(char* self, int unusedEdx, int key)
{
    Iter it;
    Iter tmp;
    Holder h;
    Holder g;
    fn_00541c70(self, 0, &it, key);
    if (!(fn_00540ed0(&it, 0, fn_005409b0(self, 0, &tmp)) & 0xff)) {
        int t = fn_0054c610(fn_0054bf70(&it, 0));
        if (!(fn_00541d70(self + 8, 0, key, t) & 0xff))
            goto done;
    }
    {
        Iter saved = it;
        int r1 = fn_005410b0(&h, 0);
        int r2 = fn_00542680(&g, 0, key, r1);
        Iter* res = fn_00541650(self, 0, &tmp, saved.a, saved.b, r2);
        it = *res;
        fn_005411e0(&g, 0);
        fn_00540e20(&h, 0);
    }
done:
    fn_00542640(&it, 0);
}
