// from server: 53% by atomic.potato
struct FileLoader;

typedef void (__thiscall *LoaderFunction)(void *, void *);

struct FileLoader
{
    void fillVertices(void *, void *);
};

void FileLoader::fillVertices(void *arg1, void *arg2)
{
    LoaderFunction function = *(LoaderFunction *)(*(unsigned long *)arg1 + 12);
    function((char *)this + 8, arg2);
}
