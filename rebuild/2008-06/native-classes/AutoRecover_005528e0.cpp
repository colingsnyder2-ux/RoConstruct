// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout from offsets only; vector at +0xc, count at +0x24.
struct Node {
    char pad[0xc];
    char vec[0x18];
    int count;
};

extern "C" int __fastcall fn_00546320(void* self, int unusedEdx);
extern "C" void __fastcall fn_00546210(void* self, int unusedEdx, int* v);
extern "C" int* __fastcall fn_00552e60(void* self, int unusedEdx, int a1);
extern "C" Node* __fastcall fn_005529b0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_005528e0(void* self, int unusedEdx, int a1, Node* a2);

extern "C" int __fastcall fn_005528e0(void* self, int unusedEdx, int a1, Node* a2)
{
    while (1) {
        if (fn_00546320(a2->vec, 0) == a2->count) {
            fn_00546210(a2->vec, 0, &a1);
            a2->count++;
            return 1;
        }
        int v = *fn_00552e60(a2->vec, 0, a2->count);
        Node* r = fn_005529b0(self, 0, v);
        if (r == a2) {
            a2->count++;
            continue;
        }
        *fn_00552e60(a2->vec, 0, a2->count) = a1;
        return fn_005528e0(self, 0, v, r) + 1;
    }
}
