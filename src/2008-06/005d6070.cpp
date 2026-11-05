// from server: 100% by colin
namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
        char padding[0x100];
        Instance* next;
    };

    struct Entry {
        Instance* object;
        void* control;
    };

    struct Children {
        char padding[0x0c];
        Entry* first;
        Entry* last;
    };

    struct ServiceProvider : Instance {
        Children* children;
        unsigned int count();
    };

    namespace Network {
        class Player : Instance {
        public:
            char padding[0x74];
            bool flag;
        };
    }

    struct FactoryProduct : Instance {
        bool f();
    };
}

extern RBX::ServiceProvider* __cdecl func_00491d50(RBX::Instance*);
extern "C" void (__cdecl *invalid_parameter_noinfo)();

bool RBX::FactoryProduct::f()
{
    ServiceProvider* provider = func_00491d50(this);
    unsigned int i = 0;

    if (provider->count() > 0) {
        void (__cdecl *invalid)() = invalid_parameter_noinfo;
        do {
            Children* children = provider->children;
            if (i >= static_cast<unsigned int>(children->last - children->first))
                invalid();

            Instance* obj = children->first[i].object;
            Network::Player* player = dynamic_cast<Network::Player*>(obj);

            if (player && !player->flag)
                return true;

            ++i;
        } while (i < provider->count());
    }

    return false;
}
