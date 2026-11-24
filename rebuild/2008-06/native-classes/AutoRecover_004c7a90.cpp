// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is the MSVC 2008 std::vector<T>::_Insert_n(where, count, val)
// with a 4-byte element type. The value is copied through the x87 stack
// (fld/fstp), so T is modelled as float. The first stack argument is unused.
// INFERRED: layout is 0xc bytes of allocator/proxy data, then _Myfirst, _Mylast, _Myend.
struct FloatVec {
    int pad[3];
    float* first;
    float* last;
    float* end;
};

extern "C" void  __cdecl   fn_004c6d40();                                     // _Xlen
extern "C" float* __cdecl  fn_00420b50(unsigned count, void* hint);           // _Allocate
extern "C" float* __fastcall fn_00423c00(void* self, int unusedEdx, float* first, float* last, float* dest); // _Umove
extern "C" float* __fastcall fn_004c7700(void* self, int unusedEdx, float* dest, unsigned count, const float* val); // _Ufill
extern "C" void  __cdecl   fn_004c71b0(float* first, float* last, const float* val); // fill (cdecl per disassembly)
extern "C" float* __cdecl  fn_00459670(float* first, float* last, float* dest);      // copy_backward

extern "C" void __fastcall fn_004c7a90(FloatVec* self, int unusedEdx, int unused,
                                       float* where, unsigned count, const float* val)
{
    unsigned cap = self->first ? (unsigned)(self->end - self->first) : 0;
    if (count == 0)
        return;

    unsigned size = (unsigned)(self->last - self->first);
    if (0x3fffffffu - size < count)
        fn_004c6d40();

    if (cap < size + count) {
        unsigned half = cap >> 1;
        if (0x3fffffffu - half < cap)
            cap = 0;
        else
            cap += half;
        if (cap < size + count)
            cap = size + count;

        float* newvec = fn_00420b50(cap, 0);
        float* p = fn_00423c00(self, 0, self->first, where, newvec);
        p = fn_004c7700(self, 0, p, count, val);
        fn_00423c00(self, 0, where, self->last, p);

        unsigned newsize = count + (unsigned)(self->last - self->first);
        if (self->first)
            ::operator delete(self->first);
        self->end   = newvec + cap;
        self->last  = newvec + newsize;
        self->first = newvec;
    }
    else if ((unsigned)(self->last - where) < count) {
        float tmp = *val;
        fn_00423c00(self, 0, where, self->last, where + count);
        fn_004c7700(self, 0, self->last, count - (unsigned)(self->last - where), &tmp);
        self->last += count;
        fn_004c71b0(where, self->last - count, &tmp);
    }
    else {
        float tmp = *val;
        float* oldlast = self->last;
        self->last = fn_00423c00(self, 0, oldlast - count, oldlast, oldlast);
        fn_00459670(where, oldlast - count, oldlast);
        fn_004c71b0(where, where + count, &tmp);
    }
}
