// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is std::set<int>::_Tidy() (erase(begin(), end()), destroy the
// head node's pointer fields, deallocate the head, zero the head and size).

struct Iter8 { int a; int b; };

extern "C" Iter8* __fastcall fn_005409b0(void* self, int unusedEdx, Iter8* out);
extern "C" Iter8* __fastcall fn_0054f140(void* self, int unusedEdx, Iter8* out);
extern "C" int __fastcall fn_00542fe0(void* self, int unusedEdx, Iter8* ret, int a2, int a3, int a4, int a5);
// INFERRED: the disassembly shows "add esp,4" after these two, so they are cdecl.
extern "C" int fn_0054c630(int a1);
extern "C" int fn_0054c640(int a1);
extern "C" int fn_00541da0(int a1);
extern "C" void __fastcall fn_0054f900(void* self, int unusedEdx, int ptr);
extern "C" void __fastcall fn_00543610(void* self, int unusedEdx, int ptr, int count);

extern "C" void __fastcall fn_00541ca0(void* self, int unusedEdx)
{
    char* p = (char*)self;
    Iter8 tmpEnd;
    Iter8 tmpBegin;
    Iter8 tmpRet;

    Iter8 endIt = *fn_005409b0(self, 0, &tmpEnd);
    Iter8 beginIt = *fn_0054f140(self, 0, &tmpBegin);

    fn_00542fe0(self, 0, &tmpRet, beginIt.a, beginIt.b, endIt.a, endIt.b);

    fn_0054f900(p + 0x10, 0, fn_0054c630(*(int*)(p + 0x18)));
    fn_0054f900(p + 0x10, 0, fn_0054c640(*(int*)(p + 0x18)));
    fn_0054f900(p + 0x10, 0, fn_00541da0(*(int*)(p + 0x18)));
    fn_00543610(p + 0xc, 0, *(int*)(p + 0x18), 1);

    *(int*)(p + 0x18) = 0;
    *(int*)(p + 0x1c) = 0;
}
