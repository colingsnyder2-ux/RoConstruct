// from server: 100% by user
// from server: 99% by king_originala
// roc 2008-06 005ea4d0  unit: RBX::PhysicsService  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ea4d0
//
// 005ea4d0  83ec14               sub esp, 0x14
// 005ea4d3  56                   push esi
// 005ea4d4  57                   push edi
// 005ea4d5  8bf1                 mov esi, ecx
// 005ea4d7  ff86ec000000         inc dword ptr [esi + 0xec]
// 005ea4dd  6a00                 push 0
// 005ea4df  8dbef0000000         lea edi, [esi + 0xf0]
// 005ea4e5  6a00                 push 0
// 005ea4e7  8bcf                 mov ecx, edi
// 005ea4e9  e882f5faff           call 0x599a70
// 005ea4ee  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005ea4f2  57                   push edi
// 005ea4f3  51                   push ecx
// 005ea4f4  e857d5ffff           call 0x5e7a50
// 005ea4f9  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 005ea4ff  50                   push eax
// 005ea500  e83b2c0200           call 0x60d140
// 005ea505  33c0                 xor eax, eax
// 005ea507  3986f4000000         cmp dword ptr [esi + 0xf4], eax
// 005ea50d  89442408             mov dword ptr [esp + 8], eax
// 005ea511  0f8ead000000         jle 0x5ea5c4
// 005ea517  53                   push ebx
// 005ea518  55                   push ebp
// 005ea519  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 005ea51d  8d4900               lea ecx, [ecx]
// 005ea520  8b8ef0000000         mov ecx, dword ptr [esi + 0xf0]
// 005ea526  8b1c81               mov ebx, dword ptr [ecx + eax*4]
// 005ea529  895c242c             mov dword ptr [esp + 0x2c], ebx
// 005ea52d  85ed                 test ebp, ebp
// 005ea52f  743c                 je 0x5ea56d
// 005ea531  8b5518               mov edx, dword ptr [ebp + 0x18]
// 005ea534  8b4500               mov eax, dword ptr [ebp]
// 005ea537  8d4c242c             lea ecx, [esp + 0x2c]
// 005ea53b  89542418             mov dword ptr [esp + 0x18], edx
// 005ea53f  51                   push ecx
// 005ea540  8d542420             lea edx, [esp + 0x20]
// 005ea544  52                   push edx
// 005ea545  8bcd                 mov ecx, ebp
// 005ea547  8944241c             mov dword ptr [esp + 0x1c], eax
// 005ea54b  e8103becff           call 0x4ae060
// 005ea550  8bf8                 mov edi, eax
// 005ea552  8b07                 mov eax, dword ptr [edi]
// 005ea554  85c0                 test eax, eax
// 005ea556  7406                 je 0x5ea55e
// 005ea558  3b442414             cmp eax, dword ptr [esp + 0x14]
// 005ea55c  7406                 je 0x5ea564
// 005ea55e  ff1590288000         call dword ptr [0x802890]
// 005ea564  8b442418             mov eax, dword ptr [esp + 0x18]
// 005ea568  394704               cmp dword ptr [edi + 4], eax
// 005ea56b  7540                 jne 0x5ea5ad
// 005ea56d  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005ea571  53                   push ebx
// 005ea572  57                   push edi
// 005ea573  e868d7ffff           call 0x5e7ce0
// 005ea578  83c408               add esp, 8
// 005ea57b  85c0                 test eax, eax
// 005ea57d  752e                 jne 0x5ea5ad
// 005ea57f  53                   push ebx
// 005ea580  57                   push edi
// 005ea581  e88a2e0600           call 0x64d410
// 005ea586  8bf8                 mov edi, eax
// 005ea588  83c408               add esp, 8
// 005ea58b  85ff                 test edi, edi
// 005ea58d  741e                 je 0x5ea5ad
// 005ea58f  57                   push edi
// 005ea590  8bce                 mov ecx, esi
// 005ea592  e889fdffff           call 0x5ea320
// 005ea597  57                   push edi
// 005ea598  8bce                 mov ecx, esi
// 005ea59a  c686a500000001       mov byte ptr [esi + 0xa5], 1
// 005ea5a1  e89af3ffff           call 0x5e9940
// 005ea5a6  c686a500000000       mov byte ptr [esi + 0xa5], 0
// 005ea5ad  8b442410             mov eax, dword ptr [esp + 0x10]
// 005ea5b1  40                   inc eax
// 005ea5b2  3b86f4000000         cmp eax, dword ptr [esi + 0xf4]
// 005ea5b8  89442410             mov dword ptr [esp + 0x10], eax
// 005ea5bc  0f8c5effffff         jl 0x5ea520
// 005ea5c2  5d                   pop ebp
// 005ea5c3  5b                   pop ebx
// 005ea5c4  5f                   pop edi
// 005ea5c5  5e                   pop esi
// 005ea5c6  83c414               add esp, 0x14
// 005ea5c9  c20800               ret 8

struct Geometry {
    const void* getBounds();
};
struct Connection;

struct Array {
    Geometry** data;
    int count;
    void reset(int, int);
};

struct Receiver {
    void collect(const void*, Geometry*, Array*);
};

struct Iterator {
    void* owner;
    void* node;
};

struct Filter {
    void* owner;
    unsigned char reserved[0x14];
    void* endNode;

    Iterator* find(Iterator*, Geometry**);
};

extern "C" {
    extern void (__cdecl* _invalid_parameter_noinfo)();
}
void* __cdecl findConnection(Geometry*, Geometry*);
Connection* __cdecl makeConnection(Geometry*, Geometry*);

struct S {
    unsigned char reserved0[0x84];
    Receiver* receiver;
    unsigned char reserved1[0x1D];
    unsigned char active;
    unsigned char reserved2[0x46];
    int version;
    Array candidates;

    void prepare(Connection*);
    void process(Connection*);
    void f(Geometry*, Filter*);
};

void S::f(Geometry* geometry, Filter* filter)
{
    ++version;
    candidates.reset(0, 0);
    receiver->collect(geometry->getBounds(), geometry, &candidates);

    for (int i = 0; i < candidates.count; ++i) {
        Geometry* candidate = candidates.data[i];
        Geometry* key = candidate;

        if (filter) {
            Iterator end;
            end.node = filter->endNode;
            end.owner = filter->owner;
            Iterator result;
            Iterator* found = filter->find(&result, &key);

            if (!found->owner || found->owner != end.owner)
                _invalid_parameter_noinfo();

            if (found->node != end.node)
                continue;
        }

        if (!findConnection(geometry, candidate)) {
            Connection* connection = makeConnection(geometry, candidate);
            if (connection) {
                prepare(connection);
                active = 1;
                process(connection);
                active = 0;
            }
        }
    }
}
