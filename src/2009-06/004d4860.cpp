// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
template<class T> struct Countable {
    static long count;
    Countable() { InterlockedIncrement(&count); }
};
template<class T> struct sptr {
    T* px; void* pn;
    sptr() : px(0), pn(0) {}
    ~sptr();
};
template<class T> struct scoped {
    T* p;
    scoped() : p(0) {}
    ~scoped();
};
struct B0 { virtual void a(); int x[4]; };
struct B1 { virtual void b(); };
struct B2 { virtual void c(); int d; };
struct B3 { virtual void e(); char pad[0x68]; };
struct B4 { virtual void f(); char pad[0x74]; };
struct Base : B0, B1, B2, B3, B4 {
    Base();
    ~Base();
    void setName(const std::string& name);
};
struct X;
struct Client : Base {
    Countable<Client> counter;
    sptr<X> sp;
    int i110, i114;
    std::string str;
    scoped<X> s1, s2, s3;
    Client();
};
Client::Client()
{
    setName("NetworkClient");
}
