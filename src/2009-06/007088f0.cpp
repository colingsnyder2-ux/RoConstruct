// from server: 100% by EspClaude
// from server: 78% by EspClaude
// roc 2009-06 007088f0  unit: RBX::worker_thread::Udata::?$sp_counted_impl_p  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007088f0
//
// 007088f0  81ec10010000         sub esp, 0x110
// 007088f6  56                   push esi
// 007088f7  8d442404             lea eax, [esp + 4]
// 007088fb  50                   push eax
// 007088fc  8d7140               lea esi, [ecx + 0x40]
// 007088ff  ff1560e28900         call dword ptr [0x89e260]
// 00708905  0fb74c2412           movzx ecx, word ptr [esp + 0x12]
// 0070890a  0fb7542410           movzx edx, word ptr [esp + 0x10]
// 0070890f  0fb744240e           movzx eax, word ptr [esp + 0xe]
// 00708914  51                   push ecx
// 00708915  0fb74c2410           movzx ecx, word ptr [esp + 0x10]
// 0070891a  52                   push edx
// 0070891b  50                   push eax
// 0070891c  51                   push ecx
// 0070891d  6808f98e00           push 0x8ef908
// 00708922  8d542428             lea edx, [esp + 0x28]
// 00708926  6800010000           push 0x100
// 0070892b  52                   push edx
// 0070892c  ff15fce88900         call dword ptr [0x89e8fc]
// 00708932  8d442430             lea eax, [esp + 0x30]
// 00708936  50                   push eax
// 00708937  56                   push esi
// 00708938  e8d3ddd3ff           call 0x446710
// 0070893d  83c424               add esp, 0x24
// 00708940  8bce                 mov ecx, esi
// 00708942  ff1518e48900         call dword ptr [0x89e418]
// 00708948  8b842418010000       mov eax, dword ptr [esp + 0x118]
// 0070894f  83e800               sub eax, 0
// 00708952  741c                 je 0x708970
// 00708954  83e801               sub eax, 1
// 00708957  740e                 je 0x708967
// 00708959  83e801               sub eax, 1
// 0070895c  7521                 jne 0x70897f
// 0070895e  8b0d5849a200         mov ecx, dword ptr [0xa24958]
// 00708964  51                   push ecx
// 00708965  eb0f                 jmp 0x708976
// 00708967  8b155449a200         mov edx, dword ptr [0xa24954]
// 0070896d  52                   push edx
// 0070896e  eb06                 jmp 0x708976
// 00708970  a15049a200           mov eax, dword ptr [0xa24950]
// 00708975  50                   push eax
// 00708976  56                   push esi
// 00708977  e894ddd3ff           call 0x446710
// 0070897c  83c408               add esp, 8
// 0070897f  8b8c241c010000       mov ecx, dword ptr [esp + 0x11c]
// 00708986  51                   push ecx
// 00708987  56                   push esi
// 00708988  e883ddd3ff           call 0x446710
// 0070898d  6a0a                 push 0xa
// 0070898f  56                   push esi
// 00708990  e86bdfd3ff           call 0x446900
// 00708995  83c410               add esp, 0x10
// 00708998  8bce                 mov ecx, esi
// 0070899a  ff1518e48900         call dword ptr [0x89e418]
// 007089a0  5e                   pop esi
// 007089a1  81c410010000         add esp, 0x110
// 007089a7  c20800               ret 8

