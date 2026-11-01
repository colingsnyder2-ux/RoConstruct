// from server: 100% by Espeon
// from server: 78% by colin
// roc 2008-06 0060d140  unit: RBX::BallBlockContact  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060d140
//
// 0060d140  51                   push ecx
// 0060d141  53                   push ebx
// 0060d142  55                   push ebp
// 0060d143  56                   push esi
// 0060d144  57                   push edi
// 0060d145  8bf9                 mov edi, ecx
// 0060d147  6a00                 push 0
// 0060d149  8d5f08               lea ebx, [edi + 8]
// 0060d14c  6a00                 push 0
// 0060d14e  8bcb                 mov ecx, ebx
// 0060d150  897c2418             mov dword ptr [esp + 0x18], edi
// 0060d154  e817c9f8ff           call 0x599a70
// 0060d159  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060d15d  8b742418             mov esi, dword ptr [esp + 0x18]
// 0060d161  8b0f                 mov ecx, dword ptr [edi]
// 0060d163  53                   push ebx
// 0060d164  50                   push eax
// 0060d165  56                   push esi
// 0060d166  e8f5da0400           call 0x65ac60
// 0060d16b  33ed                 xor ebp, ebp
// 0060d16d  396f0c               cmp dword ptr [edi + 0xc], ebp
// 0060d170  7e79                 jle 0x60d1eb
// 0060d172  8b03                 mov eax, dword ptr [ebx]
// 0060d174  8d3cad00000000       lea edi, [ebp*4]
// 0060d17b  8b0c38               mov ecx, dword ptr [eax + edi]
// 0060d17e  03c7                 add eax, edi
// 0060d180  e8cba8fdff           call 0x5e7a50
// 0060d185  8bc8                 mov ecx, eax
// 0060d187  d9410c               fld dword ptr [ecx + 0xc]
// 0060d18a  d81e                 fcomp dword ptr [esi]
// 0060d18c  dfe0                 fnstsw ax
// 0060d18e  f6c405               test ah, 5
// 0060d191  7b4e                 jnp 0x60d1e1
// 0060d193  d94110               fld dword ptr [ecx + 0x10]
// 0060d196  d85e04               fcomp dword ptr [esi + 4]
// 0060d199  dfe0                 fnstsw ax
// 0060d19b  f6c405               test ah, 5
// 0060d19e  7b41                 jnp 0x60d1e1
// 0060d1a0  d94114               fld dword ptr [ecx + 0x14]
// 0060d1a3  d85e08               fcomp dword ptr [esi + 8]
// 0060d1a6  dfe0                 fnstsw ax
// 0060d1a8  f6c405               test ah, 5
// 0060d1ab  7b34                 jnp 0x60d1e1
// 0060d1ad  d94104               fld dword ptr [ecx + 4]
// 0060d1b0  d85e10               fcomp dword ptr [esi + 0x10]
// 0060d1b3  dfe0                 fnstsw ax
// 0060d1b5  f6c441               test ah, 0x41
// 0060d1b8  7427                 je 0x60d1e1
// 0060d1ba  d901                 fld dword ptr [ecx]
// 0060d1bc  d85e0c               fcomp dword ptr [esi + 0xc]
// 0060d1bf  dfe0                 fnstsw ax
// 0060d1c1  f6c441               test ah, 0x41
// 0060d1c4  741b                 je 0x60d1e1
// 0060d1c6  d94108               fld dword ptr [ecx + 8]
// 0060d1c9  d85e14               fcomp dword ptr [esi + 0x14]
// 0060d1cc  dfe0                 fnstsw ax
// 0060d1ce  f6c441               test ah, 0x41
// 0060d1d1  740e                 je 0x60d1e1
// 0060d1d3  8b0b                 mov ecx, dword ptr [ebx]
// 0060d1d5  03cf                 add ecx, edi
// 0060d1d7  51                   push ecx
// 0060d1d8  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0060d1dc  e8afcff8ff           call 0x59a190
// 0060d1e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0060d1e5  45                   inc ebp
// 0060d1e6  3b6a0c               cmp ebp, dword ptr [edx + 0xc]
// 0060d1e9  7c87                 jl 0x60d172
// 0060d1eb  5f                   pop edi
// 0060d1ec  5e                   pop esi
// 0060d1ed  5d                   pop ebp
// 0060d1ee  5b                   pop ebx
// 0060d1ef  59                   pop ecx
// 0060d1f0  c20c00               ret 0xc

