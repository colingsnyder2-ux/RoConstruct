// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace boost { namespace signals {
class connection { public: void disconnect() const; void* a; void* b; };
} }
namespace RBX {
class Accoutrement {
public:
    char pad[0xfc];
    boost::signals::connection c1;
    boost::signals::connection c2;
protected:
    void downFrom_InCharacter();
};
void Accoutrement::downFrom_InCharacter()
{
    c1.disconnect();
    c2.disconnect();
}
}
