// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void __cdecl invalid_parameter_noinfo();
extern "C" void* __cdecl runtime_cast(void*, int, const void*, const void*, int);

extern char instance_type;
extern char camera_type;

struct PartTool;
struct Children;

struct Entry {
    PartTool* object;
    void* reference;
};

struct IteratorOwner {
    Children* container;
};

struct Children {
    IteratorOwner* owner;
    unsigned char padding[8];
    Entry* first;
    Entry* last;
};

struct EndIterator {
    Entry* position;
    IteratorOwner* owner;
    unsigned int reserved;
};

struct PartTool {
    unsigned char padding[0x108];
    Children* children;
    void* findCamera();
};

void* PartTool::findCamera()
{
    Children* list = children;
    if (list) {
        EndIterator finish;
        finish.position = list->last;
        void (__cdecl *report)() = invalid_parameter_noinfo;
        if (list->first > finish.position)
            report();
        finish.owner = list->owner;

        list = children;
        Entry* current = list->first;
        if (current > list->last)
            report();
        IteratorOwner* owner = list->owner;

        for (;;) {
            if (!owner || owner != finish.owner)
                report();
            if (current == finish.position)
                break;

            Children* container;
            if (!owner) report();
    container = owner ? owner->container : 0;
            if (current >= container->last)
                report();

            PartTool* object = current->object;
            void* result = runtime_cast(object, 0, &instance_type, &camera_type, 0);
            if (result)
                return result;
            result = object->findCamera();
            if (result)
                return result;

            if (!owner) report();
    container = owner ? owner->container : 0;
            if (current >= container->last)
                report();
            ++current;
        }
    }
    return 0;
}
