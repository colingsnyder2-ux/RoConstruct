// from server: 60% by Intel
// roc 2012-06 006f1ca0  unit: RBX::DataModel  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f1ca0
//
// 006f1ca0  56                   push esi
// 006f1ca1  8bf1                 mov esi, ecx
// 006f1ca3  8b4604               mov eax, dword ptr [esi + 4]
// 006f1ca6  83f807               cmp eax, 7
// 006f1ca9  750f                 jne 0x6f1cba
// 006f1cab  d94608               fld dword ptr [esi + 8]
// 006f1cae  8b442408             mov eax, dword ptr [esp + 8]
// 006f1cb2  d918                 fstp dword ptr [eax]
// 006f1cb4  b001                 mov al, 1
// 006f1cb6  5e                   pop esi
// 006f1cb7  c20400               ret 4
// 006f1cba  57                   push edi
// 006f1cbb  83f802               cmp eax, 2
// 006f1cbe  752f                 jne 0x6f1cef
// 006f1cc0  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006f1cc4  8b4e08               mov ecx, dword ptr [esi + 8]
// 006f1cc7  57                   push edi
// 006f1cc8  51                   push ecx
// 006f1cc9  e8a2240500           call 0x744170
// 006f1cce  83c408               add esp, 8
// 006f1cd1  84c0                 test al, al
// 006f1cd3  741a                 je 0x6f1cef
// 006f1cd5  8bce                 mov ecx, esi
// 006f1cd7  e884fcffff           call 0x6f1960
// 006f1cdc  d907                 fld dword ptr [edi]
// 006f1cde  5f                   pop edi
// 006f1cdf  d95e08               fstp dword ptr [esi + 8]
// 006f1ce2  c7460407000000       mov dword ptr [esi + 4], 7
// 006f1ce9  b001                 mov al, 1
// 006f1ceb  5e                   pop esi
// 006f1cec  c20400               ret 4
// 006f1cef  803db380e50000       cmp byte ptr [0xe580b3], 0
// 006f1cf6  743c                 je 0x6f1d34
// 006f1cf8  837e0409             cmp dword ptr [esi + 4], 9
// 006f1cfc  7536                 jne 0x6f1d34
// 006f1cfe  a19c80e500           mov eax, dword ptr [0xe5809c]
// 006f1d03  85c0                 test eax, eax
// 006f1d05  7418                 je 0x6f1d1f
// 006f1d07  6846010000           push 0x146
// 006f1d0c  68b8bbb900           push 0xb9bbb8
// 006f1d11  68a0bbb900           push 0xb9bba0
// 006f1d16  ffd0                 call eax
// 006f1d18  83c40c               add esp, 0xc
// 006f1d1b  84c0                 test al, al
// 006f1d1d  7515                 jne 0x6f1d34
// 006f1d1f  0fb615b380e500       movzx edx, byte ptr [0xe580b3]
// 006f1d26  6830bbb900           push 0xb9bb30
// 006f1d2b  52                   push edx
// 006f1d2c  e85f052800           call 0x972290
// 006f1d31  83c408               add esp, 8
// 006f1d34  5f                   pop edi
// 006f1d35  32c0                 xor al, al
// 006f1d37  5e                   pop esi
// 006f1d38  c20400               ret 4

struct DataModel {
    unsigned char valueType;
    float value;
    bool getValue(float* out);
    void setValue(float val);
};

extern "C" bool __cdecl sub_744170(float* a1, float a2);
extern "C" void __cdecl sub_972290(const char* a1, unsigned char a2);
extern "C" bool __cdecl sub_E5809C(int a1, const char* a2, const char* a3);

bool DataModel::getValue(float* out) {
    if (valueType == 7) {
        *out = value;
        return true;
    }
    if (valueType == 2) {
        float temp = value;
        if (sub_744170(out, temp)) {
            setValue(*out);
            return true;
        }
    }
    if (*(unsigned char*)0xE580B3) {
        if (valueType == 9) {
            bool (*func)(int, const char*, const char*) = (bool (*)(int, const char*, const char*))0xE5809C;
            if (func) {
                if (func(0x146, (const char*)0xB9BBA0, (const char*)0xB9BBB8)) {
                    return false;
                }
            }
            sub_972290((const char*)0xB9BB30, *(unsigned char*)0xE580B3);
        }
    }
    return false;
}

void DataModel::setValue(float val) {
    value = val;
    valueType = 7;
}
