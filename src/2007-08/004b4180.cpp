// from server: 100% by EspClaude
// roc 2007-08 004b4180  unit: RBX::Reflection::SignalSource  size: 448 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b4180
// 004b4180  807c240800           cmp byte ptr [esp + 8], 0
// 004b4185  53                   push ebx
// 004b4186  55                   push ebp
// 004b4187  56                   push esi
// 004b4188  57                   push edi
// 004b4189  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004b418d  8be9                 mov ebp, ecx
// 004b418f  7418                 je 0x4b41a9
// 004b4191  6a01                 push 1
// 004b4193  6a04                 push 4
// 004b4195  8d442420             lea eax, [esp + 0x20]
// 004b4199  50                   push eax
// 004b419a  8bcf                 mov ecx, edi
// 004b419c  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004b41a4  e8f7b7feff           call 0x49f9a0
// 004b41a9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004b41ad  8b1e                 mov ebx, dword ptr [esi]
// 004b41af  e84c980b00           call 0x56da00
// 004b41b4  394314               cmp dword ptr [ebx + 0x14], eax
// 004b41b7  7520                 jne 0x4b41d9
// 004b41b9  8b06                 mov eax, dword ptr [esi]
// 004b41bb  57                   push edi
// 004b41bc  56                   push esi
// 004b41bd  50                   push eax
// 004b41be  8bcd                 mov ecx, ebp
// 004b41c0  e8ebfbffff           call 0x4b3db0
// 004b41c5  8bc8                 mov ecx, eax
// 004b41c7  81c1100e0000         add ecx, 0xe10
// 004b41cd  e8cedffeff           call 0x4a21a0
// 004b41d2  5f                   pop edi
// 004b41d3  5e                   pop esi
// 004b41d4  5d                   pop ebp
// 004b41d5  5b                   pop ebx
// 004b41d6  c20c00               ret 0xc
// 004b41d9  8b1e                 mov ebx, dword ptr [esi]
// 004b41db  e860960b00           call 0x56d840
// 004b41e0  394314               cmp dword ptr [ebx + 0x14], eax
// 004b41e3  7521                 jne 0x4b4206
// 004b41e5  8d4c2418             lea ecx, [esp + 0x18]
// 004b41e9  51                   push ecx
// 004b41ea  57                   push edi
// 004b41eb  e860c0feff           call 0x4a0250
// 004b41f0  83c408               add esp, 8
// 004b41f3  8d542418             lea edx, [esp + 0x18]
// 004b41f7  52                   push edx
// 004b41f8  8bce                 mov ecx, esi
// 004b41fa  e8413effff           call 0x4a8040
// 004b41ff  5f                   pop edi
// 004b4200  5e                   pop esi
// 004b4201  5d                   pop ebp
// 004b4202  5b                   pop ebx
// 004b4203  c20c00               ret 0xc
// 004b4206  8b1e                 mov ebx, dword ptr [esi]
// 004b4208  e8c3950b00           call 0x56d7d0
// 004b420d  394314               cmp dword ptr [ebx + 0x14], eax
// 004b4210  7521                 jne 0x4b4233
// 004b4212  8d442418             lea eax, [esp + 0x18]
// 004b4216  50                   push eax
// 004b4217  57                   push edi
// 004b4218  e823c4feff           call 0x4a0640
// 004b421d  83c408               add esp, 8
// 004b4220  8d4c2418             lea ecx, [esp + 0x18]
// 004b4224  51                   push ecx
// 004b4225  8bce                 mov ecx, esi
// 004b4227  e8743effff           call 0x4a80a0
// 004b422c  5f                   pop edi
// 004b422d  5e                   pop esi
// 004b422e  5d                   pop ebp
// 004b422f  5b                   pop ebx
// 004b4230  c20c00               ret 0xc
// 004b4233  8b1e                 mov ebx, dword ptr [esi]
// 004b4235  e876960b00           call 0x56d8b0
// 004b423a  394314               cmp dword ptr [ebx + 0x14], eax
// 004b423d  7511                 jne 0x4b4250
// 004b423f  57                   push edi
// 004b4240  56                   push esi
// 004b4241  e88a4affff           call 0x4a8cd0
// 004b4246  83c408               add esp, 8
// 004b4249  5f                   pop edi
// 004b424a  5e                   pop esi
// 004b424b  5d                   pop ebp
// 004b424c  5b                   pop ebx
// 004b424d  c20c00               ret 0xc
// 004b4250  8b1e                 mov ebx, dword ptr [esi]
// 004b4252  e8699a0b00           call 0x56dcc0
// 004b4257  394314               cmp dword ptr [ebx + 0x14], eax
// 004b425a  7511                 jne 0x4b426d
// 004b425c  57                   push edi
// 004b425d  56                   push esi
// 004b425e  e81dd6feff           call 0x4a1880
// 004b4263  83c408               add esp, 8
// 004b4266  5f                   pop edi
// 004b4267  5e                   pop esi
// 004b4268  5d                   pop ebp
// 004b4269  5b                   pop ebx
// 004b426a  c20c00               ret 0xc
// 004b426d  8b1e                 mov ebx, dword ptr [esi]
// 004b426f  e8dc980b00           call 0x56db50
// 004b4274  394314               cmp dword ptr [ebx + 0x14], eax
// 004b4277  7511                 jne 0x4b428a
// 004b4279  57                   push edi
// 004b427a  56                   push esi
// 004b427b  e8804affff           call 0x4a8d00
// 004b4280  83c408               add esp, 8
// 004b4283  5f                   pop edi
// 004b4284  5e                   pop esi
// 004b4285  5d                   pop ebp
// 004b4286  5b                   pop ebx
// 004b4287  c20c00               ret 0xc
// 004b428a  8b1e                 mov ebx, dword ptr [esi]
// 004b428c  e8df970b00           call 0x56da70
// 004b4291  394314               cmp dword ptr [ebx + 0x14], eax
// 004b4294  7511                 jne 0x4b42a7
// 004b4296  57                   push edi
// 004b4297  56                   push esi
// 004b4298  e8934affff           call 0x4a8d30
// 004b429d  83c408               add esp, 8
// 004b42a0  5f                   pop edi
// 004b42a1  5e                   pop esi
// 004b42a2  5d                   pop ebp
// 004b42a3  5b                   pop ebx
// 004b42a4  c20c00               ret 0xc
// 004b42a7  8b1e                 mov ebx, dword ptr [esi]
// 004b42a9  e802000c00           call 0x5742b0
// 004b42ae  394314               cmp dword ptr [ebx + 0x14], eax
// 004b42b1  7511                 jne 0x4b42c4
// 004b42b3  57                   push edi
// 004b42b4  56                   push esi
// 004b42b5  e8b64affff           call 0x4a8d70
// 004b42ba  83c408               add esp, 8
// 004b42bd  5f                   pop edi
// 004b42be  5e                   pop esi
// 004b42bf  5d                   pop ebp
// 004b42c0  5b                   pop ebx
// 004b42c1  c20c00               ret 0xc
// 004b42c4  8b06                 mov eax, dword ptr [esi]
// 004b42c6  6a00                 push 0
// 004b42c8  68dc7c8800           push 0x887cdc
// 004b42cd  6874718800           push 0x887174
// 004b42d2  6a00                 push 0
// 004b42d4  50                   push eax
// 004b42d5  e85cca1700           call 0x630d36
// 004b42da  83c414               add esp, 0x14
// 004b42dd  85c0                 test eax, eax
// 004b42df  7411                 je 0x4b42f2
// 004b42e1  57                   push edi
// 004b42e2  56                   push esi
// 004b42e3  e808bffeff           call 0x4a01f0
// 004b42e8  83c408               add esp, 8
// 004b42eb  5f                   pop edi
// 004b42ec  5e                   pop esi
// 004b42ed  5d                   pop ebp
// 004b42ee  5b                   pop ebx
// 004b42ef  c20c00               ret 0xc
// 004b42f2  8b06                 mov eax, dword ptr [esi]
// 004b42f4  6a00                 push 0
// 004b42f6  68a87c8800           push 0x887ca8
// 004b42fb  6874718800           push 0x887174
// 004b4300  6a00                 push 0
// 004b4302  50                   push eax
// 004b4303  e82eca1700           call 0x630d36
// 004b4308  83c414               add esp, 0x14
// 004b430b  85c0                 test eax, eax
// 004b430d  7414                 je 0x4b4323
// 004b430f  57                   push edi
// 004b4310  56                   push esi
// 004b4311  8d8dec000000         lea ecx, [ebp + 0xec]
// 004b4317  e8d4effeff           call 0x4a32f0
// 004b431c  5f                   pop edi
// 004b431d  5e                   pop esi
// 004b431e  5d                   pop ebp
// 004b431f  5b                   pop ebx
// 004b4320  c20c00               ret 0xc
// 004b4323  8b1e                 mov ebx, dword ptr [esi]
// 004b4325  e866960b00           call 0x56d990
// 004b432a  394314               cmp dword ptr [ebx + 0x14], eax
// 004b432d  750a                 jne 0x4b4339
// 004b432f  57                   push edi
// 004b4330  56                   push esi
// 004b4331  e81acafeff           call 0x4a0d50
// 004b4336  83c408               add esp, 8
// 004b4339  5f                   pop edi
// 004b433a  5e                   pop esi
// 004b433b  5d                   pop ebp
// 004b433c  5b                   pop ebx
// 004b433d  c20c00               ret 0xc
namespace RakNet {
class BitStream {
public:
    bool ReadBits(unsigned char* output, int numberOfBitsToRead, bool alignBitsToRight);
};
}

