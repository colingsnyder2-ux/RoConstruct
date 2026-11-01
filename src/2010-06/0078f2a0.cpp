// from server: 100% by Yeetserama
// roc 2010-06 0078f2a0  unit: RBX::VGroupDragTool::?$Named  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0078f2a0
//
// 0078f2a0  56                   push esi
// 0078f2a1  8bf1                 mov esi, ecx
// 0078f2a3  807e2800             cmp byte ptr [esi + 0x28], 0
// 0078f2a7  7440                 je 0x78f2e9
// 0078f2a9  8b442408             mov eax, dword ptr [esp + 8]
// 0078f2ad  8b4008               mov eax, dword ptr [eax + 8]
// 0078f2b0  83e872               sub eax, 0x72
// 0078f2b3  57                   push edi
// 0078f2b4  741c                 je 0x78f2d2
// 0078f2b6  83e802               sub eax, 2
// 0078f2b9  7527                 jne 0x78f2e2
// 0078f2bb  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 0078f2be  e84d0ff0ff           call 0x690210
// 0078f2c3  50                   push eax
// 0078f2c4  8bcf                 mov ecx, edi
// 0078f2c6  e86591f8ff           call 0x718430
// 0078f2cb  5f                   pop edi
// 0078f2cc  8bc6                 mov eax, esi
// 0078f2ce  5e                   pop esi
// 0078f2cf  c20400               ret 4
// 0078f2d2  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 0078f2d5  e8a60ef0ff           call 0x690180
// 0078f2da  50                   push eax
// 0078f2db  8bcf                 mov ecx, edi
// 0078f2dd  e84e91f8ff           call 0x718430
// 0078f2e2  5f                   pop edi
// 0078f2e3  8bc6                 mov eax, esi
// 0078f2e5  5e                   pop esi
// 0078f2e6  c20400               ret 4
// 0078f2e9  33c0                 xor eax, eax
// 0078f2eb  5e                   pop esi
// 0078f2ec  c20400               ret 4
// copied from an identical function in another client (function ?onMouseUp@GroupDragTool@ns_ROCX000014@@QAEPAXPAX@Z)

namespace ns_ROCX000014 {
// from server: 100% by king_originala
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
}
