// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace G3D {
class System {
public:
    static void* alignedMalloc(unsigned int bytes, unsigned int alignment);
    static void memset(void* dst, unsigned char value, unsigned int numBytes);
};
}

// INFERRED: layout from the disassembly offsets; +0 is untouched by this function.
struct Table4E7810 {
    int field0;
    int field4;
    void** buckets;
    int count;
};

// Callee only reads ecx; a single fastcall arg avoids the dummy edx zeroing.
extern "C" void* __fastcall fn_004e6eb0(void* self);

extern "C" void __fastcall fn_004e7810(Table4E7810* self, int unusedEdx, Table4E7810* other)
{
    self->field4 = other->field4;
    self->count = other->count;
    self->buckets = (void**)G3D::System::alignedMalloc(self->count * 4, 16);
    G3D::System::memset(self->buckets, 0, self->count * 4);
    for (int i = 0; i < self->count; ++i) {
        if (other->buckets[i] != 0) {
            self->buckets[i] = fn_004e6eb0(other->buckets[i]);
        }
    }
}
