// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::set<int>::erase(first, last) with 8-byte iterators; begin/end/clear/==/!=/++/erase/_Make_iter are extern helpers.
struct It8 { int a, b; };

extern "C" It8* __fastcall fn_0054f140(void* self, int unusedEdx, It8* ret);
extern "C" int __fastcall fn_00540ed0(void* self, int unusedEdx, It8* a1);
extern "C" int __fastcall fn_005409b0(void* self, int unusedEdx, It8* a1);
extern "C" int __fastcall fn_00540d60(void* self, int unusedEdx);
extern "C" bool __fastcall fn_00540f20(void* self, int unusedEdx, It8* a1);
extern "C" It8* __fastcall fn_00544570(void* self, int unusedEdx, It8* ret, int a2);
extern "C" int __fastcall fn_00543670(void* self, int unusedEdx, It8* ret, int a, int b);
extern "C" It8* __fastcall fn_00544730(void* self, int unusedEdx, It8* ret, int a, int b);

extern "C" It8* __fastcall fn_00541e20(void* self, int unusedEdx, It8* ret, It8 first, It8 last)
{
    It8 t8, t10, t18, t20;
    if ((unsigned char)fn_00540ed0(&first, 0, fn_0054f140(self, 0, &t8))
        && (unsigned char)fn_00540ed0(&last, 0, (It8*)fn_005409b0(self, 0, &t10)))
    {
        fn_00540d60(self, 0);
        fn_0054f140(self, 0, ret);
        return ret;
    }
    while ((unsigned char)fn_00540f20(&first, 0, &last)) {
        It8* p = fn_00544570(&first, 0, &t18, 0);
        fn_00543670(self, 0, &t20, p->a, p->b);
    }
    fn_00544730(self, 0, ret, first.a, first.b);
    return ret;
}
