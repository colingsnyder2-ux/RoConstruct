// from server: 100% by Intel
// from server: 97% by EspClaude
// roc 2007-08 00460840  unit: CScriptDoc  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00460840
//
// 00460840  51                   push ecx
// 00460841  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00460845  56                   push esi
// 00460846  33f6                 xor esi, esi
// 00460848  3bc6                 cmp eax, esi
// 0046084a  89742404             mov dword ptr [esp + 4], esi
// 0046084e  750c                 jne 0x46085c
// 00460850  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00460854  8930                 mov dword ptr [eax], esi
// 00460856  897004               mov dword ptr [eax + 4], esi
// 00460859  5e                   pop esi
// 0046085a  59                   pop ecx
// 0046085b  c3                   ret 
// 0046085c  8b88bc000000         mov ecx, dword ptr [eax + 0xbc]
// 00460862  3bce                 cmp ecx, esi
// 00460864  7405                 je 0x46086b
// 00460866  e8759cfcff           call 0x42a4e0
// 0046086b  56                   push esi
// 0046086c  68a0658800           push 0x8865a0
// 00460871  684c1f8800           push 0x881f4c
// 00460876  56                   push esi
// 00460877  50                   push eax
// 00460878  e8b9041d00           call 0x630d36
// 0046087d  83c414               add esp, 0x14
// 00460880  3bc6                 cmp eax, esi
// 00460882  74cc                 je 0x460850
// 00460884  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00460888  56                   push esi
// 00460889  8bc8                 mov ecx, eax
// 0046088b  e860fdffff           call 0x4605f0
// 00460890  8bc6                 mov eax, esi
// 00460892  5e                   pop esi
// 00460893  59                   pop ecx
// 00460894  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 00464750  unit: CScriptDoc  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00464750
//
// 00464750  51                   push ecx
// 00464751  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00464755  56                   push esi
// 00464756  33f6                 xor esi, esi
// 00464758  89742404             mov dword ptr [esp + 4], esi
// 0046475c  3bc6                 cmp eax, esi
// 0046475e  750c                 jne 0x46476c
// 00464760  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00464764  8930                 mov dword ptr [eax], esi
// 00464766  897004               mov dword ptr [eax + 4], esi
// 00464769  5e                   pop esi
// 0046476a  59                   pop ecx
// 0046476b  c3                   ret 
// 0046476c  8b8804010000         mov ecx, dword ptr [eax + 0x104]
// 00464772  3bce                 cmp ecx, esi
// 00464774  7405                 je 0x46477b
// 00464776  e8755efcff           call 0x42a5f0
// 0046477b  56                   push esi
// 0046477c  68a0e89200           push 0x92e8a0
// 00464781  687c909200           push 0x92907c
// 00464786  56                   push esi
// 00464787  50                   push eax
// 00464788  e839d02300           call 0x6a17c6
// 0046478d  83c414               add esp, 0x14
// 00464790  3bc6                 cmp eax, esi
// 00464792  74cc                 je 0x464760
// 00464794  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00464798  56                   push esi
// 00464799  8bc8                 mov ecx, eax
// 0046479b  e870ffffff           call 0x464710
// 004647a0  8bc6                 mov eax, esi
// 004647a2  5e                   pop esi
// 004647a3  59                   pop ecx
// 004647a4  c3                   ret 

struct Result
{
    void *object;
    void *count;

    Result() : object(0), count(0) {}
};

struct Instance
{
    char padding[0xbc];
    Instance *parent;

    Instance *getRootAncestor();
};

struct DataModel
{
    Result getResult();
};

extern char instanceType;
extern char dataModelType;

extern "C" void *__cdecl __RTDynamicCast(
    void *, long, void *, void *, int);

Result func_00464750(Instance *instance)
{
    volatile int temporary = 0;

    if (!instance)
        return Result();

    Instance *root = instance;
    if (root->parent)
        root = root->parent->getRootAncestor();

    DataModel *model = static_cast<DataModel *>(
        __RTDynamicCast(root, 0, &instanceType, &dataModelType, 0));

    if (!model)
        return Result();

    return model->getResult();
}
