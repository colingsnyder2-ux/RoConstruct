// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a std::set<int> (_Tree) clear()/_Tidy-style routine:
// erase(begin(), end()), destroy and free the head node, null head and size.
// Layout: +0x0c node allocator, +0x10 value allocator, +0x18 head, +0x1c size.

struct FnIter {
    int a;
    int b;
};

extern "C" FnIter* __fastcall fn_005409b0(void* self, int unusedEdx, FnIter* out);
extern "C" FnIter* __fastcall fn_0054f140(void* self, int unusedEdx, FnIter* out);
extern "C" int __fastcall fn_00541e20(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5);
extern "C" int fn_0054c630(int a1);
extern "C" char *fn_0054c640(char* self);
extern "C" char *fn_00541da0(char* self);
extern "C" void __fastcall fn_0054f900(void* self, int unusedEdx, int ptr);
extern "C" void __fastcall fn_00543610(void* self, int unusedEdx, int ptr, int count);

extern "C" void __fastcall fn_00542410(void* self, int unusedEdx)
{
    char* p = (char*)self;
    FnIter tmpEnd, tmpBegin;
    int erased[1];

    FnIter* e = fn_005409b0(self, 0, &tmpEnd);
    FnIter endIt = *e;
    FnIter* b = fn_0054f140(self, 0, &tmpBegin);
    FnIter beginIt = *b;

    fn_00541e20(self, 0, (int)erased, beginIt.a, beginIt.b, endIt.a, endIt.b);

    int head = *(int*)(p + 0x18);
    fn_0054f900(p + 0x10, 0, fn_0054c630(head));
    fn_0054f900(p + 0x10, 0, fn_0054c640(self, 0, *(int*)(p + 0x18)));
    fn_0054f900(p + 0x10, 0, fn_00541da0(self, 0, *(int*)(p + 0x18)));
    fn_00543610(p + 0xc, 0, *(int*)(p + 0x18), 1);

    *(int*)(p + 0x18) = 0;
    *(int*)(p + 0x1c) = 0;
}
