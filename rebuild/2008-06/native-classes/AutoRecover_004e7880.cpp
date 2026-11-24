// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace G3D {
class System {
public:
    static void* alignedMalloc(unsigned int bytes, unsigned int alignment);
    static void memset(void* dst, unsigned char value, unsigned int n);
};
}

// INFERRED: pointer-array container; field names guessed from usage only.
struct PtrArray2008 {
    int unk0;
    int field4;
    void** data;
    int count;
};

extern "C" int __fastcall fn_004e6f50(void* self, int unusedEdx);

extern "C" void __fastcall fn_004e7880(PtrArray2008* self, int unusedEdx, PtrArray2008* other)
{
    self->field4 = other->field4;
    self->count = other->count;
    self->data = (void**)G3D::System::alignedMalloc(self->count * 4, 16);
    G3D::System::memset(self->data, 0, self->count * 4);
    for (int i = 0; i < self->count; ++i) {
        if (other->data[i]) {
            self->data[i] = (void*)fn_004e6f50(other->data[i], 0);
        }
    }
}
