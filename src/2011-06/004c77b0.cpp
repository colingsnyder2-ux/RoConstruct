// from server: 89% by atomic.potato
struct MeshAdapter
{
    int isValid();
};

extern "C" MeshAdapter* __cdecl getLocalScope();

int MeshAdapter::isValid()
{
    return getLocalScope() == this;
}
