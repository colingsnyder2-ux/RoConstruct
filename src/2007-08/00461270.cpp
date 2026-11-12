// from server: 65% by EspClaude
// from server: 48% by colin
// roc 2007-08 00461270  unit: CScriptEditor  size: 496 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00461270
//
// 00461270  55                   push ebp
// 00461271  8bec                 mov ebp, esp
// 00461273  6aff                 push -1
// 00461275  6876297400           push 0x742976
// 0046127a  64a100000000         mov eax, dword ptr fs:[0]
// 00461280  50                   push eax
// 00461281  81ecb8000000         sub esp, 0xb8
// 00461287  53                   push ebx
// 00461288  56                   push esi
// 00461289  57                   push edi
// 0046128a  a188518b00           mov eax, dword ptr [0x8b5188]
// 0046128f  33c5                 xor eax, ebp
// 00461291  50                   push eax
// 00461292  8d45f4               lea eax, [ebp - 0xc]
// 00461295  64a300000000         mov dword ptr fs:[0], eax
// 0046129b  8965f0               mov dword ptr [ebp - 0x10], esp
// 0046129e  8bf1                 mov esi, ecx
// 004612a0  8975e8               mov dword ptr [ebp - 0x18], esi
// 004612a3  837e2000             cmp dword ptr [esi + 0x20], 0
// 004612a7  0f844e020000         je 0x4614fb
// 004612ad  83be3401000000       cmp dword ptr [esi + 0x134], 0
// 004612b4  c6864401000001       mov byte ptr [esi + 0x144], 1
// 004612bb  0f8410020000         je 0x4614d1
// 004612c1  8b9e28010000         mov ebx, dword ptr [esi + 0x128]
// 004612c7  8bcb                 mov ecx, ebx
// 004612c9  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004612d0  895ddc               mov dword ptr [ebp - 0x24], ebx
// 004612d3  c645e000             mov byte ptr [ebp - 0x20], 0
// 004612d7  e874442c00           call 0x725750
// 004612dc  c645e001             mov byte ptr [ebp - 0x20], 1
// 004612e0  8b8634010000         mov eax, dword ptr [esi + 0x134]
// 004612e6  8d88f0000000         lea ecx, [eax + 0xf0]
// 004612ec  c645fc01             mov byte ptr [ebp - 4], 1
// 004612f0  ff154ce67700         call dword ptr [0x77e64c]
// 004612f6  85c0                 test eax, eax
// 004612f8  0f94c0               sete al
// 004612fb  888646010000         mov byte ptr [esi + 0x146], al
// 00461301  84c0                 test al, al
// 00461303  8b8634010000         mov eax, dword ptr [esi + 0x134]
// 00461309  7424                 je 0x46132f
// 0046130b  8b88e8000000         mov ecx, dword ptr [eax + 0xe8]
// 00461311  ff15a8e67700         call dword ptr [0x77e6a8]
// 00461317  8bce                 mov ecx, esi
// 00461319  8bf8                 mov edi, eax
// 0046131b  e810bfffff           call 0x45d230
// 00461320  6a01                 push 1
// 00461322  57                   push edi
// 00461323  8bc8                 mov ecx, eax
// 00461325  e866b9ffff           call 0x45cc90
// 0046132a  e9ee000000           jmp 0x46141d
// 0046132f  83ec20               sub esp, 0x20
// 00461332  8bdc                 mov ebx, esp
// 00461334  8db8f0000000         lea edi, [eax + 0xf0]
// 0046133a  8965e4               mov dword ptr [ebp - 0x1c], esp
// 0046133d  57                   push edi
// 0046133e  8bcb                 mov ecx, ebx
// 00461340  ff159ce67700         call dword ptr [0x77e69c]
// 00461346  8b471c               mov eax, dword ptr [edi + 0x1c]
// 00461349  89431c               mov dword ptr [ebx + 0x1c], eax
// 0046134c  c645fc02             mov byte ptr [ebp - 4], 2
// 00461350  e8eb73faff           call 0x408740
// 00461355  8d4dec               lea ecx, [ebp - 0x14]
// 00461358  51                   push ecx
// 00461359  8bc8                 mov ecx, eax
// 0046135b  c645fc01             mov byte ptr [ebp - 4], 1
// 0046135f  e82c7b0e00           call 0x548e90
// 00461364  8b10                 mov edx, dword ptr [eax]
// 00461366  8bfa                 mov edi, edx
// 00461368  c70000000000         mov dword ptr [eax], 0
// 0046136e  897de4               mov dword ptr [ebp - 0x1c], edi
// 00461371  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00461374  85c0                 test eax, eax
// 00461376  c645fc03             mov byte ptr [ebp - 4], 3
// 0046137a  7410                 je 0x46138c
// 0046137c  8b08                 mov ecx, dword ptr [eax]
// 0046137e  8b5104               mov edx, dword ptr [ecx + 4]
// 00461381  8d0c02               lea ecx, [edx + eax]
// 00461384  8b01                 mov eax, dword ptr [ecx]
// 00461386  8b10                 mov edx, dword ptr [eax]
// 00461388  6a01                 push 1
// 0046138a  ffd2                 call edx
// 0046138c  6a01                 push 1
// 0046138e  6a02                 push 2
// 00461390  8d8d3cffffff         lea ecx, [ebp - 0xc4]
// 00461396  ff157ce67700         call dword ptr [0x77e67c]
// 0046139c  6800100000           push 0x1000
// 004613a1  8d853cffffff         lea eax, [ebp - 0xc4]
// 004613a7  50                   push eax
// 004613a8  57                   push edi
// 004613a9  c645fc04             mov byte ptr [ebp - 4], 4
// 004613ad  e85edffeff           call 0x44f310
// 004613b2  83c40c               add esp, 0xc
// 004613b5  8d4dbc               lea ecx, [ebp - 0x44]
// 004613b8  51                   push ecx
// 004613b9  8d8d3cffffff         lea ecx, [ebp - 0xc4]
// 004613bf  ff1580e67700         call dword ptr [0x77e680]
// 004613c5  8bc8                 mov ecx, eax
// 004613c7  c645fc05             mov byte ptr [ebp - 4], 5
// 004613cb  ff15a8e67700         call dword ptr [0x77e6a8]
// 004613d1  8bce                 mov ecx, esi
// 004613d3  8bd8                 mov ebx, eax
// 004613d5  e856beffff           call 0x45d230
// 004613da  6a01                 push 1
// 004613dc  53                   push ebx
// 004613dd  8bc8                 mov ecx, eax
// 004613df  e8acb8ffff           call 0x45cc90
// 004613e4  8d4dbc               lea ecx, [ebp - 0x44]
// 004613e7  c645fc04             mov byte ptr [ebp - 4], 4
// 004613eb  ff15ace67700         call dword ptr [0x77e6ac]
// 004613f1  8d8d3cffffff         lea ecx, [ebp - 0xc4]
// 004613f7  c645fc03             mov byte ptr [ebp - 4], 3
// 004613fb  ff1584e67700         call dword ptr [0x77e684]
// 00461401  85ff                 test edi, edi
// 00461403  c645fc01             mov byte ptr [ebp - 4], 1
// 00461407  7411                 je 0x46141a
// 00461409  8b17                 mov edx, dword ptr [edi]
// 0046140b  8b4204               mov eax, dword ptr [edx + 4]
// 0046140e  8b1438               mov edx, dword ptr [eax + edi]
// 00461411  8d0c38               lea ecx, [eax + edi]
// 00461414  8b02                 mov eax, dword ptr [edx]
// 00461416  6a01                 push 1
// 00461418  ffd0                 call eax
// 0046141a  8b5ddc               mov ebx, dword ptr [ebp - 0x24]
// 0046141d  80be4501000000       cmp byte ptr [esi + 0x145], 0
// 00461424  750d                 jne 0x461433
// 00461426  80be4601000000       cmp byte ptr [esi + 0x146], 0
// 0046142d  7404                 je 0x461433
// 0046142f  33ff                 xor edi, edi
// 00461431  eb05                 jmp 0x461438
// 00461433  bf01000000           mov edi, 1
// 00461438  8bce                 mov ecx, esi
// 0046143a  e8f1bdffff           call 0x45d230
// 0046143f  6a01                 push 1
// 00461441  57                   push edi
// 00461442  8bc8                 mov ecx, eax
// 00461444  e887b6ffff           call 0x45cad0
// 00461449  8bcb                 mov ecx, ebx
// 0046144b  c645fc00             mov byte ptr [ebp - 4], 0
// 0046144f  e81c432c00           call 0x725770
// 00461454  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0046145b  e984000000           jmp 0x4614e4
// roc-cl: 50727
#include <string>
#include <sstream>
#include <istream>
#include <memory>
#include <exception>


