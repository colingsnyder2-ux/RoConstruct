// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is std::vector<T>::_Insert_n(where, count, val) for a 4-byte,
// ref-counted element type. The vector layout is: allocator at +8, first at +0xc,
// last at +0x10, end at +0x14. The first stack arg is unused.

extern "C" int __fastcall fn_005462e0(void* self, int unusedEdx);   // capacity
extern "C" int __fastcall fn_00546320(void* self, int unusedEdx);   // size
extern "C" int __fastcall fn_00542a30(void* self, int unusedEdx);   // max_size
extern "C" int fn_00553270(void);                                   // _Xlen
extern "C" int __fastcall fn_00542de0(void* self, int unusedEdx, int a1); // allocate
extern "C" int __fastcall fn_00541540(void* self, int unusedEdx, int a1, int a2, int a3); // _Ufill
extern "C" int __fastcall fn_005414a0(void* self, int unusedEdx, int a1, int a2);         // _Destroy
extern "C" int __fastcall fn_00545fa0(void* self, int unusedEdx, int first, int last, int dest); // _Umove
extern "C" void fn_00545fd0(int first, int last, const void* val);          // std::fill
extern "C" int fn_00546000(int first, int last, int dest);                  // move_backward
extern "C" void __fastcall fn_00543610(void* alloc, int unusedEdx, int ptr, int count); // deallocate
extern "C" void __fastcall fn_004f0820(void* self, int unusedEdx, const void* other);   // ref copy ctor
extern "C" void __fastcall fn_00502a70(void* self, int unusedEdx);          // ref dtor

namespace {
struct RefElem {
    int p;
    RefElem(const RefElem& o) { fn_004f0820(this, 0, &o); }
    ~RefElem() { fn_00502a70(this, 0); }
};
}

extern "C" void __fastcall fn_00542a50(void* self, int unusedEdx, int unusedArg, int where, unsigned count, const RefElem* val)
{
    char* base = (char*)self;
    int*& pFirst = *(int**)(base + 0xc);
    int*& pLast  = *(int**)(base + 0x10);
    int*& pEnd   = *(int**)(base + 0x14);
    void* alloc  = base + 8;

    unsigned cap = (unsigned)fn_005462e0(self, 0);
    if (count == 0)
        return;

    if ((unsigned)fn_00542a30(self, 0) - (unsigned)fn_00546320(self, 0) < count) {
        fn_00553270();
        return;
    }

    if (cap < (unsigned)fn_00546320(self, 0) + count) {
        unsigned half = cap >> 1;
        if ((unsigned)fn_00542a30(self, 0) - half < cap)
            cap = 0;
        else
            cap = cap + (cap >> 1);
        if (cap < (unsigned)fn_00546320(self, 0) + count)
            cap = (unsigned)fn_00546320(self, 0) + count;

        int newvec = fn_00542de0(alloc, 0, (int)cap);
        int newlast = newvec;
        try {
            newlast = fn_00545fa0(self, 0, (int)pFirst, where, newvec);
            newlast = fn_00541540(self, 0, newlast, (int)count, (int)val);
            fn_00545fa0(self, 0, where, (int)pLast, newlast);
        } catch (...) {
            fn_005414a0(self, 0, newvec, newlast);
            fn_00543610(alloc, 0, newvec, (int)cap);
            throw;
        }
        count += (unsigned)fn_00546320(self, 0);
        if (pFirst) {
            fn_005414a0(self, 0, (int)pFirst, (int)pLast);
            fn_00543610(alloc, 0, (int)pFirst, (int)(pEnd - pFirst));
        }
        pEnd = (int*)newvec + cap;
        pLast = (int*)newvec + count;
        pFirst = (int*)newvec;
    }
    else if ((unsigned)(pLast - (int*)where) < count) {
        RefElem tmp(*val);
        fn_00545fa0(self, 0, where, (int)pLast, (int)((int*)where + count));
        try {
            fn_00541540(self, 0, (int)pLast, (int)(count - (unsigned)(pLast - (int*)where)), (int)&tmp);
        } catch (...) {
            fn_005414a0(self, 0, (int)((int*)where + count), (int)(pLast + count));
            throw;
        }
        pLast = pLast + count;
        fn_00545fd0(where, (int)((char*)pLast - count * 4), &tmp);
    }
    else {
        RefElem tmp(*val);
        int* oldLast = pLast;
        pLast = (int*)fn_00545fa0(self, 0, (int)(oldLast - count), (int)oldLast, (int)pLast);
        fn_00546000(where, (int)((char*)oldLast - count * 4), (int)oldLast);
        fn_00545fd0(where, (int)((int*)where + count), &tmp);
    }
}
