// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 44% by colin
// roc 2007-08 005b8be0  unit: RBX::Controller::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 263 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b8be0
//
// 005b8be0  64a100000000         mov eax, dword ptr fs:[0]
// 005b8be6  6aff                 push -1
// 005b8be8  6879be7500           push 0x75be79
// 005b8bed  50                   push eax
// 005b8bee  64892500000000       mov dword ptr fs:[0], esp
// 005b8bf5  83ec24               sub esp, 0x24
// 005b8bf8  56                   push esi
// 005b8bf9  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 005b8bfd  57                   push edi
// 005b8bfe  8bf9                 mov edi, ecx
// 005b8c00  8bce                 mov ecx, esi
// 005b8c02  e8994cfaff           call 0x55d8a0
// 005b8c07  84c0                 test al, al
// 005b8c09  0f85c5000000         jne 0x5b8cd4
// 005b8c0f  83c60c               add esi, 0xc
// 005b8c12  8bce                 mov ecx, esi
// 005b8c14  e8e746faff           call 0x55d300
// 005b8c19  84c0                 test al, al
// 005b8c1b  0f8487000000         je 0x5b8ca8
// 005b8c21  8d4c2410             lea ecx, [esp + 0x10]
// 005b8c25  ff15a4e67700         call dword ptr [0x77e6a4]
// 005b8c2b  8d442410             lea eax, [esp + 0x10]
// 005b8c2f  50                   push eax
// 005b8c30  8bce                 mov ecx, esi
// 005b8c32  c744243800000000     mov dword ptr [esp + 0x38], 0
// 005b8c3a  e8d146faff           call 0x55d310
// 005b8c3f  84c0                 test al, al
// 005b8c41  7453                 je 0x5b8c96
// 005b8c43  8d4c2440             lea ecx, [esp + 0x40]
// 005b8c47  51                   push ecx
// 005b8c48  8d542414             lea edx, [esp + 0x14]
// 005b8c4c  52                   push edx
// 005b8c4d  e88ef2ffff           call 0x5b7ee0
// 005b8c52  8bc8                 mov ecx, eax
// 005b8c54  e847360200           call 0x5dc2a0
// 005b8c59  84c0                 test al, al
// 005b8c5b  7439                 je 0x5b8c96
// 005b8c5d  8b4f1c               mov ecx, dword ptr [edi + 0x1c]
// 005b8c60  8b01                 mov eax, dword ptr [ecx]
// 005b8c62  8b4008               mov eax, dword ptr [eax + 8]
// 005b8c65  8d542440             lea edx, [esp + 0x40]
// 005b8c69  52                   push edx
// 005b8c6a  8b542440             mov edx, dword ptr [esp + 0x40]
// 005b8c6e  52                   push edx
// 005b8c6f  ffd0                 call eax
// 005b8c71  8d4c2410             lea ecx, [esp + 0x10]
// 005b8c75  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 005b8c7d  ff15ace67700         call dword ptr [0x77e6ac]
// 005b8c83  5f                   pop edi
// 005b8c84  5e                   pop esi
// 005b8c85  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005b8c89  64890d00000000       mov dword ptr fs:[0], ecx
// 005b8c90  83c430               add esp, 0x30
// 005b8c93  c20c00               ret 0xc
// 005b8c96  8d4c2410             lea ecx, [esp + 0x10]
// 005b8c9a  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 005b8ca2  ff15ace67700         call dword ptr [0x77e6ac]
// 005b8ca8  8d4c2408             lea ecx, [esp + 8]
// 005b8cac  51                   push ecx
// 005b8cad  8bce                 mov ecx, esi
// 005b8caf  e83c49faff           call 0x55d5f0
// 005b8cb4  84c0                 test al, al
// 005b8cb6  741c                 je 0x5b8cd4
// 005b8cb8  8b542408             mov edx, dword ptr [esp + 8]
// 005b8cbc  8b4f1c               mov ecx, dword ptr [edi + 0x1c]
// 005b8cbf  8954240c             mov dword ptr [esp + 0xc], edx
// 005b8cc3  8b01                 mov eax, dword ptr [ecx]
// 005b8cc5  8b4008               mov eax, dword ptr [eax + 8]
// 005b8cc8  8d54240c             lea edx, [esp + 0xc]
// 005b8ccc  52                   push edx
// 005b8ccd  8b542440             mov edx, dword ptr [esp + 0x40]
// 005b8cd1  52                   push edx
// 005b8cd2  ffd0                 call eax
// 005b8cd4  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005b8cd8  5f                   pop edi
// 005b8cd9  5e                   pop esi
// 005b8cda  64890d00000000       mov dword ptr fs:[0], ecx
// 005b8ce1  83c430               add esp, 0x30
// 005b8ce4  c20c00               ret 0xc

#include <string>

class DescribedBase;
class IReferenceBinder;

class XmlValue {
public:
    bool isString() const;
    bool get(std::string& value) const;
    bool get(int& value) const;
};

class XmlElement {
public:
    bool isXsiNil() const;
    char pad[0xc];
    XmlValue value;
};

template<class T> class EnumDesc {
public:
    static EnumDesc& singleton();
    bool convertToValue(const std::string& text, T& value) const;
};

template<class T> class GetSet {
public:
    virtual T get(const DescribedBase* instance) const = 0;
    virtual bool isReadOnly() const = 0;
    virtual void set(DescribedBase* instance, const T& value) const = 0;
};

enum InputType { NO_INPUT = 0 };

class SurfaceEnumPropDescriptor {
public:
    virtual ~SurfaceEnumPropDescriptor();
    char pad[0x18];
    GetSet<InputType>* getset;
    void readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const;
};

void SurfaceEnumPropDescriptor::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
    if (element->isXsiNil())
        return;
    const XmlValue& v = element->value;
    if (v.isString()) {
        std::string s;
        if (v.get(s)) {
            InputType value;
            if (EnumDesc<InputType>::singleton().convertToValue(s, value)) {
                getset->set(instance, value);
                return;
            }
        }
    }
    int i;
    if (v.get(i)) {
        InputType value = (InputType)i;
        getset->set(instance, value);
    }
}
