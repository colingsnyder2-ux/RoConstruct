// from server: 100% by Xemicl
// roc 2012-06 007323e0  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007323e0
//
// 007323e0  8b442404             mov eax, dword ptr [esp + 4]
// 007323e4  39818c000000         cmp dword ptr [ecx + 0x8c], eax
// 007323ea  7413                 je 0x7323ff
// 007323ec  89818c000000         mov dword ptr [ecx + 0x8c], eax
// 007323f2  c74424044038e300     mov dword ptr [esp + 4], 0xe33840
// 007323fa  e9a129ceff           jmp 0x414da0
// 007323ff  c20400               ret 4
// copied from an identical function in another client (function ?setValue@X005d8a90@RBX@@QAEXH@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor&);
};
class X005d8a90 : public Instance {
    char pad[0x8c];
    int value;
public:
    void setValue(int v);
};
extern Reflection::PropertyDescriptor prop_X005d8a90;
void X005d8a90::setValue(int v)
{
    if (value != v) {
        value = v;
        raisePropertyChanged(prop_X005d8a90);
    }
}
}