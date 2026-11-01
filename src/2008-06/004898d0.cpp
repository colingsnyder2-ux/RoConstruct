// from server: 100% by king_originala
namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
        char padding[256];
        Instance* parent;
    };

    class ServiceProvider : public Instance {};
}

RBX::ServiceProvider* findServiceProvider(RBX::Instance* instance)
{
    while (instance) {
        RBX::ServiceProvider* provider =
            dynamic_cast<RBX::ServiceProvider*>(instance);
        if (provider)
            return provider;
        instance = instance->parent;
    }
    return 0;
}
