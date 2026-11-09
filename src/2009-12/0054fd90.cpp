// from server: 100% by atomic.potato
extern "C" int __cdecl InitializeIdSerializer();

int g_IdSerializerCount;
int g_IdSerializerHandle;

struct IdSerializer
{
    void Initialize();
};

void IdSerializer::Initialize()
{
    ++g_IdSerializerCount;
    if (g_IdSerializerCount == 1)
        g_IdSerializerHandle = InitializeIdSerializer();
}
