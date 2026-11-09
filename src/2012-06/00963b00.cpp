// roc 2012-06 00963b00  unit: RBX::EdgeStage  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00963b00
//
// 00963b00  53                   push ebx
// 00963b01  56                   push esi
// 00963b02  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00963b06  8b06                 mov eax, dword ptr [esi]
// 00963b08  8b5010               mov edx, dword ptr [eax + 0x10]
// 00963b0b  57                   push edi
// 00963b0c  6a00                 push 0
// 00963b0e  8bce                 mov ecx, esi
// 00963b10  ffd2                 call edx
// 00963b12  8bf8                 mov edi, eax
// 00963b14  8b06                 mov eax, dword ptr [esi]
// 00963b16  8b5010               mov edx, dword ptr [eax + 0x10]
// 00963b19  6a01                 push 1
// 00963b1b  8bce                 mov ecx, esi
// 00963b1d  ffd2                 call edx
// 00963b1f  8bd8                 mov ebx, eax
// 00963b21  85ff                 test edi, edi
// 00963b23  7504                 jne 0x963b29
// 00963b25  33f6                 xor esi, esi
// 00963b27  eb18                 jmp 0x963b41
// 00963b29  8b4704               mov eax, dword ptr [edi + 4]
// 00963b2c  85c0                 test eax, eax
// 00963b2e  7505                 jne 0x963b35
// 00963b30  8d7001               lea esi, [eax + 1]
// 00963b33  eb0c                 jmp 0x963b41
// 00963b35  50                   push eax
// 00963b36  e865feffff           call 0x9639a0
// 00963b3b  8bf0                 mov esi, eax
// 00963b3d  83c404               add esp, 4
// 00963b40  46                   inc esi
// 00963b41  85db                 test ebx, ebx
// 00963b43  7504                 jne 0x963b49
// 00963b45  33c0                 xor eax, eax
// 00963b47  eb18                 jmp 0x963b61
// 00963b49  8b4304               mov eax, dword ptr [ebx + 4]
// 00963b4c  85c0                 test eax, eax
// 00963b4e  7507                 jne 0x963b57
// 00963b50  b801000000           mov eax, 1
// 00963b55  eb0a                 jmp 0x963b61
// 00963b57  50                   push eax
// 00963b58  e843feffff           call 0x9639a0
// 00963b5d  83c404               add esp, 4
// 00963b60  40                   inc eax
// 00963b61  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00963b65  8b542414             mov edx, dword ptr [esp + 0x14]
// 00963b69  51                   push ecx
// 00963b6a  52                   push edx
// 00963b6b  50                   push eax
// 00963b6c  56                   push esi
// 00963b6d  53                   push ebx
// 00963b6e  57                   push edi
// 00963b6f  e89cfeffff           call 0x963a10
// 00963b74  83c418               add esp, 0x18
// 00963b77  5f                   pop edi
// 00963b78  5e                   pop esi
// 00963b79  5b                   pop ebx
// 00963b7a  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000002@ns_ROCX000002@@YAHPAUSpatialFilter@1@HHH@Z)

namespace ns_ROCX000002 {
// from server: 100% by atomic.potato
int fn_ROCX000002(void *p);

struct SpatialFilter {
    virtual void *getFilter(int index);
    virtual void *getFilter2(int index);
    virtual void *getFilter3(int index);
    virtual void *getFilter4(int index);
    virtual void *getFilter5(int index);
};

int fn_ROCX000002(void *a, void *b, int c, int d, int e, int f);

int fn_ROCX000002(SpatialFilter *self, int a, int b, int c)
{
    void *p0 = self->getFilter5(0);
    void *p1 = self->getFilter5(1);

    int n0;
    if (!p0)
        n0 = 0;
    else if (!*(void **)((char *)p0 + 4))
        n0 = 1;
    else
        n0 = fn_ROCX000002(*(void **)((char *)p0 + 4)) + 1;

    int n1;
    if (!p1)
        n1 = 0;
    else if (!*(void **)((char *)p1 + 4))
        n1 = 1;
    else
        n1 = fn_ROCX000002(*(void **)((char *)p1 + 4)) + 1;

    return fn_ROCX000002(p0, p1, n0, n1, a, b);
}
}