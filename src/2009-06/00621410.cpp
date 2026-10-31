// from server: 100% by EspClaude
// roc 2009-06 00621410  unit: RBX::RootInstance  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00621410
//
// 00621410  53                   push ebx
// 00621411  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00621415  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00621418  56                   push esi
// 00621419  8bf1                 mov esi, ecx
// 0062141b  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0062141e  2bc8                 sub ecx, eax
// 00621420  83e1f8               and ecx, 0xfffffff8
// 00621423  57                   push edi
// 00621424  83f908               cmp ecx, 8
// 00621427  753f                 jne 0x621468
// 00621429  8b38                 mov edi, dword ptr [eax]
// 0062142b  6a00                 push 0
// 0062142d  680499a000           push 0xa09904
// 00621432  6840be9d00           push 0x9dbe40
// 00621437  6a00                 push 0
// 00621439  57                   push edi
// 0062143a  e83b880f00           call 0x719c7a
// 0062143f  83c414               add esp, 0x14
// 00621442  85c0                 test eax, eax
// 00621444  7422                 je 0x621468
// 00621446  56                   push esi
// 00621447  e8449beaff           call 0x4caf90
// 0062144c  83c404               add esp, 4
// 0062144f  85c0                 test eax, eax
// 00621451  7415                 je 0x621468
// 00621453  8bc8                 mov ecx, eax
// 00621455  e8d65ce9ff           call 0x4b7130
// 0062145a  50                   push eax
// 0062145b  8bcf                 mov ecx, edi
// 0062145d  e8ee09fbff           call 0x5d1e50
// 00621462  5f                   pop edi
// 00621463  5e                   pop esi
// 00621464  5b                   pop ebx
// 00621465  c20800               ret 8
// 00621468  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0062146c  57                   push edi
// 0062146d  56                   push esi
// 0062146e  53                   push ebx
// 0062146f  8bce                 mov ecx, esi
// 00621471  e8aaf7ffff           call 0x620c20
// 00621476  57                   push edi
// 00621477  8bce                 mov ecx, esi
// 00621479  e8e2fdffff           call 0x621260
// 0062147e  5f                   pop edi
// 0062147f  5e                   pop esi
// 00621480  5b                   pop ebx
// 00621481  c20800               ret 8
// copied from an identical function in another client (function ?dispatch@Root@ns_ROCX000014@@QAEXPAUArguments@2@PAX@Z)

namespace ns_ROCX000014 {
struct Object {
    void apply(void*);
};

struct Entry {
    Object* object;
    void* ownership;
};

struct Arguments {
    char padding[12];
    Entry* first;
    Entry* last;
};

struct Service {
    void* value();
};

extern "C" void* __cdecl findService(void*);
extern "C" void* __cdecl castObject(void*, int, const void*, const void*, int);

extern const char instanceType[];
extern const char hopperBinType[];

struct Root {
    void dispatch(Arguments*, void*);
    void fallback(Arguments*, Root*, void*);
    void finish(void*);
};

void Root::dispatch(Arguments* args, void* context)
{
    if (((unsigned int)args->last - (unsigned int)args->first) / 8 == 1) {
        Object* object = args->first->object;
        if (castObject(object, 0, instanceType, hopperBinType, 0)) {
            Service* service = (Service*)findService(this);
            if (service) {
                object->apply(service->value());
                return;
            }
        }
    }

    fallback(args, this, context);
    finish(context);
}
}
