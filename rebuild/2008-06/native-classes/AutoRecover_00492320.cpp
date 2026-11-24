// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native header paths were visible, so the needed declarations are made file-local.
// INFERRED: the offsets 0x1a0 and 0x1d0 come from the disassembly; their field meanings are guesses.

namespace RBX {
    class Instance;
    namespace Network {
        class Players;
    }
    class ServiceProvider {
    public:
        template<class T> T* find() const;
        static const ServiceProvider* findServiceProvider(const Instance* instance);
    };
}

namespace G3D {
    class System {
    public:
        static double getLocalTime();
    };
}

extern "C" void fn_00492320(const RBX::ServiceProvider* sp)
{
    RBX::Network::Players* players = sp->find<RBX::Network::Players>();
    if (players)
    {
        // INFERRED: the pointer at +0x1a0 is the local player, an Instance subclass.
        RBX::Instance* player = *reinterpret_cast<RBX::Instance**>(
            reinterpret_cast<char*>(players) + 0x1a0);
        if (player)
        {
            if (RBX::ServiceProvider::findServiceProvider(player))
            {
                // INFERRED: +0x1d0 holds a double timestamp on the player.
                *reinterpret_cast<double*>(reinterpret_cast<char*>(player) + 0x1d0) =
                    G3D::System::getLocalTime();
            }
        }
    }
}
