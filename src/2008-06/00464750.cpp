// from server: 100% by king_originala
struct Result
{
    void *object;
    void *count;

    Result() : object(0), count(0) {}
};

struct Instance
{
    char padding[0x104];
    Instance *parent;

    Instance *getRootAncestor();
};

struct DataModel
{
    Result getResult();
};

extern char instanceType;
extern char dataModelType;

extern "C" void *__cdecl __RTDynamicCast(
    void *, long, void *, void *, int);

Result func_00464750(Instance *instance)
{
    volatile int temporary = 0;

    if (!instance)
        return Result();

    Instance *root = instance;
    if (root->parent)
        root = root->parent->getRootAncestor();

    DataModel *model = static_cast<DataModel *>(
        __RTDynamicCast(root, 0, &instanceType, &dataModelType, 0));

    if (!model)
        return Result();

    return model->getResult();
}
