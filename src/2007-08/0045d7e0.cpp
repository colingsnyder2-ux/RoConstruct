// from server: 100% by colin
struct CScintillaView {
    char pad[0x58];
    int field_58;
    int InsertText(int pos, int length, const char* text);
    int ReplaceSel(int pos, int length, const char* text);
    int SomeMethod(int a, int b);
};

int CScintillaView::SomeMethod(int a, int b) {
    int* self = (int*)((char*)this + 0x58);
    int result = ((CScintillaView*)self)->InsertText(a, b, (const char*)1);
    if (result != -1) {
        ((CScintillaView*)self)->ReplaceSel(*(int*)(b + 0xc), *(int*)(b + 0x10), (const char*)1);
    }
    return result;
}
