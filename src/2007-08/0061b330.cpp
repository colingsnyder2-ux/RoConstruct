// from server: 100% by EspClaude
// from server: 99% by Intel
// roc 2007-08 0061b330  unit: RBX::VModelInstance::?$RefPropDescriptor  size: 472 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061b330
//
// 0061b330  8b442404             mov eax, dword ptr [esp + 4]
// 0061b334  56                   push esi
// 0061b335  8bf1                 mov esi, ecx
// 0061b337  8b08                 mov ecx, dword ptr [eax]
// 0061b339  83c1ff               add ecx, -1
// 0061b33c  83f908               cmp ecx, 8
// 0061b33f  0f879b010000         ja 0x61b4e0
// 0061b345  ff248de4b46100       jmp dword ptr [ecx*4 + 0x61b4e4]
// 0061b34c  50                   push eax
// 0061b34d  8bce                 mov ecx, esi
// 0061b34f  e83cf8ffff           call 0x61ab90
// 0061b354  85f6                 test esi, esi
// 0061b356  7412                 je 0x61b36a
// 0061b358  8d4604               lea eax, [esi + 4]
// 0061b35b  5e                   pop esi
// 0061b35c  89442404             mov dword ptr [esp + 4], eax
// 0061b360  b958818c00           mov ecx, 0x8c8158
// 0061b365  e9365be9ff           jmp 0x4b0ea0
// 0061b36a  33c0                 xor eax, eax
// 0061b36c  5e                   pop esi
// 0061b36d  89442404             mov dword ptr [esp + 4], eax
// 0061b371  b958818c00           mov ecx, 0x8c8158
// 0061b376  e9255be9ff           jmp 0x4b0ea0
// 0061b37b  50                   push eax
// 0061b37c  8bce                 mov ecx, esi
// 0061b37e  e80df8ffff           call 0x61ab90
// 0061b383  85f6                 test esi, esi
// 0061b385  7412                 je 0x61b399
// 0061b387  8d4604               lea eax, [esi + 4]
// 0061b38a  5e                   pop esi
// 0061b38b  89442404             mov dword ptr [esp + 4], eax
// 0061b38f  b97c818c00           mov ecx, 0x8c817c
// 0061b394  e9075be9ff           jmp 0x4b0ea0
// 0061b399  33c0                 xor eax, eax
// 0061b39b  5e                   pop esi
// 0061b39c  89442404             mov dword ptr [esp + 4], eax
// 0061b3a0  b97c818c00           mov ecx, 0x8c817c
// 0061b3a5  e9f65ae9ff           jmp 0x4b0ea0
// 0061b3aa  50                   push eax
// 0061b3ab  8bce                 mov ecx, esi
// 0061b3ad  e8def7ffff           call 0x61ab90
// 0061b3b2  85f6                 test esi, esi
// 0061b3b4  7412                 je 0x61b3c8
// 0061b3b6  8d4604               lea eax, [esi + 4]
// 0061b3b9  5e                   pop esi
// 0061b3ba  89442404             mov dword ptr [esp + 4], eax
// 0061b3be  b95c808c00           mov ecx, 0x8c805c
// 0061b3c3  e9d85ae9ff           jmp 0x4b0ea0
// 0061b3c8  33c0                 xor eax, eax
// 0061b3ca  5e                   pop esi
// 0061b3cb  89442404             mov dword ptr [esp + 4], eax
// 0061b3cf  b95c808c00           mov ecx, 0x8c805c
// 0061b3d4  e9c75ae9ff           jmp 0x4b0ea0
// 0061b3d9  50                   push eax
// 0061b3da  8bce                 mov ecx, esi
// 0061b3dc  e8aff7ffff           call 0x61ab90
// 0061b3e1  85f6                 test esi, esi
// 0061b3e3  7412                 je 0x61b3f7
// 0061b3e5  8d4604               lea eax, [esi + 4]
// 0061b3e8  5e                   pop esi
// 0061b3e9  89442404             mov dword ptr [esp + 4], eax
// 0061b3ed  b9b8808c00           mov ecx, 0x8c80b8
// 0061b3f2  e9a95ae9ff           jmp 0x4b0ea0
// 0061b3f7  33c0                 xor eax, eax
// 0061b3f9  5e                   pop esi
// 0061b3fa  89442404             mov dword ptr [esp + 4], eax
// 0061b3fe  b9b8808c00           mov ecx, 0x8c80b8
// 0061b403  e9985ae9ff           jmp 0x4b0ea0
// 0061b408  50                   push eax
// 0061b409  8bce                 mov ecx, esi
// 0061b40b  e880f7ffff           call 0x61ab90
// 0061b410  85f6                 test esi, esi
// 0061b412  7412                 je 0x61b426
// 0061b414  8d4604               lea eax, [esi + 4]
// 0061b417  5e                   pop esi
// 0061b418  89442404             mov dword ptr [esp + 4], eax
// 0061b41c  b9f8808c00           mov ecx, 0x8c80f8
// 0061b421  e97a5ae9ff           jmp 0x4b0ea0
// 0061b426  33c0                 xor eax, eax
// 0061b428  5e                   pop esi
// 0061b429  89442404             mov dword ptr [esp + 4], eax
// 0061b42d  b9f8808c00           mov ecx, 0x8c80f8
// 0061b432  e9695ae9ff           jmp 0x4b0ea0
// 0061b437  50                   push eax
// 0061b438  8bce                 mov ecx, esi
// 0061b43a  e851f7ffff           call 0x61ab90
// 0061b43f  85f6                 test esi, esi
// 0061b441  7412                 je 0x61b455
// 0061b443  8d4604               lea eax, [esi + 4]
// 0061b446  5e                   pop esi
// 0061b447  89442404             mov dword ptr [esp + 4], eax
// 0061b44b  b914808c00           mov ecx, 0x8c8014
// 0061b450  e94b5ae9ff           jmp 0x4b0ea0
// 0061b455  33c0                 xor eax, eax
// 0061b457  5e                   pop esi
// 0061b458  89442404             mov dword ptr [esp + 4], eax
// 0061b45c  b914808c00           mov ecx, 0x8c8014
// 0061b461  e93a5ae9ff           jmp 0x4b0ea0
// 0061b466  85f6                 test esi, esi
// 0061b468  7412                 je 0x61b47c
// 0061b46a  8d4604               lea eax, [esi + 4]
// 0061b46d  5e                   pop esi
// 0061b46e  89442404             mov dword ptr [esp + 4], eax
// 0061b472  b9bc818c00           mov ecx, 0x8c81bc
// 0061b477  e9245ae9ff           jmp 0x4b0ea0
// 0061b47c  33c0                 xor eax, eax
// 0061b47e  5e                   pop esi
// 0061b47f  89442404             mov dword ptr [esp + 4], eax
// 0061b483  b9bc818c00           mov ecx, 0x8c81bc
// 0061b488  e9135ae9ff           jmp 0x4b0ea0
// 0061b48d  85f6                 test esi, esi
// 0061b48f  7412                 je 0x61b4a3
// 0061b491  8d4604               lea eax, [esi + 4]
// 0061b494  5e                   pop esi
// 0061b495  89442404             mov dword ptr [esp + 4], eax
// 0061b499  b938808c00           mov ecx, 0x8c8038
// 0061b49e  e9fd59e9ff           jmp 0x4b0ea0
// 0061b4a3  33c0                 xor eax, eax
// 0061b4a5  5e                   pop esi
// 0061b4a6  89442404             mov dword ptr [esp + 4], eax
// 0061b4aa  b938808c00           mov ecx, 0x8c8038
// 0061b4af  e9ec59e9ff           jmp 0x4b0ea0
// 0061b4b4  85f6                 test esi, esi
// 0061b4b6  7405                 je 0x61b4bd
// 0061b4b8  83c604               add esi, 4
// 0061b4bb  eb02                 jmp 0x61b4bf
// 0061b4bd  33f6                 xor esi, esi
// 0061b4bf  0fb64008             movzx eax, byte ptr [eax + 8]
// 0061b4c3  83ec1c               sub esp, 0x1c
// 0061b4c6  8bcc                 mov ecx, esp
// 0061b4c8  89642424             mov dword ptr [esp + 0x24], esp
// 0061b4cc  50                   push eax
// 0061b4cd  6a01                 push 1
// 0061b4cf  ff1568e47700         call dword ptr [0x77e468]
// 0061b4d5  56                   push esi
// 0061b4d6  b9fc818c00           mov ecx, 0x8c81fc
// 0061b4db  e8a019e1ff           call 0x42ce80
// 0061b4e0  5e                   pop esi
// 0061b4e1  c20400               ret 4
// 0061b4e4  08b4610037b461       or byte ptr [ecx + 0x61b43700], dh
// 0061b4eb  00aab36100d9         add byte ptr [edx - 0x26ff9e4d], ch
// 0061b4f1  b361                 mov bl, 0x61
// 0061b4f3  004cb361             add byte ptr [ebx + esi*4 + 0x61], cl
// 0061b4f7  007bb3               add byte ptr [ebx - 0x4d], bh
// 0061b4fa  61                   popal 
// 0061b4fb  0066b4               add byte ptr [esi - 0x4c], ah
// 0061b4fe  61                   popal 
// 0061b4ff  008db46100b4         add byte ptr [ebp - 0x4bff9e4c], cl
// 0061b505  b461                 mov ah, 0x61

// 2007-08 hand variant of 0061b330 (RBX::Mouse::onEvent):
// the target's jump table spans eventType 1..9 (add ecx,-1 ; cmp ecx,8 ; ja default), so the
// keyboard event must be the switch DEFAULT, not "case 10".
// Pad14 has no data payload here: DescribedBase sits at +4, not +0x14.
#include <string>
namespace RBX {
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); };
template<class Sig> class SignalDesc {
public:
    void fireEvent(DescribedBase* instance) const;
};
template<class Sig> class SignalDesc1 {
public:
    void fireEvent(DescribedBase* instance, std::string arg) const;
};
}
struct UIEvent {
    int eventType;
    int a;
    unsigned char key;
    int b, c;
};
struct Pad14 { virtual ~Pad14(); };
extern const Reflection::SignalDesc<void(int)> event_1;
extern const Reflection::SignalDesc<void(int)> event_2;
extern const Reflection::SignalDesc<void(int)> event_3;
extern const Reflection::SignalDesc<void(int)> event_4;
extern const Reflection::SignalDesc<void(int)> event_5;
extern const Reflection::SignalDesc<void(int)> event_6;
extern const Reflection::SignalDesc<void(int)> event_7;
extern const Reflection::SignalDesc<void(int)> event_8;
extern const Reflection::SignalDesc1<void(std::string)> event_key;
class Mouse : public Pad14, public Reflection::DescribedBase {
public:
    void update(const UIEvent& event);
    void onEvent(const UIEvent& event);
};
void Mouse::onEvent(const UIEvent& event)
{
    switch (event.eventType)
    {
    case 5: update(event); event_5.fireEvent(this); break;
    case 6: update(event); event_6.fireEvent(this); break;
    case 3: update(event); event_3.fireEvent(this); break;
    case 4: update(event); event_4.fireEvent(this); break;
    case 1: update(event); event_1.fireEvent(this); break;
    case 2: update(event); event_2.fireEvent(this); break;
    case 7: event_7.fireEvent(this); break;
    case 8: event_8.fireEvent(this); break;
    case 9: event_key.fireEvent(this, std::string(1, event.key)); break;
    default: break;
    }
}
}
