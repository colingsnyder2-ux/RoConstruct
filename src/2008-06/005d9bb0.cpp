// from server: 100% by king_originala
struct Humanoid;

struct ModelInstance
{
    Humanoid* getHumanoid();
};

struct Player;

extern ModelInstance* __cdecl getCharacter(const Player*);
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

Humanoid* __cdecl findHumanoid(const Player* player)
{
    ModelInstance* character = getCharacter(player);
    if (character)
    {
        ModelInstance* model = static_cast<ModelInstance*>(
            __RTDynamicCast(character, 0,
                reinterpret_cast<void*>(0x92907c),
                reinterpret_cast<void*>(0x932a40), 0));
        if (model)
            return model->getHumanoid();
    }
    return 0;
}
