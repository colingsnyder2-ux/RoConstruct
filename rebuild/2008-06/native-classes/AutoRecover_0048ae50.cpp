// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: G3D-style Array<Vector4> append(const T&) with aliasing guard; layout {data,size,capacity}.

struct Vec4 { float x, y, z, w; };

struct Vec4Array {
    Vec4* data;
    int size;
    int capacity;
};

// INFERRED: __thiscall grow helper (resize to newSize, shrink flag 0), callee-clean, args (newSize, 0)
extern "C" void __fastcall fn_0048a7c0(Vec4Array* self, int unusedEdx, int newSize, int flag);

extern "C" void __fastcall fn_0048ae50(Vec4Array* self, int unusedEdx, const Vec4* v)
{
    if (self->size < self->capacity) {
        Vec4* slot = self->data + self->size;
        if (slot) {
            slot->x = v->x;
            slot->y = v->y;
            slot->z = v->z;
            slot->w = v->w;
        }
        ++self->size;
        return;
    }

    if (v >= self->data && v < self->data + self->size) {
        // value lives inside the buffer that is about to be reallocated: copy first
        Vec4 tmp = *v;
        fn_0048ae50(self, 0, &tmp);
        return;
    }

    fn_0048a7c0(self, 0, self->size + 1, 0);
    Vec4* last = self->data + (self->size - 1);
    last->x = v->x;
    last->y = v->y;
    last->z = v->z;
    last->w = v->w;
}
