// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout taken from the disassembly: vtable at +0, heap handle at +4, owns-heap flag at +8.
struct HeapHolder {
    void* m_vtable;
    void* m_heap;
    char  m_ownsHeap;
};

// INFERRED: unknown global at 0x00871f58 (a vtable) stored into the object's first dword.
extern "C" char g_00871f58[];

extern "C" __declspec(dllimport) int __stdcall HeapDestroy(void* hHeap);

extern "C" void __fastcall fn_007a5d12(HeapHolder* self, int unusedEdx)
{
    self->m_vtable = g_00871f58;
    if (self->m_ownsHeap != 0) {
        void* h = self->m_heap;
        if (h != 0) {
            HeapDestroy(h);
        }
    }
}
