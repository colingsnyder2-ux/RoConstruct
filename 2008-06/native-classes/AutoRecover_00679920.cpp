// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int __fastcall fn_00679120(void* self, int unusedEdx, int a1, int a2, int a3, int a4);

// INFERRED: std::vector<float>-like with a dword at 0 (proxy/allocator) and begin/last/end at +0xc/+0x10/+0x14
struct FloatVec {
    int proxy;
    int pad[2];
    float* first;
    float* last;
    float* end;
};

extern "C" void __fastcall fn_00679920(FloatVec* self, int unusedEdx, const float* val)
{
    int cap = self->first ? (int)(self->end - self->first) : 0;
    if ((int)(self->last - self->first) < cap) {
        *self->last++ = *val;
        return;
    }
    int out[2];
    fn_00679120(self, 0, (int)out, self->proxy, (int)self->last, (int)val);
}