// from server: 73% by king_originala
// roc 2008-06 0060d140  unit: RBX::BallBlockContact  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060d140
//
// 0060d140  51                   push ecx
// 0060d141  53                   push ebx
// 0060d142  55                   push ebp
// 0060d143  56                   push esi
// 0060d144  57                   push edi
// 0060d145  8bf9                 mov edi, ecx
// 0060d147  6a00                 push 0
// 0060d149  8d5f08               lea ebx, [edi + 8]
// 0060d14c  6a00                 push 0
// 0060d14e  8bcb                 mov ecx, ebx
// 0060d150  897c2418             mov dword ptr [esp + 0x18], edi
// 0060d154  e817c9f8ff           call 0x599a70
// 0060d159  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060d15d  8b742418             mov esi, dword ptr [esp + 0x18]
// 0060d161  8b0f                 mov ecx, dword ptr [edi]
// 0060d163  53                   push ebx
// 0060d164  50                   push eax
// 0060d165  56                   push esi
// 0060d166  e8f5da0400           call 0x65ac60
// 0060d16b  33ed                 xor ebp, ebp
// 0060d16d  396f0c               cmp dword ptr [edi + 0xc], ebp
// 0060d170  7e79                 jle 0x60d1eb
// 0060d172  8b03                 mov eax, dword ptr [ebx]
// 0060d174  8d3cad00000000       lea edi, [ebp*4]
// 0060d17b  8b0c38               mov ecx, dword ptr [eax + edi]
// 0060d17e  03c7                 add eax, edi
// 0060d180  e8cba8fdff           call 0x5e7a50
// 0060d185  8bc8                 mov ecx, eax
// 0060d187  d9410c               fld dword ptr [ecx + 0xc]
// 0060d18a  d81e                 fcomp dword ptr [esi]
// 0060d18c  dfe0                 fnstsw ax
// 0060d18e  f6c405               test ah, 5
// 0060d191  7b4e                 jnp 0x60d1e1
// 0060d193  d94110               fld dword ptr [ecx + 0x10]
// 0060d196  d85e04               fcomp dword ptr [esi + 4]
// 0060d199  dfe0                 fnstsw ax
// 0060d19b  f6c405               test ah, 5
// 0060d19e  7b41                 jnp 0x60d1e1
// 0060d1a0  d94114               fld dword ptr [ecx + 0x14]
// 0060d1a3  d85e08               fcomp dword ptr [esi + 8]
// 0060d1a6  dfe0                 fnstsw ax
// 0060d1a8  f6c405               test ah, 5
// 0060d1ab  7b34                 jnp 0x60d1e1
// 0060d1ad  d94104               fld dword ptr [ecx + 4]
// 0060d1b0  d85e10               fcomp dword ptr [esi + 0x10]
// 0060d1b3  dfe0                 fnstsw ax
// 0060d1b5  f6c441               test ah, 0x41
// 0060d1b8  7427                 je 0x60d1e1
// 0060d1ba  d901                 fld dword ptr [ecx]
// 0060d1bc  d85e0c               fcomp dword ptr [esi + 0xc]
// 0060d1bf  dfe0                 fnstsw ax
// 0060d1c1  f6c441               test ah, 0x41
// 0060d1c4  741b                 je 0x60d1e1
// 0060d1c6  d94108               fld dword ptr [ecx + 8]
// 0060d1c9  d85e14               fcomp dword ptr [esi + 0x14]
// 0060d1cc  dfe0                 fnstsw ax
// 0060d1ce  f6c441               test ah, 0x41
// 0060d1d1  740e                 je 0x60d1e1
// 0060d1d3  8b0b                 mov ecx, dword ptr [ebx]
// 0060d1d5  03cf                 add ecx, edi
// 0060d1d7  51                   push ecx
// 0060d1d8  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0060d1dc  e8afcff8ff           call 0x59a190
// 0060d1e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0060d1e5  45                   inc ebp
// 0060d1e6  3b6a0c               cmp ebp, dword ptr [edx + 0xc]
// 0060d1e9  7c87                 jl 0x60d172
// 0060d1eb  5f                   pop edi
// 0060d1ec  5e                   pop esi
// 0060d1ed  5d                   pop ebp
// 0060d1ee  5b                   pop ebx
// 0060d1ef  59                   pop ecx
// 0060d1f0  c20c00               ret 0xc

#pragma float_control(precise, off)

struct Box {
    float x0, y0, z0;
    float x1, y1, z1;
};

struct Source {
    char reserved[0x90];
    unsigned int version;
    const void* get();
};

struct List {
    Source** data;
    int count;
    int capacity;

    void reset(int, int);
    void append(Source* const*);
};

struct Owner {
    void query(const Box*, int, List*);
};

struct Contact {
    Owner* owner;
    int reserved;
    List candidates;

    void collect(const Box*, int, List*);
};

void Contact::collect(const Box* box, int argument, List* output)
{
    candidates.reset(0, 0);
    owner->query(box, argument, &candidates);

    for (int i = 0; i < candidates.count; ++i) {
        Source*& source = candidates.data[i];
        const Box* bounds = static_cast<const Box*>(source->get());

        if (!(box->x0 > bounds->x1) &&
            !(box->y0 > bounds->y1) &&
            !(box->z0 > bounds->z1) &&
            !(box->y1 < bounds->y0) &&
            !(box->x1 < bounds->x0) &&
            !(box->z1 < bounds->z0)) {
            output->append(&candidates.data[i]);
        }
    }
}
