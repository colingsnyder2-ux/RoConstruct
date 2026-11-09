// from server: 100% by EspClaude
// roc 2009-06 005aac00  unit: seg_005a0000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005aac00
//
// 005aac00  55                   push ebp
// 005aac01  8bec                 mov ebp, esp
// 005aac03  0fb605d12ca400       movzx eax, byte ptr [0xa42cd1]
// 005aac0a  85c0                 test eax, eax
// 005aac0c  7402                 je 0x5aac10
// 005aac0e  eb0c                 jmp 0x5aac1c
// 005aac10  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005aac13  e8685fefff           call 0x4a0b80
// 005aac18  33c9                 xor ecx, ecx
// 005aac1a  75fc                 jne 0x5aac18
// 005aac1c  5d                   pop ebp
// 005aac1d  c3                   ret 
// copied from an identical function in another client (function ?restoreDevice@@YAXPAVDevice@@@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// Analog for 00549030: unless shared state is disabled (009738a1), resets the
// device (004796a0).
class Device {
public:
    void restore();
};

extern bool sharedDisabled;

void restoreDevice(Device* device)
{
    if (sharedDisabled)
        return;
    device->restore();
    do {} while (0);
}