// from server: 100% by king_originala
// roc 2008-06 005a6ef0  unit: RBX::Workspace  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a6ef0
//
// 005a6ef0  81ec10010000         sub esp, 0x110
// 005a6ef6  56                   push esi
// 005a6ef7  8d442404             lea eax, [esp + 4]
// 005a6efb  50                   push eax
// 005a6efc  8d7140               lea esi, [ecx + 0x40]
// 005a6eff  ff151c228000         call dword ptr [0x80221c]
// 005a6f05  0fb74c2412           movzx ecx, word ptr [esp + 0x12]
// 005a6f0a  0fb7542410           movzx edx, word ptr [esp + 0x10]
// 005a6f0f  0fb744240e           movzx eax, word ptr [esp + 0xe]
// 005a6f14  51                   push ecx
// 005a6f15  0fb74c2410           movzx ecx, word ptr [esp + 0x10]
// 005a6f1a  52                   push edx
// 005a6f1b  50                   push eax
// 005a6f1c  51                   push ecx
// 005a6f1d  8d542424             lea edx, [esp + 0x24]
// 005a6f21  6880418300           push 0x834180
// 005a6f26  52                   push edx
// 005a6f27  ff1530288000         call dword ptr [0x802830]
// 005a6f2d  8d44242c             lea eax, [esp + 0x2c]
// 005a6f31  50                   push eax
// 005a6f32  56                   push esi
// 005a6f33  e81835eaff           call 0x44a450
// 005a6f38  83c420               add esp, 0x20
// 005a6f3b  8bce                 mov ecx, esi
// 005a6f3d  ff15bc238000         call dword ptr [0x8023bc]
// 005a6f43  8b842418010000       mov eax, dword ptr [esp + 0x118]
// 005a6f4a  83e800               sub eax, 0
// 005a6f4d  741c                 je 0x5a6f6b
// 005a6f4f  83e801               sub eax, 1
// 005a6f52  740e                 je 0x5a6f62
// 005a6f54  83e801               sub eax, 1
// 005a6f57  7521                 jne 0x5a6f7a
// 005a6f59  8b0d28c49400         mov ecx, dword ptr [0x94c428]
// 005a6f5f  51                   push ecx
// 005a6f60  eb0f                 jmp 0x5a6f71
// 005a6f62  8b1524c49400         mov edx, dword ptr [0x94c424]
// 005a6f68  52                   push edx
// 005a6f69  eb06                 jmp 0x5a6f71
// 005a6f6b  a120c49400           mov eax, dword ptr [0x94c420]
// 005a6f70  50                   push eax
// 005a6f71  56                   push esi
// 005a6f72  e8d934eaff           call 0x44a450
// 005a6f77  83c408               add esp, 8
// 005a6f7a  8b8c241c010000       mov ecx, dword ptr [esp + 0x11c]
// 005a6f81  51                   push ecx
// 005a6f82  56                   push esi
// 005a6f83  e8c834eaff           call 0x44a450
// 005a6f88  6a0a                 push 0xa
// 005a6f8a  56                   push esi
// 005a6f8b  e8b036eaff           call 0x44a640
// 005a6f90  83c410               add esp, 0x10
// 005a6f93  8bce                 mov ecx, esi
// 005a6f95  ff15bc238000         call dword ptr [0x8023bc]
// 005a6f9b  5e                   pop esi
// 005a6f9c  81c410010000         add esp, 0x110
// 005a6fa2  c20800               ret 8

struct LocalTime {
    unsigned short year, month, dayOfWeek, day;
    unsigned short hour, minute, second, milliseconds;
};

struct Stream {};

extern "C" void (__stdcall *GetLocalTime)(LocalTime*);
extern "C" int (__cdecl *sprintf_s)(char*, unsigned int, const char*, ...);
extern "C" Stream& (__thiscall *flush)(Stream*);

Stream& __cdecl appendText(Stream*, const char*);
Stream& __cdecl appendCharacter(Stream*, char);

extern const char* prefix0;
extern const char* prefix1;
extern const char* prefix2;

struct Workspace {
    void log(int level, const char* text);
};

void Workspace::log(int level, const char* text)
{
    LocalTime time;
    char buffer[256];
    Stream* stream = reinterpret_cast<Stream*>(
        reinterpret_cast<char*>(this) + 0x40);

    GetLocalTime(&time);
    sprintf_s(buffer, 256, "%02u:%02u:%02u.%03u ",
            time.hour, time.minute, time.second, time.milliseconds);
    appendText(stream, buffer);
    flush(stream);

    switch (level) {
    case 0:
        appendText(stream, prefix0);
        break;
    case 1:
        appendText(stream, prefix1);
        break;
    case 2:
        appendText(stream, prefix2);
        break;
    }

    appendText(stream, text);
    appendCharacter(stream, '\n');
    flush(stream);
}
