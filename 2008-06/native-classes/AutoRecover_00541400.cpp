// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout of the clipper object and the 8-byte sort pair; only the field at +0x10 is used here.
struct ClipperSelf {
    int pad0;
    int pad1;
    int pad2;
    int pad3;
    int endPtr; // +0x10: end of vertex array
};

struct SortedPair {
    int a;
    int b;
};

extern "C" int __fastcall fn_00541360(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int __fastcall fn_005414a0(void* self, int unusedEdx, int a1, int a2);
// ConvexHull2<float>::SortedVertex::operator!=
extern "C" bool __fastcall fn_00540f20(SortedPair* self, int unusedEdx, SortedPair* other);
// stdext::unchecked_copy<Vertex*,Vertex*>
extern "C" int __cdecl fn_00545e60(int first, int last, int dest);

extern "C" SortedPair* __fastcall fn_00541400(ClipperSelf* self, int unusedEdx, SortedPair* ret,
                                              int a1, int a2, int a3, int a4)
{
    SortedPair first;
    SortedPair second;

    fn_00541360(self, 0, (int)&first, a1, a2);
    fn_00541360(self, 0, (int)&second, a3, a4);

    if (fn_00540f20(&first, 0, &second)) {
        int newEnd = fn_00545e60(second.b, self->endPtr, first.b);
        fn_005414a0(self, 0, newEnd, self->endPtr);
        self->endPtr = newEnd;
    }

    ret->a = first.a;
    ret->b = first.b;
    return ret;
}
