// from server: 95% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005cce80  unit: RBX::P8Camera::?$GetSetImpl  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005cce80
//
// 005cce80  56                   push esi
// 005cce81  8bf1                 mov esi, ecx
// 005cce83  8b86d4010000         mov eax, dword ptr [esi + 0x1d4]
// 005cce89  83f805               cmp eax, 5
// 005cce8c  754e                 jne 0x5ccedc
// 005cce8e  8b86dc010000         mov eax, dword ptr [esi + 0x1dc]
// 005cce94  85c0                 test eax, eax
// 005cce96  743e                 je 0x5cced6
// 005cce98  6a00                 push 0
// 005cce9a  6804839400           push 0x948304
// 005cce9f  687c909200           push 0x92907c
// 005ccea4  6a00                 push 0
// 005ccea6  50                   push eax
// 005ccea7  e81a490d00           call 0x6a17c6
// 005cceac  83c414               add esp, 0x14
// 005cceaf  85c0                 test eax, eax
// 005cceb1  7423                 je 0x5cced6
// 005cceb3  8b10                 mov edx, dword ptr [eax]
// 005cceb5  d9442408             fld dword ptr [esp + 8]
// 005cceb9  8b5210               mov edx, dword ptr [edx + 0x10]
// 005ccebc  8d8ea4010000         lea ecx, [esi + 0x1a4]
// 005ccec2  51                   push ecx
// 005ccec3  81c674010000         add esi, 0x174
// 005ccec9  56                   push esi
// 005cceca  51                   push ecx
// 005ccecb  8bc8                 mov ecx, eax
// 005ccecd  d91c24               fstp dword ptr [esp]
// 005cced0  ffd2                 call edx
// 005cced2  5e                   pop esi
// 005cced3  c20400               ret 4
// 005cced6  32c0                 xor al, al
// 005cced8  5e                   pop esi
// 005cced9  c20400               ret 4
// 005ccedc  83bedc01000000       cmp dword ptr [esi + 0x1dc], 0
// 005ccee3  7420                 je 0x5ccf05
// 005ccee5  83f804               cmp eax, 4
// 005ccee8  740a                 je 0x5ccef4
// 005cceea  83f801               cmp eax, 1
// 005cceed  7405                 je 0x5ccef4
// 005cceef  83f803               cmp eax, 3
// 005ccef2  7511                 jne 0x5ccf05
// 005ccef4  d9442408             fld dword ptr [esp + 8]
// 005ccef8  51                   push ecx
// 005ccef9  d91c24               fstp dword ptr [esp]
// 005ccefc  e85ff6ffff           call 0x5cc560
// 005ccf01  5e                   pop esi
// 005ccf02  c20400               ret 4
// 005ccf05  d9442408             fld dword ptr [esp + 8]
// 005ccf09  51                   push ecx
// 005ccf0a  d91c24               fstp dword ptr [esp]
// 005ccf0d  e86ef5ffff           call 0x5cc480
// 005ccf12  5e                   pop esi
// 005ccf13  c20400               ret 4

struct Frame {
    char data[48];
};

struct Subject;

struct SubjectTable {
    void* unused[4];
    bool (__thiscall *update)(Subject*, float, Frame*, Frame*);
};

struct Subject {
    SubjectTable* table;
};

extern char instanceType;
extern char cameraSubjectType;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

struct Camera {
    char padding[0x174];
    Frame first;
    Frame second;
    int mode;
    int reserved;
    void* subject;

    bool update(float);
    bool follow(float);
    bool fallback(float);
};

bool Camera::update(float dt)
{
    if (mode == 5) {
        if (subject) {
            Subject* target = static_cast<Subject*>(
                __RTDynamicCast(subject, 0,
                                &instanceType, &cameraSubjectType, 0));
            if (target)
                return target->table->update(target, dt, &first, &second);
        }
        return false;
    }

    if (subject && (mode == 4 || mode == 1 || mode == 3))
        return follow(dt);

    return fallback(dt);
}
