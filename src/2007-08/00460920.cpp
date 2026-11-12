// from server: 100% by EspClaude
// from server: 52% by colin
// roc 2007-08 00460920  unit: CScriptDoc  size: 312 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00460920
//
// 00460920  6aff                 push -1
// 00460922  68da277400           push 0x7427da
// 00460927  64a100000000         mov eax, dword ptr fs:[0]
// 0046092d  50                   push eax
// 0046092e  83ec28               sub esp, 0x28
// 00460931  55                   push ebp
// 00460932  56                   push esi
// 00460933  57                   push edi
// 00460934  a188518b00           mov eax, dword ptr [0x8b5188]
// 00460939  33c4                 xor eax, esp
// 0046093b  50                   push eax
// 0046093c  8d442438             lea eax, [esp + 0x38]
// 00460940  64a300000000         mov dword ptr fs:[0], eax
// 00460946  8bf1                 mov esi, ecx
// 00460948  6a01                 push 1
// 0046094a  e8e1c8ffff           call 0x45d230
// 0046094f  8bc8                 mov ecx, eax
// 00460951  e87abfffff           call 0x45c8d0
// 00460956  85c0                 test eax, eax
// 00460958  0f84e7000000         je 0x460a45
// 0046095e  80be4401000000       cmp byte ptr [esi + 0x144], 0
// 00460965  0f85da000000         jne 0x460a45
// 0046096b  83be3401000000       cmp dword ptr [esi + 0x134], 0
// 00460972  0f84bd000000         je 0x460a35
// 00460978  8bbe28010000         mov edi, dword ptr [esi + 0x128]
// 0046097e  8bcf                 mov ecx, edi
// 00460980  897c2414             mov dword ptr [esp + 0x14], edi
// 00460984  e8c74d2c00           call 0x725750
// 00460989  c644241801           mov byte ptr [esp + 0x18], 1
// 0046098e  6a01                 push 1
// 00460990  8bce                 mov ecx, esi
// 00460992  c744244400000000     mov dword ptr [esp + 0x44], 0
// 0046099a  e891c8ffff           call 0x45d230
// 0046099f  8bc8                 mov ecx, eax
// 004609a1  e87ac3ffff           call 0x45cd20
// 004609a6  8d4c2410             lea ecx, [esp + 0x10]
// 004609aa  8be8                 mov ebp, eax
// 004609ac  ff15acdd7700         call dword ptr [0x77ddac]
// 004609b2  6a01                 push 1
// 004609b4  83c501               add ebp, 1
// 004609b7  55                   push ebp
// 004609b8  8d4c2418             lea ecx, [esp + 0x18]
// 004609bc  c644244801           mov byte ptr [esp + 0x48], 1
// 004609c1  ff1560d57700         call dword ptr [0x77d560]
// 004609c7  50                   push eax
// 004609c8  55                   push ebp
// 004609c9  8bce                 mov ecx, esi
// 004609cb  e860c8ffff           call 0x45d230
// 004609d0  8bc8                 mov ecx, eax
// 004609d2  e8f9c2ffff           call 0x45ccd0
// 004609d7  6aff                 push -1
// 004609d9  8d4c2414             lea ecx, [esp + 0x14]
// 004609dd  ff155cd57700         call dword ptr [0x77d55c]
// 004609e3  8d4c2410             lea ecx, [esp + 0x10]
// 004609e7  ff1598dd7700         call dword ptr [0x77dd98]
// 004609ed  50                   push eax
// 004609ee  8d4c2420             lea ecx, [esp + 0x20]
// 004609f2  ff1598e67700         call dword ptr [0x77e698]
// 004609f8  8b8e34010000         mov ecx, dword ptr [esi + 0x134]
// 004609fe  8d44241c             lea eax, [esp + 0x1c]
// 00460a02  50                   push eax
// 00460a03  c644244402           mov byte ptr [esp + 0x44], 2
// 00460a08  e833d40d00           call 0x53de40
// 00460a0d  8d4c241c             lea ecx, [esp + 0x1c]
// 00460a11  c644244001           mov byte ptr [esp + 0x40], 1
// 00460a16  ff15ace67700         call dword ptr [0x77e6ac]
// 00460a1c  8d4c2410             lea ecx, [esp + 0x10]
// 00460a20  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00460a26  8bcf                 mov ecx, edi
// 00460a28  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 00460a30  e83b4d2c00           call 0x725770
// 00460a35  6a01                 push 1
// 00460a37  8bce                 mov ecx, esi
// 00460a39  e8f2c7ffff           call 0x45d230
// 00460a3e  8bc8                 mov ecx, eax
// 00460a40  e82bb6ffff           call 0x45c070
// 00460a45  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00460a49  64890d00000000       mov dword ptr fs:[0], ecx
// 00460a50  59                   pop ecx
// 00460a51  5f                   pop edi
// 00460a52  5e                   pop esi

#include <string>

// MFC80 imports by ordinal: 310 CStringT(), 2468 GetBuffer(int), 5403 ReleaseBuffer(int),
// 876 operator const char*, 578 ~CStringT
class __declspec(dllimport) CSimpleStringA {
public:
    char* GetBuffer(int nMinBufferLength);
    void ReleaseBuffer(int nNewLength = -1);
    operator const char*() const;
private:
    char* m_pszData;
};

class __declspec(dllimport) CStringA : public CSimpleStringA {
public:
    CStringA();
    ~CStringA() throw();
};

struct Mutex {
    void do_lock();
    void do_unlock();
};

struct ScopedLock {
    Mutex* m;
    bool locked;
    explicit ScopedLock(Mutex& mx) : m(&mx), locked(false) { m->do_lock(); locked = true; }
    ~ScopedLock() { if (locked) m->do_unlock(); }
};

struct ScriptCtrl {
    int GetModify(int bDirect = 1);                         // 0x45c8d0
    int GetLength(int bDirect = 1);                         // 0x45cd20
    void GetText(int length, char* text, int bDirect = 1);  // 0x45ccd0
    void SetSavePoint(int bDirect = 1);                     // 0x45c070
};

struct ScriptTarget {
    void setSource(const std::string& source); // 0x53de40
};

struct CScriptDoc {
    char pad0[0x128];
    Mutex* mutex;            // +0x128
    char pad12c[0x134 - 0x12c];
    ScriptTarget* target;    // +0x134
    char pad138[0x144 - 0x138];
    bool busy;               // +0x144

    ScriptCtrl* GetCtrl();   // 0x45d230
    void commit();
};

void CScriptDoc::commit()
{
    if (GetCtrl()->GetModify() && !busy) {
        if (target) {
            ScopedLock lock(*mutex);
            int length = GetCtrl()->GetLength();
            CStringA text;
            GetCtrl()->GetText(length + 1, text.GetBuffer(length + 1));
            text.ReleaseBuffer();
            target->setSource((const char*)text);
        }
        GetCtrl()->SetSavePoint();
    }
}
