// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" char g_00823984[], g_00823978[], g_00823970[], g_00823968[];
extern "C" char g_00823958[], g_00823948[], g_00823938[], g_00823928[];
extern "C" char g_00823918[], g_00823908[], g_008238d8[], g_008238cc[];

#pragma comment(linker, "/alternatename:??1?$FactoryProduct@VServer@Network@RBX@@VPeer@23@$1?sServer@23@3PADA@RBX@@IAE@XZ=??1?$FactoryProduct@VServer@Network@RBX@@VPeer@23@$1?sServer@23@3PADA@RBX@@MAE@XZ")

namespace RBX
{
    namespace Network
    {
        class Server;
        class Peer;
        extern char sServer[];
    }

    // INFERRED: Word overlay preserves the constructor's store offsets.
    // The alias binds the direct unwind call to the native base destructor.
    template<class C, class D, const char* N>
    class FactoryProduct
    {
    protected:
        unsigned long words[78];
        FactoryProduct();
        ~FactoryProduct();
    };

    namespace Reflection
    {
        class ClassDescriptor;

        template<class C, const char* N, class D>
        class Described
        {
        public:
            static ClassDescriptor& classDescriptor();
        };
    }

    template<class C, class D, const char* N>
    class DescribedCreatable : public FactoryProduct<C, D, N>
    {
    protected:
        DescribedCreatable();
    };

    // Verified relocation identities name the constructor and both callees.
    // This standalone translation unit has no fresh byte-match verification.
    template<>
    DescribedCreatable<Network::Server, Network::Peer, Network::sServer>::DescribedCreatable()
        : FactoryProduct<Network::Server, Network::Peer, Network::sServer>()
    {
        words[7] = reinterpret_cast<unsigned long>(&Reflection::Described<
            Network::Server, Network::sServer,
            FactoryProduct<Network::Server, Network::Peer, Network::sServer>
        >::classDescriptor());
        words[0] = reinterpret_cast<unsigned long>(g_00823984);
        words[4] = reinterpret_cast<unsigned long>(g_00823978);
        words[5] = reinterpret_cast<unsigned long>(g_00823970);
        words[8] = reinterpret_cast<unsigned long>(g_00823968);
        words[9] = reinterpret_cast<unsigned long>(g_00823958);
        words[17] = reinterpret_cast<unsigned long>(g_00823948);
        words[25] = reinterpret_cast<unsigned long>(g_00823938);
        words[33] = reinterpret_cast<unsigned long>(g_00823928);
        words[41] = reinterpret_cast<unsigned long>(g_00823918);
        words[49] = reinterpret_cast<unsigned long>(g_00823908);
        words[76] = reinterpret_cast<unsigned long>(g_008238d8);
        words[77] = reinterpret_cast<unsigned long>(g_008238cc);
    }
}
