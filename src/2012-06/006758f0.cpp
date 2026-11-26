// from server: 100% by Xemicl
// roc 2012-06 006758f0  unit: RBX::XVGfxBinding::XV?$mf2::V?$bind_t::?$callable_slot  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006758f0
//
// 006758f0  55                   push ebp
// 006758f1  8bec                 mov ebp, esp
// 006758f3  51                   push ecx
// 006758f4  894dfc               mov dword ptr [ebp - 4], ecx
// 006758f7  8b45fc               mov eax, dword ptr [ebp - 4]
// 006758fa  8b4d08               mov ecx, dword ptr [ebp + 8]
// 006758fd  894808               mov dword ptr [eax + 8], ecx
// 00675900  8b55fc               mov edx, dword ptr [ebp - 4]
// 00675903  837a0800             cmp dword ptr [edx + 8], 0
// 00675907  7510                 jne 0x675919
// 00675909  8b45fc               mov eax, dword ptr [ebp - 4]
// 0067590c  c6400400             mov byte ptr [eax + 4], 0
// 00675910  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00675913  c6410d00             mov byte ptr [ecx + 0xd], 0
// 00675917  eb17                 jmp 0x675930
// 00675919  8b55fc               mov edx, dword ptr [ebp - 4]
// 0067591c  837a0801             cmp dword ptr [edx + 8], 1
// 00675920  750e                 jne 0x675930
// 00675922  8b45fc               mov eax, dword ptr [ebp - 4]
// 00675925  c6400401             mov byte ptr [eax + 4], 1
// 00675929  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0067592c  c6410d01             mov byte ptr [ecx + 0xd], 1
// 00675930  8be5                 mov esp, ebp
// 00675932  5d                   pop ebp
// 00675933  c20400               ret 4
// copied from an identical function in another client (function ?setMode@S@@QAEXH@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct S { int pad; bool a; char p1[3]; int mode; char p2; bool b; void setMode(int m); };
void S::setMode(int m)
{
    mode = m;
    if (mode == 0) { a = false; b = false; }
    else if (mode == 1) { a = true; b = true; }
}