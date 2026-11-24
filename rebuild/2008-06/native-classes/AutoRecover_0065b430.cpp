// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" int __fastcall fn_0065af80(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
extern "C" int __fastcall fn_0065aee0(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5);
// INFERRED: _Vector_iterator::operator+ ; ecx = iterator, args = (result buffer, offset), returns pointer to iterator
extern "C" int* __fastcall fn_0067c910(void* self, int unusedEdx, void* outBuf, unsigned n);

extern "C" void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: layout of a checked-iterator vector<shared_ptr<Instance>>: container ptr at 0, first/last at 0xc/0x10
struct InstVec {
    int* cont;
    int pad[2];
    int* first;
    int* last;
    int* end;
};

// INFERRED: behaves like vector::resize(newSize, val) with val (8 bytes, shared_ptr) passed on the stack
extern "C" void __fastcall fn_0065b430(InstVec* self, int unusedEdx, unsigned newSize, int v1, int v2)
{
    int* last = self->last;
    unsigned size = (unsigned)(last - self->first) >> 1;
    if (newSize > size) {
        if (self->first > last)
            _invalid_parameter_noinfo();
        fn_0065af80(self, 0, (int)self->cont, (int)self->last,
                    (int)(newSize - (((unsigned)((char*)self->last - (char*)self->first)) >> 3)),
                    (int)&v1);
        return;
    }
    if (newSize < size) {
        if (self->first > last)
            _invalid_parameter_noinfo();
        int* cont = self->cont;
        int* first = self->first;
        if (first > self->last)
            _invalid_parameter_noinfo();
        struct { int* cont; int* ptr; } it;
        it.cont = self->cont;
        it.ptr = first;
        int tmp[2];
        int* r = fn_0067c910(&it, 0, tmp, newSize);
        fn_0065aee0(self, 0, (int)tmp, r[0], r[1], (int)it.cont, (int)last);
        (void)cont;
    }
}
