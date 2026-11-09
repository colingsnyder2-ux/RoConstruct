// from server: 100% by king_originala
namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
    };

    struct Humanoid;

    class ModelInstance : public Instance {
    public:
        Humanoid* getHumanoid();
    };

    struct Humanoid {
        static Humanoid* fromInstance(Instance*);
    };
}

RBX::Humanoid* RBX::Humanoid::fromInstance(RBX::Instance* instance)
{
    if (instance) {
        ModelInstance* model = dynamic_cast<ModelInstance*>(instance);
        if (model)
            return model->getHumanoid();
    }
    return 0;
}