class __declspec(dllimport) CString {
    char* m_pszData;
public:
    CString();
    ~CString();
    void __cdecl Format(const char* format, ...);
    operator const char*() const;
};

namespace boost {
class lock_error : public std::exception {
public:
    lock_error();
};

namespace detail { namespace thread {
template <typename Mutex> class lock_ops {
public:
    static void lock(Mutex& m) { m.do_lock(); }
    static void unlock(Mutex& m) { m.do_unlock(); }
};

template <typename Mutex> class scoped_lock {
public:
    explicit scoped_lock(Mutex& mx, bool initially_locked = true)
        : m_mutex(mx), m_locked(false)
    {
        if (initially_locked) lock();
    }
    ~scoped_lock()
    {
        if (m_locked) unlock();
    }
    void lock()
    {
        if (m_locked) throw lock_error();
        lock_ops<Mutex>::lock(m_mutex);
        m_locked = true;
    }
    void unlock()
    {
        if (!m_locked) throw lock_error();
        lock_ops<Mutex>::unlock(m_mutex);
        m_locked = false;
    }
private:
    Mutex& m_mutex;
    bool m_locked;
};
} }

class recursive_mutex {
public:
    typedef detail::thread::scoped_lock<recursive_mutex> scoped_lock;
    void do_lock();
    void do_unlock();
};

namespace detail {
class sp_counted_base;
class shared_count {
public:
    sp_counted_base* pi_;
};
}

template<class T> class shared_ptr {
public:
    T& operator*() const { return *px; }
    T* operator->() const { return px; }
    operator bool() const { return px != 0; }
    T* px;
    detail::shared_count pn;
};

namespace iostreams {
std::streamsize copy(std::istream& in, std::ostream& out, std::streamsize buffer_size);
}
}

