// from server: 100% by colin
// from server: 91% by king_originala
// roc 2008-06 0055de10  unit: RBX::VInstance::?$NonFactoryProduct  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055de10
//
// 0055de10  6aff                 push -1
// 0055de12  68f9e87c00           push 0x7ce8f9
// 0055de17  64a100000000         mov eax, dword ptr fs:[0]
// 0055de1d  50                   push eax
// 0055de1e  64892500000000       mov dword ptr fs:[0], esp
// 0055de25  51                   push ecx
// 0055de26  55                   push ebp
// 0055de27  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0055de2b  c744240400000000     mov dword ptr [esp + 4], 0
// 0055de33  8b4500               mov eax, dword ptr [ebp]
// 0055de36  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 0055de39  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0055de41  85c9                 test ecx, ecx
// 0055de43  740b                 je 0x55de50
// 0055de45  8b11                 mov edx, dword ptr [ecx]
// 0055de47  8b4210               mov eax, dword ptr [edx + 0x10]
// 0055de4a  ffd0                 call eax
// 0055de4c  85c0                 test eax, eax
// 0055de4e  7510                 jne 0x55de60
// 0055de50  8b15ecf29700         mov edx, dword ptr [0x97f2ec]
// 0055de56  8b4210               mov eax, dword ptr [edx + 0x10]
// 0055de59  b9ecf29700           mov ecx, 0x97f2ec
// 0055de5e  ffd0                 call eax
// 0055de60  33c9                 xor ecx, ecx
// 0055de62  85c0                 test eax, eax
// 0055de64  0f95c1               setne cl
// 0055de67  85c9                 test ecx, ecx
// 0055de69  750a                 jne 0x55de75
// 0055de6b  6805400080           push 0x80004005
// 0055de70  e88b31eaff           call 0x401000
// 0055de75  8b10                 mov edx, dword ptr [eax]
// 0055de77  56                   push esi
// 0055de78  8bc8                 mov ecx, eax
// 0055de7a  8b420c               mov eax, dword ptr [edx + 0xc]
// 0055de7d  57                   push edi
// 0055de7e  ffd0                 call eax
// 0055de80  8b742420             mov esi, dword ptr [esp + 0x20]
// 0055de84  83c010               add eax, 0x10
// 0055de87  8906                 mov dword ptr [esi], eax
// 0055de89  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0055de8d  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0055de95  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0055de9d  85ff                 test edi, edi
// 0055de9f  7504                 jne 0x55dea5
// 0055dea1  33c0                 xor eax, eax
// 0055dea3  eb14                 jmp 0x55deb9
// 0055dea5  8bc7                 mov eax, edi
// 0055dea7  8d5001               lea edx, [eax + 1]
// 0055deaa  8d9b00000000         lea ebx, [ebx]
// 0055deb0  8a08                 mov cl, byte ptr [eax]
// 0055deb2  40                   inc eax
// 0055deb3  84c9                 test cl, cl
// 0055deb5  75f9                 jne 0x55deb0
// 0055deb7  2bc2                 sub eax, edx
// 0055deb9  8b4d00               mov ecx, dword ptr [ebp]
// 0055debc  8b51f4               mov edx, dword ptr [ecx - 0xc]
// 0055debf  50                   push eax
// 0055dec0  57                   push edi
// 0055dec1  52                   push edx
// 0055dec2  51                   push ecx
// 0055dec3  56                   push esi
// 0055dec4  e877f9ffff           call 0x55d840
// 0055dec9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0055decd  83c414               add esp, 0x14
// 0055ded0  5f                   pop edi
// 0055ded1  8bc6                 mov eax, esi
// 0055ded3  5e                   pop esi
// 0055ded4  5d                   pop ebp
// 0055ded5  64890d00000000       mov dword ptr fs:[0], ecx
// 0055dedc  83c410               add esp, 0x10
// 0055dedf  c3                   ret 

struct StringData;

struct StringManager {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual StringData* GetNilString();
    virtual StringManager* Clone();
};

struct StringData {
    StringManager* manager;
    int length;
    int capacity;
    long references;
};

struct ManagerStorage {
    void* vtable;
};

extern ManagerStorage defaultManager;

namespace ATL {
    __declspec(noreturn) void __stdcall AtlThrowImpl(long);
}

extern "C" unsigned int __cdecl strlen(const char*);

struct String {
    char* data;

    String(StringManager*);
    ~String();
    static unsigned int Length(const char*);
};

extern void __cdecl Concatenate(
    String*, const char*, int, const char*, unsigned int);

inline String::String(StringManager* manager)
{
    int valid = manager != 0;
    if (!valid)
        ATL::AtlThrowImpl((long)0x80004005);
    data = reinterpret_cast<char*>(manager->GetNilString()) + 16;
}

inline unsigned int String::Length(const char* text)
{
    if (!text)
        return 0;
    return strlen(text);
}

String __cdecl Combine(const String& first, const char* second)
{
    StringManager* manager =
        (reinterpret_cast<StringData*>(first.data) - 1)->manager;

    StringManager* selected = 0;
    if (manager)
        selected = manager->Clone();
    if (!selected)
        selected = reinterpret_cast<StringManager*>(&defaultManager)->Clone();

    String result(selected);
    unsigned int length = String::Length(second);
    int firstLength = (reinterpret_cast<StringData*>(first.data) - 1)->length;
    Concatenate(&result, first.data, firstLength, second, length);
    return result;
}
