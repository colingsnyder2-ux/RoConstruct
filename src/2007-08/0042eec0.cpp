// from server: 100% by colin
// roc 2007-08 0042eec0  unit: CWrapperView  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042eec0
//
// 0042eec0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042eec4  8b01                 mov eax, dword ptr [ecx]
// 0042eec6  8b500c               mov edx, dword ptr [eax + 0xc]
// 0042eec9  c744240454597800     mov dword ptr [esp + 4], 0x785954
// 0042eed1  ffe2                 jmp edx

struct CWrapperView {
    void Dispatch(int);
};

void CWrapperView::Dispatch(int a) {
    typedef void (__thiscall *Fn)(void *, int);
    char *p = (char *)a;
    Fn fn = *(Fn *)(*(char **)p + 0xc);
    fn(p, 0x785954);
}
