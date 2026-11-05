// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0056e6e0  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e6e0
//
// 0056e6e0  56                   push esi
// 0056e6e1  57                   push edi
// 0056e6e2  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0056e6e6  8bf1                 mov esi, ecx
// 0056e6e8  8bcf                 mov ecx, edi
// 0056e6ea  e821e10000           call 0x57c810
// 0056e6ef  84c0                 test al, al
// 0056e6f1  7525                 jne 0x56e718
// 0056e6f3  8d442410             lea eax, [esp + 0x10]
// 0056e6f7  50                   push eax
// 0056e6f8  8d4f10               lea ecx, [edi + 0x10]
// 0056e6fb  e8b0de0000           call 0x57c5b0
// 0056e700  84c0                 test al, al
// 0056e702  7414                 je 0x56e718
// 0056e704  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0056e707  8b11                 mov edx, dword ptr [ecx]
// 0056e709  8b520c               mov edx, dword ptr [edx + 0xc]
// 0056e70c  8d442410             lea eax, [esp + 0x10]
// 0056e710  50                   push eax
// 0056e711  8b442410             mov eax, dword ptr [esp + 0x10]
// 0056e715  50                   push eax
// 0056e716  ffd2                 call edx
// 0056e718  5f                   pop edi
// 0056e719  5e                   pop esi
// 0056e71a  c20c00               ret 0xc

class XmlElement {
public:
    bool isXsiNil() const;
};

namespace RBX {
class DescribedBase;
namespace Reflection {
class IReferenceBinder;

struct GetSet {
    virtual ~GetSet();
    virtual bool isReadOnly() const;
    virtual bool getValue() const;
    virtual void setValue(DescribedBase*, const bool&);
};

template<typename T>
class TypedPropertyDescriptor {
public:
    virtual void readValue(DescribedBase*, const XmlElement*, IReferenceBinder&) const;
};

struct XmlValueBase {
    bool getValue(bool&) const;
};

template<>
void TypedPropertyDescriptor<bool>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
    if (!element->isXsiNil())
    {
        bool value;
        const XmlValueBase* vb = reinterpret_cast<const XmlValueBase*>(reinterpret_cast<const char*>(element) + 0x10);
        if (vb->getValue(value))
        {
            GetSet* gs = *reinterpret_cast<GetSet**>(const_cast<char*>(reinterpret_cast<const char*>(this)) + 0x18);
            gs->setValue(instance, value);
        }
    }
}
}
}

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD