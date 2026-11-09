// from server: 100% by EspClaude
// from server: 80% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_4c227f07be7ebc39.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <string>
// from server: 79% by colin
// roc 2008-06 00603730  unit: RBX::UnifiedImageWidget  size: 496 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00603730
//
// 00603730  6aff                 push -1
// 00603732  68c3857d00           push 0x7d85c3
// 00603737  64a100000000         mov eax, dword ptr fs:[0]
// 0060373d  50                   push eax
// 0060373e  64892500000000       mov dword ptr fs:[0], esp
// 00603745  83ec50               sub esp, 0x50
// 00603748  53                   push ebx
// 00603749  56                   push esi
// 0060374a  57                   push edi
// 0060374b  83ec08               sub esp, 8
// 0060374e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00603756  d90534c48100         fld dword ptr [0x81c434]
// 0060375c  8bc4                 mov eax, esp
// 0060375e  d918                 fstp dword ptr [eax]
// 00603760  89642418             mov dword ptr [esp + 0x18], esp
// 00603764  d90528248400         fld dword ptr [0x842428]
// 0060376a  bb01000000           mov ebx, 1
// 0060376f  53                   push ebx
// 00603770  d95804               fstp dword ptr [eax + 4]
// 00603773  8d442428             lea eax, [esp + 0x28]
// 00603777  6a02                 push 2
// 00603779  50                   push eax
// 0060377a  8bf1                 mov esi, ecx
// 0060377c  e85feaffff           call 0x6021e0
// 00603781  83c414               add esp, 0x14
// 00603784  6818248400           push 0x842418
// 00603789  8d4c2428             lea ecx, [esp + 0x28]
// 0060378d  895c2468             mov dword ptr [esp + 0x68], ebx
// 00603791  ff1558248000         call dword ptr [0x802458]
// 00603797  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0060379b  8b11                 mov edx, dword ptr [ecx]
// 0060379d  8b5204               mov edx, dword ptr [edx + 4]
// 006037a0  8d442424             lea eax, [esp + 0x24]
// 006037a4  50                   push eax
// 006037a5  c644246802           mov byte ptr [esp + 0x68], 2
// 006037aa  ffd2                 call edx
// 006037ac  8d4c2424             lea ecx, [esp + 0x24]
// 006037b0  885c2464             mov byte ptr [esp + 0x64], bl
// 006037b4  ff1568248000         call dword ptr [0x802468]
// 006037ba  8b442470             mov eax, dword ptr [esp + 0x70]
// 006037be  68a42b8200           push 0x822ba4
// 006037c3  50                   push eax
// 006037c4  8d4c241c             lea ecx, [esp + 0x1c]
// 006037c8  51                   push ecx
// 006037c9  e8b2eaffff           call 0x602280
// 006037ce  8b542420             mov edx, dword ptr [esp + 0x20]
// 006037d2  83c404               add esp, 4
// 006037d5  8bc4                 mov eax, esp
// 006037d7  8910                 mov dword ptr [eax], edx
// 006037d9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006037dd  894804               mov dword ptr [eax + 4], ecx
// 006037e0  8b442420             mov eax, dword ptr [esp + 0x20]
// 006037e4  c644246c03           mov byte ptr [esp + 0x6c], 3
// 006037e9  89642478             mov dword ptr [esp + 0x78], esp
// 006037ed  85c0                 test eax, eax
// 006037ef  7409                 je 0x6037fa
// 006037f1  83c004               add eax, 4
// 006037f4  8bd3                 mov edx, ebx
// 006037f6  f00fc110             lock xadd dword ptr [eax], edx
// 006037fa  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006037fe  e80dd7ffff           call 0x600f10
// 00603803  e878500500           call 0x658880
// 00603808  8b38                 mov edi, dword ptr [eax]
// 0060380a  6816b78000           push 0x80b716
// 0060380f  8d4c2444             lea ecx, [esp + 0x44]
// 00603813  ff1558248000         call dword ptr [0x802458]
// 00603819  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0060381d  83ec08               sub esp, 8
// 00603820  8bc4                 mov eax, esp
// 00603822  8908                 mov dword ptr [eax], ecx
// 00603824  8b542420             mov edx, dword ptr [esp + 0x20]
// 00603828  895004               mov dword ptr [eax + 4], edx
// 0060382b  8b442420             mov eax, dword ptr [esp + 0x20]
// 0060382f  89642478             mov dword ptr [esp + 0x78], esp
// 00603833  85c0                 test eax, eax
// 00603835  7409                 je 0x603840
// 00603837  83c004               add eax, 4
// 0060383a  8bcb                 mov ecx, ebx
// 0060383c  f00fc108             lock xadd dword ptr [eax], ecx
// 00603840  83ec1c               sub esp, 0x1c
// 00603843  8d542464             lea edx, [esp + 0x64]
// 00603847  8bcc                 mov ecx, esp
// 00603849  89642434             mov dword ptr [esp + 0x34], esp
// 0060384d  52                   push edx
// 0060384e  c684248c00000005     mov byte ptr [esp + 0x8c], 5
// 00603856  ff155c248000         call dword ptr [0x80245c]
// 0060385c  57                   push edi
// 0060385d  8bce                 mov ecx, esi
// 0060385f  c684248c00000004     mov byte ptr [esp + 0x8c], 4
// 00603867  e864fcffff           call 0x6034d0
// 0060386c  8b7c246c             mov edi, dword ptr [esp + 0x6c]
// 00603870  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00603874  8907                 mov dword ptr [edi], eax
// 00603876  8b442420             mov eax, dword ptr [esp + 0x20]
// 0060387a  894704               mov dword ptr [edi + 4], eax
// 0060387d  85c0                 test eax, eax
// 0060387f  7409                 je 0x60388a
// 00603881  83c004               add eax, 4
// 00603884  8bcb                 mov ecx, ebx
// 00603886  f00fc108             lock xadd dword ptr [eax], ecx
// 0060388a  8d4c2440             lea ecx, [esp + 0x40]
// 0060388e  895c240c             mov dword ptr [esp + 0xc], ebx
// 00603892  c644246403           mov byte ptr [esp + 0x64], 3
// 00603897  ff1568248000         call dword ptr [0x802468]
// 0060389d  8b742418             mov esi, dword ptr [esp + 0x18]
// 006038a1  885c2464             mov byte ptr [esp + 0x64], bl
// 006038a5  85f6                 test esi, esi
// 006038a7  742a                 je 0x6038d3
// 006038a9  8d5604               lea edx, [esi + 4]
// 006038ac  83c8ff               or eax, 0xffffffff
// 006038af  f00fc102             lock xadd dword ptr [edx], eax
// 006038b3  751e                 jne 0x6038d3
// 006038b5  8b16                 mov edx, dword ptr [esi]
// 006038b7  8b4204               mov eax, dword ptr [edx + 4]
// 006038ba  8bce                 mov ecx, esi
// 006038bc  ffd0                 call eax
// 006038be  8d4e08               lea ecx, [esi + 8]
// 006038c1  83caff               or edx, 0xffffffff
// 006038c4  f00fc111             lock xadd dword ptr [ecx], edx
// 006038c8  7509                 jne 0x6038d3
// 006038ca  8b06                 mov eax, dword ptr [esi]
// 006038cc  8b5008               mov edx, dword ptr [eax + 8]
// 006038cf  8bce                 mov ecx, esi
// 006038d1  ffd2                 call edx
// 006038d3  8b742420             mov esi, dword ptr [esp + 0x20]
// 006038d7  c644246400           mov byte ptr [esp + 0x64], 0
// 006038dc  85f6                 test esi, esi
// 006038de  742a                 je 0x60390a
// 006038e0  8d4604               lea eax, [esi + 4]
// 006038e3  83c9ff               or ecx, 0xffffffff
// 006038e6  f00fc108             lock xadd dword ptr [eax], ecx
// 006038ea  751e                 jne 0x60390a
// 006038ec  8b16                 mov edx, dword ptr [esi]
// 006038ee  8b4204               mov eax, dword ptr [edx + 4]
// 006038f1  8bce                 mov ecx, esi
// 006038f3  ffd0                 call eax
// 006038f5  8d4e08               lea ecx, [esi + 8]
// 006038f8  83caff               or edx, 0xffffffff
// 006038fb  f00fc111             lock xadd dword ptr [ecx], edx
// 006038ff  7509                 jne 0x60390a
// 00603901  8b06                 mov eax, dword ptr [esi]
// 00603903  8b5008               mov edx, dword ptr [eax + 8]
// 00603906  8bce                 mov ecx, esi
// 00603908  ffd2                 call edx
// 0060390a  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0060390e  8bc7                 mov eax, edi
// 00603910  5f                   pop edi
// 00603911  5e                   pop esi
// 00603912  64890d00000000       mov dword ptr fs:[0], ecx
// 00603919  5b                   pop ebx
// 0060391a  83c45c               add esp, 0x5c
// 0060391d  c20800               ret 8

// from server: 78% by king_originala
// roc 2008-06 00603730  unit: RBX::UnifiedImageWidget  size: 496 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00603730
//
// 00603730  6aff                 push -1
// 00603732  68c3857d00           push 0x7d85c3
// 00603737  64a100000000         mov eax, dword ptr fs:[0]
// 0060373d  50                   push eax
// 0060373e  64892500000000       mov dword ptr fs:[0], esp
// 00603745  83ec50               sub esp, 0x50
// 00603748  53                   push ebx
// 00603749  56                   push esi
// 0060374a  57                   push edi
// 0060374b  83ec08               sub esp, 8
// 0060374e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00603756  d90534c48100         fld dword ptr [0x81c434]
// 0060375c  8bc4                 mov eax, esp
// 0060375e  d918                 fstp dword ptr [eax]
// 00603760  89642418             mov dword ptr [esp + 0x18], esp
// 00603764  d90528248400         fld dword ptr [0x842428]
// 0060376a  bb01000000           mov ebx, 1
// 0060376f  53                   push ebx
// 00603770  d95804               fstp dword ptr [eax + 4]
// 00603773  8d442428             lea eax, [esp + 0x28]
// 00603777  6a02                 push 2
// 00603779  50                   push eax
// 0060377a  8bf1                 mov esi, ecx
// 0060377c  e85feaffff           call 0x6021e0
// 00603781  83c414               add esp, 0x14
// 00603784  6818248400           push 0x842418
// 00603789  8d4c2428             lea ecx, [esp + 0x28]
// 0060378d  895c2468             mov dword ptr [esp + 0x68], ebx
// 00603791  ff1558248000         call dword ptr [0x802458]
// 00603797  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0060379b  8b11                 mov edx, dword ptr [ecx]
// 0060379d  8b5204               mov edx, dword ptr [edx + 4]
// 006037a0  8d442424             lea eax, [esp + 0x24]
// 006037a4  50                   push eax
// 006037a5  c644246802           mov byte ptr [esp + 0x68], 2
// 006037aa  ffd2                 call edx
// 006037ac  8d4c2424             lea ecx, [esp + 0x24]
// 006037b0  885c2464             mov byte ptr [esp + 0x64], bl
// 006037b4  ff1568248000         call dword ptr [0x802468]
// 006037ba  8b442470             mov eax, dword ptr [esp + 0x70]
// 006037be  68a42b8200           push 0x822ba4
// 006037c3  50                   push eax
// 006037c4  8d4c241c             lea ecx, [esp + 0x1c]
// 006037c8  51                   push ecx
// 006037c9  e8b2eaffff           call 0x602280
// 006037ce  8b542420             mov edx, dword ptr [esp + 0x20]
// 006037d2  83c404               add esp, 4
// 006037d5  8bc4                 mov eax, esp
// 006037d7  8910                 mov dword ptr [eax], edx
// 006037d9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006037dd  894804               mov dword ptr [eax + 4], ecx
// 006037e0  8b442420             mov eax, dword ptr [esp + 0x20]
// 006037e4  c644246c03           mov byte ptr [esp + 0x6c], 3
// 006037e9  89642478             mov dword ptr [esp + 0x78], esp
// 006037ed  85c0                 test eax, eax
// 006037ef  7409                 je 0x6037fa
// 006037f1  83c004               add eax, 4
// 006037f4  8bd3                 mov edx, ebx
// 006037f6  f00fc110             lock xadd dword ptr [eax], edx
// 006037fa  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006037fe  e80dd7ffff           call 0x600f10
// 00603803  e878500500           call 0x658880
// 00603808  8b38                 mov edi, dword ptr [eax]
// 0060380a  6816b78000           push 0x80b716
// 0060380f  8d4c2444             lea ecx, [esp + 0x44]
// 00603813  ff1558248000         call dword ptr [0x802458]
// 00603819  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0060381d  83ec08               sub esp, 8
// 00603820  8bc4                 mov eax, esp
// 00603822  8908                 mov dword ptr [eax], ecx
// 00603824  8b542420             mov edx, dword ptr [esp + 0x20]
// 00603828  895004               mov dword ptr [eax + 4], edx
// 0060382b  8b442420             mov eax, dword ptr [esp + 0x20]
// 0060382f  89642478             mov dword ptr [esp + 0x78], esp
// 00603833  85c0                 test eax, eax
// 00603835  7409                 je 0x603840
// 00603837  83c004               add eax, 4
// 0060383a  8bcb                 mov ecx, ebx
// 0060383c  f00fc108             lock xadd dword ptr [eax], ecx
// 00603840  83ec1c               sub esp, 0x1c
// 00603843  8d542464             lea edx, [esp + 0x64]
// 00603847  8bcc                 mov ecx, esp
// 00603849  89642434             mov dword ptr [esp + 0x34], esp
// 0060384d  52                   push edx
// 0060384e  c684248c00000005     mov byte ptr [esp + 0x8c], 5
// 00603856  ff155c248000         call dword ptr [0x80245c]
// 0060385c  57                   push edi
// 0060385d  8bce                 mov ecx, esi
// 0060385f  c684248c00000004     mov byte ptr [esp + 0x8c], 4
// 00603867  e864fcffff           call 0x6034d0
// 0060386c  8b7c246c             mov edi, dword ptr [esp + 0x6c]
// 00603870  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00603874  8907                 mov dword ptr [edi], eax
// 00603876  8b442420             mov eax, dword ptr [esp + 0x20]
// 0060387a  894704               mov dword ptr [edi + 4], eax
// 0060387d  85c0                 test eax, eax
// 0060387f  7409                 je 0x60388a
// 00603881  83c004               add eax, 4
// 00603884  8bcb                 mov ecx, ebx
// 00603886  f00fc108             lock xadd dword ptr [eax], ecx
// 0060388a  8d4c2440             lea ecx, [esp + 0x40]
// 0060388e  895c240c             mov dword ptr [esp + 0xc], ebx
// 00603892  c644246403           mov byte ptr [esp + 0x64], 3
// 00603897  ff1568248000         call dword ptr [0x802468]
// 0060389d  8b742418             mov esi, dword ptr [esp + 0x18]
// 006038a1  885c2464             mov byte ptr [esp + 0x64], bl
// 006038a5  85f6                 test esi, esi
// 006038a7  742a                 je 0x6038d3
// 006038a9  8d5604               lea edx, [esi + 4]
// 006038ac  83c8ff               or eax, 0xffffffff
// 006038af  f00fc102             lock xadd dword ptr [edx], eax
// 006038b3  751e                 jne 0x6038d3
// 006038b5  8b16                 mov edx, dword ptr [esi]
// 006038b7  8b4204               mov eax, dword ptr [edx + 4]
// 006038ba  8bce                 mov ecx, esi
// 006038bc  ffd0                 call eax
// 006038be  8d4e08               lea ecx, [esi + 8]
// 006038c1  83caff               or edx, 0xffffffff
// 006038c4  f00fc111             lock xadd dword ptr [ecx], edx
// 006038c8  7509                 jne 0x6038d3
// 006038ca  8b06                 mov eax, dword ptr [esi]
// 006038cc  8b5008               mov edx, dword ptr [eax + 8]
// 006038cf  8bce                 mov ecx, esi
// 006038d1  ffd2                 call edx
// 006038d3  8b742420             mov esi, dword ptr [esp + 0x20]
// 006038d7  c644246400           mov byte ptr [esp + 0x64], 0
// 006038dc  85f6                 test esi, esi
// 006038de  742a                 je 0x60390a
// 006038e0  8d4604               lea eax, [esi + 4]
// 006038e3  83c9ff               or ecx, 0xffffffff
// 006038e6  f00fc108             lock xadd dword ptr [eax], ecx
// 006038ea  751e                 jne 0x60390a
// 006038ec  8b16                 mov edx, dword ptr [esi]
// 006038ee  8b4204               mov eax, dword ptr [edx + 4]
// 006038f1  8bce                 mov ecx, esi
// 006038f3  ffd0                 call eax
// 006038f5  8d4e08               lea ecx, [esi + 8]
// 006038f8  83caff               or edx, 0xffffffff
// 006038fb  f00fc111             lock xadd dword ptr [ecx], edx
// 006038ff  7509                 jne 0x60390a
// 00603901  8b06                 mov eax, dword ptr [esi]
// 00603903  8b5008               mov edx, dword ptr [eax + 8]
// 00603906  8bce                 mov ecx, esi
// 00603908  ffd2                 call edx
// 0060390a  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0060390e  8bc7                 mov eax, edi
// 00603910  5f                   pop edi
// 00603911  5e                   pop esi
// 00603912  64890d00000000       mov dword ptr fs:[0], ecx
// 00603919  5b                   pop ebx
// 0060391a  83c45c               add esp, 0x5c
// 0060391d  c20800               ret 8

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

typedef std::string String;
struct Object;
typedef boost::shared_ptr<Object> Shared;

struct Object {
    virtual void unused() = 0;
    virtual void setName(const String&) = 0;
    void setParent(Shared);
};

struct Vector2 {
    float x, y;
    Vector2(const float&, const float&);
    Vector2(const Vector2& o) : x(o.x), y(o.y) {}
    ~Vector2() {}
};

inline Vector2::Vector2(const float& a, const float& b) : x(a), y(b) {}

extern const float initialX;
extern const float initialY;
extern const char objectName[];
extern const char lookupName[];
extern const char imageName[];

extern Shared __cdecl createObject(int, bool, Vector2);
extern Shared __cdecl findObject(void*, const char*);
extern int* __cdecl getContext();

struct S {
    Shared f(void*);
    void configure(int, String, Shared);
};

Shared S::f(void* p)
{
    Shared result = createObject(2, true, Vector2(initialX, initialY));
    { String name(objectName); result->setName(name); }
    Shared parent = findObject(p, lookupName);
    result->setParent(parent);
    int context = *getContext();
    String image(imageName);
    configure(context, image, parent);
    return Shared(result);
}

