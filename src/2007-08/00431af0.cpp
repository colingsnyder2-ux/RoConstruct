// from server: 100% by Intel
// from server: 99% by EspClaude
// roc 2007-08 00431af0  unit: CDataModelPropGrid  size: 608 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00431af0
//
// 00431af0  6aff                 push -1
// 00431af2  6810dc7300           push 0x73dc10
// 00431af7  64a100000000         mov eax, dword ptr fs:[0]
// 00431afd  50                   push eax
// 00431afe  83ec24               sub esp, 0x24
// 00431b01  53                   push ebx
// 00431b02  56                   push esi
// 00431b03  57                   push edi
// 00431b04  a188518b00           mov eax, dword ptr [0x8b5188]
// 00431b09  33c4                 xor eax, esp
// 00431b0b  50                   push eax
// 00431b0c  8d442434             lea eax, [esp + 0x34]
// 00431b10  64a300000000         mov dword ptr fs:[0], eax
// 00431b16  8b442444             mov eax, dword ptr [esp + 0x44]
// 00431b1a  8b700c               mov esi, dword ptr [eax + 0xc]
// 00431b1d  8bce                 mov ecx, esi
// 00431b1f  e87c9e0100           call 0x44b9a0
// 00431b24  8bce                 mov ecx, esi
// 00431b26  88442444             mov byte ptr [esp + 0x44], al
// 00431b2a  e8719e0100           call 0x44b9a0
// 00431b2f  8bce                 mov ecx, esi
// 00431b31  88642445             mov byte ptr [esp + 0x45], ah
// 00431b35  e8669e0100           call 0x44b9a0
// 00431b3a  668b542444           mov dx, word ptr [esp + 0x44]
// 00431b3f  51                   push ecx
// 00431b40  8bcc                 mov ecx, esp
// 00431b42  c1e810               shr eax, 0x10
// 00431b45  668911               mov word ptr [ecx], dx
// 00431b48  884102               mov byte ptr [ecx + 2], al
// 00431b4b  8d442448             lea eax, [esp + 0x48]
// 00431b4f  50                   push eax
// 00431b50  e85b501500           call 0x586bb0
// 00431b55  8b00                 mov eax, dword ptr [eax]
// 00431b57  83c408               add esp, 8
// 00431b5a  390538288a00         cmp dword ptr [0x8a2838], eax
// 00431b60  7410                 je 0x431b72
// 00431b62  50                   push eax
// 00431b63  b920288a00           mov ecx, 0x8a2820
// 00431b68  a338288a00           mov dword ptr [0x8a2838], eax
// 00431b6d  e82efbffff           call 0x4316a0
// 00431b72  8d4c2410             lea ecx, [esp + 0x10]
// 00431b76  51                   push ecx
// 00431b77  e894dbffff           call 0x42f710
// 00431b7c  8b742418             mov esi, dword ptr [esp + 0x18]
// 00431b80  83c404               add esp, 4
// 00431b83  833800               cmp dword ptr [eax], 0
// 00431b86  0f95c3               setne bl
// 00431b89  85f6                 test esi, esi
// 00431b8b  742a                 je 0x431bb7
// 00431b8d  8d5604               lea edx, [esi + 4]
// 00431b90  83c8ff               or eax, 0xffffffff
// 00431b93  f00fc102             lock xadd dword ptr [edx], eax
// 00431b97  751e                 jne 0x431bb7
// 00431b99  8b16                 mov edx, dword ptr [esi]
// 00431b9b  8b4204               mov eax, dword ptr [edx + 4]
// 00431b9e  8bce                 mov ecx, esi
// 00431ba0  ffd0                 call eax
// 00431ba2  8d4e08               lea ecx, [esi + 8]
// 00431ba5  83caff               or edx, 0xffffffff
// 00431ba8  f00fc111             lock xadd dword ptr [ecx], edx
// 00431bac  7509                 jne 0x431bb7
// 00431bae  8b06                 mov eax, dword ptr [esi]
// 00431bb0  8b5008               mov edx, dword ptr [eax + 8]
// 00431bb3  8bce                 mov ecx, esi
// 00431bb5  ffd2                 call edx
// 00431bb7  84db                 test bl, bl
// 00431bb9  0f8472010000         je 0x431d31
// 00431bbf  8d442410             lea eax, [esp + 0x10]
// 00431bc3  50                   push eax
// 00431bc4  e847dbffff           call 0x42f710
// 00431bc9  8b10                 mov edx, dword ptr [eax]
// 00431bcb  51                   push ecx
// 00431bcc  8bcc                 mov ecx, esp
// 00431bce  8911                 mov dword ptr [ecx], edx
// 00431bd0  8b4004               mov eax, dword ptr [eax + 4]
// 00431bd3  85c0                 test eax, eax
// 00431bd5  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00431bdd  8964244c             mov dword ptr [esp + 0x4c], esp
// 00431be1  894104               mov dword ptr [ecx + 4], eax
// 00431be4  740c                 je 0x431bf2
// 00431be6  83c004               add eax, 4
// 00431be9  b901000000           mov ecx, 1
// 00431bee  f00fc108             lock xadd dword ptr [eax], ecx
// 00431bf2  8d4c2430             lea ecx, [esp + 0x30]
// 00431bf6  e855b9fdff           call 0x40d550
// 00431bfb  8b742414             mov esi, dword ptr [esp + 0x14]
// 00431bff  85f6                 test esi, esi
// 00431c01  b302                 mov bl, 2
// 00431c03  885c243c             mov byte ptr [esp + 0x3c], bl
// 00431c07  742a                 je 0x431c33
// 00431c09  8d5604               lea edx, [esi + 4]
// 00431c0c  83c8ff               or eax, 0xffffffff
// 00431c0f  f00fc102             lock xadd dword ptr [edx], eax
// 00431c13  751e                 jne 0x431c33
// 00431c15  8b16                 mov edx, dword ptr [esi]
// 00431c17  8b4204               mov eax, dword ptr [edx + 4]
// 00431c1a  8bce                 mov ecx, esi
// 00431c1c  ffd0                 call eax
// 00431c1e  8d4e08               lea ecx, [esi + 8]
// 00431c21  83caff               or edx, 0xffffffff
// 00431c24  f00fc111             lock xadd dword ptr [ecx], edx
// 00431c28  7509                 jne 0x431c33
// 00431c2a  8b06                 mov eax, dword ptr [esi]
// 00431c2c  8b5008               mov edx, dword ptr [eax + 8]
// 00431c2f  8bce                 mov ecx, esi
// 00431c31  ffd2                 call edx
// 00431c33  83ec1c               sub esp, 0x1c
// 00431c36  8bcc                 mov ecx, esp
// 00431c38  89642460             mov dword ptr [esp + 0x60], esp
// 00431c3c  6884b47800           push 0x78b484
// 00431c41  ff1598e67700         call dword ptr [0x77e698]
// 00431c47  8d442434             lea eax, [esp + 0x34]
// 00431c4b  50                   push eax
// 00431c4c  e8bfdaffff           call 0x42f710
// 00431c51  83c404               add esp, 4
// 00431c54  8b00                 mov eax, dword ptr [eax]
// 00431c56  8d884c010000         lea ecx, [eax + 0x14c]
// 00431c5c  c644245803           mov byte ptr [esp + 0x58], 3
// 00431c61  e8ea2e1300           call 0x564b50
// 00431c66  8bf8                 mov edi, eax
// 00431c68  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00431c6c  85c0                 test eax, eax
// 00431c6e  885c243c             mov byte ptr [esp + 0x3c], bl
// 00431c72  742c                 je 0x431ca0
// 00431c74  8bf0                 mov esi, eax
// 00431c76  83c004               add eax, 4
// 00431c79  83c9ff               or ecx, 0xffffffff
// 00431c7c  f00fc108             lock xadd dword ptr [eax], ecx
// 00431c80  751e                 jne 0x431ca0
// 00431c82  8b16                 mov edx, dword ptr [esi]
// 00431c84  8b4204               mov eax, dword ptr [edx + 4]
// 00431c87  8bce                 mov ecx, esi
// 00431c89  ffd0                 call eax
// 00431c8b  8d4e08               lea ecx, [esi + 8]
// 00431c8e  83caff               or edx, 0xffffffff
// 00431c91  f00fc111             lock xadd dword ptr [ecx], edx
// 00431c95  7509                 jne 0x431ca0
// 00431c97  8b06                 mov eax, dword ptr [esi]
// 00431c99  8b5008               mov edx, dword ptr [eax + 8]
// 00431c9c  8bce                 mov ecx, esi
// 00431c9e  ffd2                 call edx
// 00431ca0  8d442420             lea eax, [esp + 0x20]
// 00431ca4  50                   push eax
// 00431ca5  e866daffff           call 0x42f710
// 00431caa  83c404               add esp, 4
// 00431cad  8b00                 mov eax, dword ptr [eax]
// 00431caf  85c0                 test eax, eax
// 00431cb1  c644243c04           mov byte ptr [esp + 0x3c], 4
// 00431cb6  7407                 je 0x431cbf
// 00431cb8  0560010000           add eax, 0x160
// 00431cbd  eb02                 jmp 0x431cc1
// 00431cbf  33c0                 xor eax, eax
// 00431cc1  8b17                 mov edx, dword ptr [edi]
// 00431cc3  50                   push eax
// 00431cc4  8b4210               mov eax, dword ptr [edx + 0x10]
// 00431cc7  8bcf                 mov ecx, edi
// 00431cc9  ffd0                 call eax
// 00431ccb  8b742424             mov esi, dword ptr [esp + 0x24]
// 00431ccf  85f6                 test esi, esi
// 00431cd1  885c243c             mov byte ptr [esp + 0x3c], bl
// 00431cd5  742a                 je 0x431d01
// 00431cd7  8d4e04               lea ecx, [esi + 4]
// 00431cda  83caff               or edx, 0xffffffff
// 00431cdd  f00fc111             lock xadd dword ptr [ecx], edx
// 00431ce1  751e                 jne 0x431d01
// 00431ce3  8b06                 mov eax, dword ptr [esi]
// 00431ce5  8b5004               mov edx, dword ptr [eax + 4]
// 00431ce8  8bce                 mov ecx, esi
// 00431cea  ffd2                 call edx
// 00431cec  8d4608               lea eax, [esi + 8]
// 00431cef  83c9ff               or ecx, 0xffffffff
// 00431cf2  f00fc108             lock xadd dword ptr [eax], ecx
// 00431cf6  7509                 jne 0x431d01
// 00431cf8  8b16                 mov edx, dword ptr [esi]
// 00431cfa  8b4208               mov eax, dword ptr [edx + 8]
// 00431cfd  8bce                 mov ecx, esi
// 00431cff  ffd0                 call eax
// 00431d01  8d4c2428             lea ecx, [esp + 0x28]
// 00431d05  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 00431d0d  e88e781200           call 0x5595a0
// 00431d12  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00431d16  c70101000000         mov dword ptr [ecx], 1
// 00431d1c  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00431d20  64890d00000000       mov dword ptr fs:[0], ecx
// 00431d27  59                   pop ecx
// 00431d28  5f                   pop edi
// 00431d29  5e                   pop esi
// 00431d2a  5b                   pop ebx
// 00431d2b  83c430               add esp, 0x30
// 00431d2e  c20800               ret 8
// 00431d31  8b542448             mov edx, dword ptr [esp + 0x48]
// 00431d35  c70201000000         mov dword ptr [edx], 1
// 00431d3b  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00431d3f  64890d00000000       mov dword ptr fs:[0], ecx
// 00431d46  59                   pop ecx
// 00431d47  5f                   pop edi
// 00431d48  5e                   pop esi
// 00431d49  5b                   pop ebx
// 00431d4a  83c430               add esp, 0x30
// 00431d4d  c20800               ret 8

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    typedef T* shared_ptr::*unspecified_bool_type;
    T* px;
    shared_count pn;
    template<class Y> shared_ptr(shared_ptr<Y> const& r) : px(r.px), pn(r.pn) {}
    T* operator->() const { return px; }
    T* get() const { return px; }
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

