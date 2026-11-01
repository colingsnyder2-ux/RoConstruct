// from server: 100% by colin
// roc 2007-08 00438740  unit: _NVCXTPPropertyGridItemBool::?$XItem  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00438740
//
// 00438740  8b542404             mov edx, dword ptr [esp + 4]
// 00438744  0fb612               movzx edx, byte ptr [edx]
// 00438747  8b01                 mov eax, dword ptr [ecx]
// 00438749  8b80e4000000         mov eax, dword ptr [eax + 0xe4]
// 0043874f  89542404             mov dword ptr [esp + 4], edx
// 00438753  ffe0                 jmp eax
// copied from an identical function in another client (function ?XItem@S@@QAEXPAE@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S
{
    int (**vtable)();

    void XItem(unsigned char *value);
};

void S::XItem(unsigned char *value)
{
    value = (unsigned char *)(*value);
    ((void (__thiscall *)(S *, unsigned char *))vtable[0x39])(this, value);
}