// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this is std::vector<boost::shared_ptr<RBX::Instance>>::_Insert_n
// (VC9, _SECURE_SCL iterator passed as container+ptr = 2 dwords).
#include <new>

struct SPEntry { unsigned px; unsigned pn; }; // boost::shared_ptr<Instance>, 8 bytes

struct InstVec {
    int pad0;
    int pad1;
    int alloc;          // +8  (empty allocator, address passed)
    SPEntry* first;     // +0xc
    SPEntry* last;      // +0x10
    SPEntry* end;       // +0x14
};

extern "C" Elem8 *fn_00659f60(Elem8* first, Elem8* last, Elem8* dest);
extern "C" int __fastcall fn_0065ac20(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int __fastcall fn_0067d5b0(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int fn_00670820(int a1, int a2, int a3);
extern "C" int fn_0065a830(int a1, int a2, int a3);
extern "C" void fn_004c6d40();                       // _Xlen
extern "C" SPEntry* fn_0066fd40(unsigned n, int z);  // _Allocate

extern "C" void __fastcall fn_0065af80(InstVec* self, int unusedEdx, int container, SPEntry* where, unsigned count, const SPEntry* val)
{
    unsigned cap = self->first ? (unsigned)(self->end - self->first) : 0;
    if (count == 0)
        return;

    unsigned sz = (unsigned)(self->last - self->first);
    if (0x1fffffffu - sz < count) {
        fn_004c6d40();
    }
    unsigned need = sz + count;
    if (cap < need) {
        unsigned newcap;
        if (0x1fffffffu - (cap >> 1) < cap)
            newcap = 0;
        else
            newcap = cap + (cap >> 1);
        if (newcap < need)
            newcap = need;

        SPEntry* newvec = fn_0066fd40(newcap, 0);
        SPEntry* p;
        try {
            p = (SPEntry*)fn_00659f60(&self->alloc - 0 /*dummy*/, 0, 0, 0, 0, 0, 0, 0);
            (void)p;
        } catch (...) {
        }
        // Real sequence (see disassembly):
        try {
            int r = fn_00659f60(self->first, 0, (int)self->first, (int)where, (int)newvec, (int)&self->alloc, (int)val, 0);
            r = fn_0065ac20(self, 0, r, (int)count, (int)val);
            fn_00659f60(self->last, 0, (int)where, (int)self->last, r, (int)&self->alloc, 0, 0);
        } catch (...) {
            ::operator delete(newvec);
            throw;
        }
        if (self->first)
            ::operator delete(self->first);
        self->end = newvec + newcap;
        self->last = newvec + (count + (unsigned)(self->last - self->first));
        self->first = newvec;
    } else if ((unsigned)(self->last - where) < count) {
        SPEntry tval = *val;
        fn_0067d5b0(self, 0, (int)where, (int)self->last, (int)(where + count));
        fn_0065ac20(self, 0, (int)self->last, (int)(count - (unsigned)(self->last - where)), (int)&tval);
        self->last += count;
        fn_00670820((int)where, (int)(self->last - count), (int)&tval);
    } else {
        SPEntry tval = *val;
        SPEntry* oldlast = self->last;
        self->last = (SPEntry*)fn_0067d5b0(self, 0, (int)(oldlast - count), (int)oldlast, (int)oldlast);
        fn_0065a830((int)where, (int)(oldlast - count), (int)oldlast);
        fn_00670820((int)where, (int)(where + count), (int)&tval);
    }
}