namespace RBX {
namespace Reflection {

class Type {
public:
    template<class T> static const Type& singleton();
};

class PropertyDescriptor {
public:
    virtual ~PropertyDescriptor();
    int pad[4];          // type reference sits at +0x14 in the target
    const Type& type;
};
template<class T> __forceinline bool isType(const PropertyDescriptor& d)
{
    return &d.type == &Type::singleton<T>();
}
class EnumPropertyDescriptor : public PropertyDescriptor {};
class RefPropertyDescriptor : public PropertyDescriptor {};

class Property {
public:
    const PropertyDescriptor* descriptor;
    const PropertyDescriptor& getDescriptor() const { return *descriptor; }
    void setValue(const int& value);
    void setValue(const float& value);
};

struct T0; struct T1; struct T2; struct T3; struct T4; struct T5; struct T6; struct T7; struct T8;

void readValue(RakNet::BitStream& stream, int& value);
void readValue(RakNet::BitStream& stream, float& value);
void receiveT3(Property& property, RakNet::BitStream& stream);
void receiveT4(Property& property, RakNet::BitStream& stream);
void receiveT5(Property& property, RakNet::BitStream& stream);
void receiveT6(Property& property, RakNet::BitStream& stream);
void receiveT7(Property& property, RakNet::BitStream& stream);
void receiveEnum(Property& property, RakNet::BitStream& stream);
void receiveT8(Property& property, RakNet::BitStream& stream);

class Receiver {
public:
    void receive(Property& property, RakNet::BitStream& stream);
};

class Container {
public:
    int pad[0xe10 / 4];
    Receiver receiver;
};

class SignalSource {
public:
    int pad[0xec / 4];
    Receiver refReceiver;

