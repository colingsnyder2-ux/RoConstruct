// from server: 100% by king_originala
namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
    };

    class PartInstance : public Instance {};
    class ModelInstance : public Instance {};
}

int __stdcall func_006298d0(RBX::Instance* instance)
{
    return dynamic_cast<RBX::PartInstance*>(instance) != 0 ||
           dynamic_cast<RBX::ModelInstance*>(instance) != 0;
}
