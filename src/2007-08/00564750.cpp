// from server: 100% by EspClaude
// from server: 58% by Intel
// roc 2007-08 00564750  unit: RBX::FollowCameraCommand  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00564750
//
// 00564750  51                   push ecx
// 00564751  56                   push esi
// 00564752  8bf1                 mov esi, ecx
// 00564754  6a01                 push 1
// 00564756  8d4e14               lea ecx, [esi + 0x14]
// 00564759  e8a2dbffff           call 0x562300
// 0056475e  8b8004010000         mov eax, dword ptr [eax + 0x104]
// 00564764  8b4804               mov ecx, dword ptr [eax + 4]
// 00564767  85c9                 test ecx, ecx
// 00564769  7439                 je 0x5647a4
// 0056476b  8b4008               mov eax, dword ptr [eax + 8]
// 0056476e  2bc1                 sub eax, ecx
// 00564770  c1f803               sar eax, 3
// 00564773  742f                 je 0x5647a4
// 00564775  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00564778  85c9                 test ecx, ecx
// 0056477a  7407                 je 0x564783
// 0056477c  e85fd1ffff           call 0x5618e0
// 00564781  eb02                 jmp 0x564785
// 00564783  33c0                 xor eax, eax
// 00564785  8b88f8000000         mov ecx, dword ptr [eax + 0xf8]
// 0056478b  85c9                 test ecx, ecx
// 0056478d  7415                 je 0x5647a4
// 0056478f  8b80fc000000         mov eax, dword ptr [eax + 0xfc]
// 00564795  2bc1                 sub eax, ecx
// 00564797  c1f802               sar eax, 2
// 0056479a  83f801               cmp eax, 1
// 0056479d  7505                 jne 0x5647a4
// 0056479f  8ac0                 mov al, al
// 005647a1  5e                   pop esi
// 005647a2  59                   pop ecx
// 005647a3  c3                   ret 
// 005647a4  32c0                 xor al, al
// 005647a6  5e                   pop esi
// 005647a7  59                   pop ecx
// 005647a8  c3                   ret 

#include <vector>

struct Entry {
    int a;
    int b;
};

struct Source {
    int pad[65];
    std::vector<Entry>* entries;
};

struct Target {
    int pad[61];
    std::vector<void*> items;
};

struct SourceRef {
    int pad[3];
    Source* get(int which);
};

struct TargetOwner {
    Target* getTarget();
};

struct FollowCameraCommand {
    int pad[5];
    SourceRef source;
    TargetOwner* owner;
    bool isEnabled();
};

bool FollowCameraCommand::isEnabled()
{
    if (source.get(1)->entries->size() != 0) {
        Target* t = owner ? owner->getTarget() : 0;
        if (t->items.size() == 1)
            return true;
    }
    return false;
}