    Container* find(const PropertyDescriptor* descriptor);
    void receiveProperty(RakNet::BitStream& stream, bool skipVersion, Property& property);
};

void SignalSource::receiveProperty(RakNet::BitStream& stream, bool skipVersion, Property& property)
{
    if (skipVersion) {
        int version = 0;
        stream.ReadBits((unsigned char*)&version, 4, true);
    }

    if (isType<T0>(property.getDescriptor())) {
        find(&property.getDescriptor())->receiver.receive(property, stream);
        return;
    }
    if (isType<T1>(property.getDescriptor())) {
        int value;
        readValue(stream, value);
        property.setValue(value);
        return;
    }
    if (isType<T2>(property.getDescriptor())) {
        float value;
        readValue(stream, value);
        property.setValue(value);
        return;
    }
    if (isType<T3>(property.getDescriptor())) {
        receiveT3(property, stream);
        return;
    }
    if (isType<T4>(property.getDescriptor())) {
        receiveT4(property, stream);
        return;
    }
    if (isType<T5>(property.getDescriptor())) {
        receiveT5(property, stream);
        return;
    }
    if (isType<T6>(property.getDescriptor())) {
        receiveT6(property, stream);
        return;
    }
    if (isType<T7>(property.getDescriptor())) {
        receiveT7(property, stream);
        return;
    }
    if (dynamic_cast<const EnumPropertyDescriptor*>(&property.getDescriptor())) {
        receiveEnum(property, stream);
        return;
    }
    if (dynamic_cast<const RefPropertyDescriptor*>(&property.getDescriptor())) {
        refReceiver.receive(property, stream);
        return;
    }
    if (isType<T8>(property.getDescriptor())) {
        receiveT8(property, stream);
    }
}

}
}
