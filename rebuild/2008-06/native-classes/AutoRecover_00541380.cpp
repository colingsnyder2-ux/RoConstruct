// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this looks like std::vector<T>::insert(iterator where, const T& val), returning
// the new iterator through a hidden sret pointer (a1). The checked iterator is 8 bytes
// (a2/a3). It calls _Insert_n(where, 1, val) and returns begin() + offset.

extern "C" int __fastcall fn_00546320(void* self, int unusedEdx);
extern "C" int __fastcall fn_00540630(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00544500(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00542a50(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
// INFERRED: iterator operator+ with hidden return pointer, three stack args
extern "C" int __fastcall fn_00546770(void* self, int unusedEdx, int a1, int a2, int a3);

extern "C" int __fastcall fn_00541380(void* self, int unusedEdx, int a1, int a2, int a3, int a4)
{
    int tmp1[2];
    int tmp2[2];
    int offset;

    if (fn_00546320(self, 0) == 0)
        offset = 0;
    else
        offset = fn_00544500(&a2, 0, fn_00540630(self, 0, (int)tmp1));

    fn_00542a50(self, 0, a2, a3, 1, a4);
    fn_00546770((void*)fn_00540630(self, 0, (int)tmp2), 0, (int)tmp2, a1, offset);
    return a1;
}