namespace RBX {
class ContentId {
public:
    std::string id;
    int kind;
    const std::string& toString() const { return id; }
};

class ContentProvider {
public:
    static ContentProvider* singleton();
    std::auto_ptr<std::istream> getContent(ContentId id);
};

class Script {
public:
    char pad_00[0xe8];
    std::string* embeddedCode;
    char pad_ec[0xf0 - 0xec];
    ContentId scriptId;
    const std::string& getEmbeddedCode() const { return *embeddedCode; }
    const ContentId& getScriptId() const { return scriptId; }
};
}

namespace Scintilla {
class CScintillaCtrl {
public:
    void SetText(const char* text, int bDirect = 1);
    void SetReadOnly(int readOnly, int bDirect = 1);
    void SetSavePoint(int bDirect = 1);
};
}

class CScriptEditor {
public:
    char pad_00[0x20];
    void* m_hWnd;
    char pad_24[0x128 - 0x24];
    boost::shared_ptr<boost::recursive_mutex> mutex;
    int m_130;
    boost::shared_ptr<RBX::Script> script;
    boost::shared_ptr<RBX::Script> m_13c;
    bool loading;
    bool running;
    bool embedded;

    Scintilla::CScintillaCtrl& GetCtrl();
    void reload();
};

void CScriptEditor::reload()
{
    if (!m_hWnd)
        return;
    loading = true;
    if (script) {
        try {
            boost::recursive_mutex::scoped_lock lock(*mutex);
            embedded = script->getScriptId().toString().size() == 0;
            if (embedded) {
                GetCtrl().SetText(script->getEmbeddedCode().c_str());
            } else {
                std::auto_ptr<std::istream> input = RBX::ContentProvider::singleton()->getContent(script->getScriptId());
                std::ostringstream output;
                boost::iostreams::copy(*input, output, 4096);
                GetCtrl().SetText(output.str().c_str());
            }
            GetCtrl().SetReadOnly(running || !embedded);
        } catch (std::exception& e) {
            CString message;
            message.Format("An error occurred while getting the script\n\n%s", e.what());
            GetCtrl().SetText(message);
            GetCtrl().SetReadOnly(0);
        }
    } else {
        GetCtrl().SetText("");
    }
    GetCtrl().SetSavePoint();
    loading = false;
}
