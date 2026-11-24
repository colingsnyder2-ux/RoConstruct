// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int fn_0054c630(int a1, int a2);
extern "C" int fn_00541d90(int value);

// INFERRED: walks a linked list (node = *fn_0054c630(node)) until the name/char at fn_00541d90(...) is non-zero
extern "C" int fn_00545510(int node)
{
    for (;;) {
        int* next = (int*)fn_0054c630(node, 0);
        int* p = (int*)fn_00541d90((void*)0, 0, *next);
        if (*(char*)p != 0)
            return node;
        node = *(int*)fn_0054c630(node, 0);
    }
}
