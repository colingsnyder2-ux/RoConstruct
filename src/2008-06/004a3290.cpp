// from server: 100% by coldek
#include <map>

struct Key {
    char data[0x14];
};

bool operator<(const Key&, const Key&);

typedef std::map<Key, int> Table;

struct State {
    char padding[0x164];
    Table table;
};

struct Script {
    char padding[0x130];
    const Key* externalKey;
    char reserved[4];
    Key localKey;
    unsigned int discriminator;
};

extern const char instanceType;
extern const char scriptType;
extern const char messageType;

extern "C" void* __cdecl dynamicCast(
    void* object, int offset, const void* sourceType,
    const void* targetType, int isReference);

struct ClientProxy {
    char padding[0x2d70];
    State* state;
    bool contains(void* object);
};

bool ClientProxy::contains(void* object)
{
    Script* script = static_cast<Script*>(
        dynamicCast(object, 0, &instanceType, &scriptType, 0));

    if (script) {
        if (script->discriminator == 0) {
            const Key& key = *script->externalKey;
            return state->table.find(key) != state->table.end();
        }
        return state->table.find(script->localKey) != state->table.end();
    }

    if (dynamicCast(object, 0, &instanceType, &messageType, 0) == 0)
        return true;
    return false;
}
