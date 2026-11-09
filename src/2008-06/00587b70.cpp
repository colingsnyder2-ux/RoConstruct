// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct String {};
extern String &(__thiscall *string_assign)(String *, const String *);

struct Owner;
struct Proxy {
    Owner *owner;
};

struct Node {
    Node *previous;
    Node *next;
    char *value;
};

struct Owner {
    char padding[0x14];
    Node *head;
};

struct S {
    char padding0[0x138];
    Proxy * volatile owner;
    char padding1[0x10];
    Node *head;
    char padding2[0x0c];
    Proxy *iteratorOwner;
    Node *iteratorNode;
    char padding3;
    bool enabled;

    bool f(String *result, int count);
};

bool S::f(String *result, int count)
{
    if (!enabled)
        return false;

    Node *node = iteratorNode;
    Proxy *proxy = iteratorOwner;

    for (int i = 0; i < count; ++i) {
        Node *limit = head->previous;
        Proxy *expected = owner;
        if (!proxy || proxy != expected)
            _invalid_parameter_noinfo();

        if (node == limit)
            return false;

        if (!proxy)
            _invalid_parameter_noinfo();

        node = node->next;
        Owner *container = proxy ? proxy->owner : 0;
        if (node == container->head)
            _invalid_parameter_noinfo();
    }

    Node *limit = head;
    Proxy *expected = owner;
    if (!proxy || proxy != expected)
        _invalid_parameter_noinfo();

    if (node == limit)
        return false;

    limit = head->previous;
    expected = owner;
    if (!proxy || proxy != expected)
        _invalid_parameter_noinfo();

    if (node == limit)
        return false;

    if (!proxy)
        _invalid_parameter_noinfo();

    Owner *container = proxy ? proxy->owner : 0;
    if (node == container->head)
        _invalid_parameter_noinfo();

    string_assign(result, reinterpret_cast<const String *>(node->value + 0x24));
    return true;
}
