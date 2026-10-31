// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00540780  unit: RBX::RenderBase::AggregatingSceneManager::Bucket  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00540780
//
// 00540780  55                   push ebp
// 00540781  8bec                 mov ebp, esp
// 00540783  83ec2c               sub esp, 0x2c
// 00540786  894dd4               mov dword ptr [ebp - 0x2c], ecx
// 00540789  8d45f0               lea eax, [ebp - 0x10]
// 0054078c  50                   push eax
// 0054078d  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 00540790  e8cbfeffff           call 0x540660
// 00540795  8b08                 mov ecx, dword ptr [eax]
// 00540797  8b5004               mov edx, dword ptr [eax + 4]
// 0054079a  894df8               mov dword ptr [ebp - 8], ecx
// 0054079d  8955fc               mov dword ptr [ebp - 4], edx
// 005407a0  8d45e0               lea eax, [ebp - 0x20]
// 005407a3  50                   push eax
// 005407a4  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005407a7  e884feffff           call 0x540630
// 005407ac  8b08                 mov ecx, dword ptr [eax]
// 005407ae  8b5004               mov edx, dword ptr [eax + 4]
// 005407b1  894de8               mov dword ptr [ebp - 0x18], ecx
// 005407b4  8955ec               mov dword ptr [ebp - 0x14], edx
// 005407b7  8b45fc               mov eax, dword ptr [ebp - 4]
// 005407ba  50                   push eax
// 005407bb  8b4df8               mov ecx, dword ptr [ebp - 8]
// 005407be  51                   push ecx
// 005407bf  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 005407c2  52                   push edx
// 005407c3  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 005407c6  50                   push eax
// 005407c7  8d4dd8               lea ecx, [ebp - 0x28]
// 005407ca  51                   push ecx
// 005407cb  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005407ce  e82d0c0000           call 0x541400
// 005407d3  8be5                 mov esp, ebp
// 005407d5  5d                   pop ebp
// 005407d6  c3                   ret 

struct Bucket;

struct Result {
    void* value;
    Bucket* owner;
    void initialize(void* value, Bucket* owner);
};

struct Bucket {
    Result* begin(Result* result);
    Result* end(Result* result);
    Result erase(Result first, Result last);
    void clear();
};

#pragma optimize("", off)
void Bucket::clear()
{
    struct Locals {
        Result firstTemporary;
        Result first;
        Result lastTemporary;
        Result last;
    } locals;

    locals.last = *end(&locals.lastTemporary);
    locals.first = *begin(&locals.firstTemporary);
    erase(locals.first, locals.last);
}
