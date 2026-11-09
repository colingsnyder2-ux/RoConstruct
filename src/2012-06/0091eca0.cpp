// roc 2012-06 0091eca0  unit: RBX::MotorJoint  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0091eca0
//
// 0091eca0  8b442404             mov eax, dword ptr [esp + 4]
// 0091eca4  83781810             cmp dword ptr [eax + 0x18], 0x10
// 0091eca8  8b4814               mov ecx, dword ptr [eax + 0x14]
// 0091ecab  7205                 jb 0x91ecb2
// 0091ecad  8b4004               mov eax, dword ptr [eax + 4]
// 0091ecb0  eb03                 jmp 0x91ecb5
// 0091ecb2  83c004               add eax, 4
// 0091ecb5  51                   push ecx
// 0091ecb6  50                   push eax
// 0091ecb7  8d44240c             lea eax, [esp + 0xc]
// 0091ecbb  50                   push eax
// 0091ecbc  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0091ecc4  e887ffffff           call 0x91ec50
// 0091ecc9  8b442410             mov eax, dword ptr [esp + 0x10]
// 0091eccd  83c40c               add esp, 0xc
// 0091ecd0  c3                   ret 
// copied from an identical function in another client (function ?sub_6d6e50@ns_ROCX000000@@YAHPBUStrData@1@@Z)

namespace ns_ROCX000000 {
struct StrData {
    int pad0;
    union {
        char buf[16];
        const char* ptr;
    } bx;
    unsigned int length;
    unsigned int capacity;
};

extern "C" void __cdecl sub_6d6e00(int* out, const char* data, unsigned int size);

int sub_6d6e50(const StrData* s) {
    unsigned int len = s->length;
    const char* data;
    if (s->capacity >= 16) {
        data = s->bx.ptr;
    } else {
        data = (const char*)&s->bx;
    }
    int result = 0;
    sub_6d6e00(&result, data, len);
    return result;
}
}