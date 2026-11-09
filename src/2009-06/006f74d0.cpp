// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0066a980  unit: RBX::GroupDragTool  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066a980
//
// 0066a980  56                   push esi
// 0066a981  8bf1                 mov esi, ecx
// 0066a983  807e2800             cmp byte ptr [esi + 0x28], 0
// 0066a987  7440                 je 0x66a9c9
// 0066a989  8b442408             mov eax, dword ptr [esp + 8]
// 0066a98d  8b4008               mov eax, dword ptr [eax + 8]
// 0066a990  83e872               sub eax, 0x72
// 0066a993  57                   push edi
// 0066a994  741c                 je 0x66a9b2
// 0066a996  83e802               sub eax, 2
// 0066a999  7527                 jne 0x66a9c2
// 0066a99b  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 0066a99e  e8ed3ef7ff           call 0x5de890
// 0066a9a3  50                   push eax
// 0066a9a4  8bcf                 mov ecx, edi
// 0066a9a6  e86539faff           call 0x60e310
// 0066a9ab  5f                   pop edi
// 0066a9ac  8bc6                 mov eax, esi
// 0066a9ae  5e                   pop esi
// 0066a9af  c20400               ret 4
// 0066a9b2  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 0066a9b5  e8463ef7ff           call 0x5de800
// 0066a9ba  50                   push eax
// 0066a9bb  8bcf                 mov ecx, edi
// 0066a9bd  e84e39faff           call 0x60e310
// 0066a9c2  5f                   pop edi
// 0066a9c3  8bc6                 mov eax, esi
// 0066a9c5  5e                   pop esi
// 0066a9c6  c20400               ret 4
// 0066a9c9  33c0                 xor eax, eax
// 0066a9cb  5e                   pop esi
// 0066a9cc  c20400               ret 4

struct Helper {
    void method(void* arg);
};

extern "C" void* __stdcall sub_5de800();
extern "C" void* __stdcall sub_5de890();

struct GroupDragTool {
    char pad[0x1c];
    Helper* megaDragger;
    char pad2[8];
    bool dragging;
    void* onMouseUp(void* inputObject);
};

void* GroupDragTool::onMouseUp(void* inputObject)
{
    if (dragging) {
        switch (*(int*)((char*)inputObject + 8)) {
        case 0x72: {
            Helper* receiver = megaDragger;
            void* p = sub_5de800();
            receiver->method(p);
            break;
        }
        case 0x74: {
            Helper* receiver = megaDragger;
            void* p = sub_5de890();
            receiver->method(p);
            break;
        }
        }
        return this;
    }
    return 0;
}
