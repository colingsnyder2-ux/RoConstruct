// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: type descriptors at 0x92907c (source) and 0x949680 (target) are unnamed RTTI data.
extern "C" char fn_005cbf50_srcType;
extern "C" char fn_005cbf50_dstType;
extern "C" void* __cdecl __RTDynamicCast(void* inptr, long vfDelta, void* srcType, void* targetType, int isReference);

// INFERRED: object with a parent pointer at +0x104.
struct Node {
    char pad[0x104];
    Node* parent;
};

// Walks the parent chain and returns the first ancestor that dynamic_casts to the target type, else null.
extern "C" void* __fastcall fn_005cbf50(Node* self, int unusedEdx)
{
    Node* n = self->parent;
    while (n) {
        void* r = __RTDynamicCast(n, 0, &fn_005cbf50_srcType, &fn_005cbf50_dstType, 0);
        if (r)
            return r;
        n = n->parent;
    }
    return 0;
}