class String {
public:
    __declspec(dllimport) String(const char* s);
    __declspec(dllimport) String(const String& s);
    __declspec(dllimport) ~String();
    char storage[0x1c];
};

struct NMHDR { void* hwndFrom; unsigned int idFrom; unsigned int code; };
typedef long LRESULT;

namespace G3D {
class Color3uint8 {
public:
    unsigned char r, g, b;
};
}

class ColorPicker {
public:
    unsigned long GetColor() const;
};

struct NMCOLORPICKER {
    NMHDR hdr;
    ColorPicker* picker;
};

namespace RBX {
class BrickColor {
public:
    int number;
    BrickColor() {}
    bool operator!=(const BrickColor& other) const { return number != other.number; }
    static BrickColor closest(G3D::Color3uint8 color);
};

class ColorSetting {
public:
    char pad[0x20];
    BrickColor color;
    void raiseChanged(BrickColor value);
    void setColor(BrickColor value)
    {
        if (color != value)
        {
            color = value;
            raiseChanged(value);
        }
    }
};
extern ColorSetting fillColor;

class IDataState {
public:
    virtual void a();
};

class Verb {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void doIt(IDataState* dataState);
};

class VerbContainer {
public:
    virtual ~VerbContainer();
    char vpad[0x10];
    Verb* getVerb(String name);
};

class DataModelBase {
public:
    virtual ~DataModelBase();
    char pad[0x148];
};

class DataModel : public DataModelBase, public VerbContainer, public IDataState {
public:
    class scoped_lock {
    public:
        scoped_lock(shared_ptr<const DataModel> dm);
        ~scoped_lock();
        int a, b, c;
    };
};
}

class CDataModelPropGrid {
public:
    static shared_ptr<RBX::DataModel> getDataModel() throw();
    void OnFillColorChanged(NMHDR* pNMHDR, LRESULT* pResult);
};

void CDataModelPropGrid::OnFillColorChanged(NMHDR* pNMHDR, LRESULT* pResult)
{
    ColorPicker* picker = reinterpret_cast<NMCOLORPICKER*>(pNMHDR)->picker;
    G3D::Color3uint8 color;
    color.r = (unsigned char)(picker->GetColor());
    color.g = (unsigned char)(((unsigned short)picker->GetColor()) >> 8);
    color.b = (unsigned char)(picker->GetColor() >> 16);
    RBX::fillColor.setColor(RBX::BrickColor::closest(color));
    if (getDataModel())
    {
        RBX::DataModel::scoped_lock lock(getDataModel());
        RBX::Verb* verb = getDataModel()->getVerb("FillTool");
        verb->doIt(getDataModel().get());
    }
    *pResult = 1;
}
