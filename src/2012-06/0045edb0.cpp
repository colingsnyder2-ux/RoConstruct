// from server: 100% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 0045e910  unit: FacesComponentItem  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0045e910
//
// 0045e910  53                   push ebx
// 0045e911  56                   push esi
// 0045e912  8bf1                 mov esi, ecx
// 0045e914  8b8628010000         mov eax, dword ptr [esi + 0x128]
// 0045e91a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045e91e  50                   push eax
// 0045e91f  e87c792e00           call 0x7462a0
// 0045e924  8b8e28010000         mov ecx, dword ptr [esi + 0x128]
// 0045e92a  51                   push ecx
// 0045e92b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0045e92f  8ad8                 mov bl, al
// 0045e931  e86a792e00           call 0x7462a0
// 0045e936  33d2                 xor edx, edx
// 0045e938  3ad8                 cmp bl, al
// 0045e93a  0f94c2               sete dl
// 0045e93d  5e                   pop esi
// 0045e93e  8ac2                 mov al, dl
// 0045e940  5b                   pop ebx
// 0045e941  c20800               ret 8

struct FaceComparable {
    bool equals(void* p);
};

struct FacesComponentItem {
    char pad[0x128];
    void* field_128;
    bool compare(void* a, void* b);
};

bool FacesComponentItem::compare(void* a, void* b) {
    FaceComparable* lhs = (FaceComparable*)a;
    FaceComparable* rhs = (FaceComparable*)b;
    bool r1 = lhs->equals(field_128);
    bool r2 = rhs->equals(field_128);
    return r1 == r2;
}
