// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class RakPeer {
public:
    struct RemoteSystemStruct {
        RemoteSystemStruct();
        ~RemoteSystemStruct();
        char data[0x13d0];
    };
};
namespace RakNet {
template<class Type> Type* OP_NEW_ARRAY(const int count)
{
    return new Type[count];
}
template RakPeer::RemoteSystemStruct* OP_NEW_ARRAY<RakPeer::RemoteSystemStruct>(const int);
}
