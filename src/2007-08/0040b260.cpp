// from server: 100% by colin
// roc 2007-08 0040b260  unit: VCApp::?$CProxy_IAppEvents  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040b260
//
// 0040b260  8b442404             mov eax, dword ptr [esp + 4]
// 0040b264  85c0                 test eax, eax
// 0040b266  7418                 je 0x40b280
// 0040b268  8b542408             mov edx, dword ptr [esp + 8]
// 0040b26c  8b48f8               mov ecx, dword ptr [eax - 8]
// 0040b26f  83c0f8               add eax, -8
// 0040b272  52                   push edx
// 0040b273  68e44b7800           push 0x784be4
// 0040b278  50                   push eax
// 0040b279  8b01                 mov eax, dword ptr [ecx]
// 0040b27b  ffd0                 call eax
// 0040b27d  c20800               ret 8
// 0040b280  8b542408             mov edx, dword ptr [esp + 8]
// 0040b284  33c0                 xor eax, eax
// 0040b286  8b08                 mov ecx, dword ptr [eax]
// 0040b288  52                   push edx
// 0040b289  68e44b7800           push 0x784be4
// 0040b28e  50                   push eax
// 0040b28f  8b01                 mov eax, dword ptr [ecx]
// 0040b291  ffd0                 call eax
// 0040b293  c20800               ret 8
// copied from an identical function in another client (function ?queryInterface@@YGJPAXPAPAX@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Object;

struct Table {
    long (__stdcall *query)(Object *, const void *, void **);
};

struct Object {
    Table *table;
};

extern const unsigned char interfaceId;

long __stdcall queryInterface(void *pointer, void **result)
{
    Object *object = pointer
        ? reinterpret_cast<Object *>(static_cast<char *>(pointer) - 8)
        : 0;
    return object->table->query(object, &interfaceId, result);
}