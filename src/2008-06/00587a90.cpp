// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" {
    extern __declspec(dllimport) void __cdecl invalid_parameter_noinfo();
}

struct String {
    char unused;
};

extern String& (__thiscall *assign_string)(String*, const String&);

struct Value {
    char padding[0x24];
    String text;
};

struct Node {
    Node* next;
    Node* previous;
    Value* value;
};

struct Container {
    char padding[0x14];
    Node* head;
};

struct Proxy {
    Container* container;
};

struct S {
    char padding0[0x138];
    Proxy* volatile proxy;
    char padding1[0x10];
    Node* head;
    char padding2[4];
    Proxy* currentProxy;
    Node* currentNode;
    char padding3[9];
    bool enabled;

    bool f(String* output, int count);
};

bool S::f(String* output, int count)
{
    if (!enabled)
        return false;

    Node* node = currentNode;
    Proxy* owner = currentProxy;

    for (int i = 0; i < count; ++i) {
        Node* end = head;
        Proxy* endOwner = proxy;

        if (!owner || owner != endOwner)
            invalid_parameter_noinfo();

        if (node == end)
            return false;

        if (!owner)
            invalid_parameter_noinfo();

        Container* container = owner ? owner->container : 0;
        if (node == container->head)
            invalid_parameter_noinfo();

        node = node->next;
    }

    Node* end = head;
    Proxy* endOwner = proxy;
    void (__cdecl *report)();

    if (!owner || owner != endOwner) {
        report = invalid_parameter_noinfo;
        report();
    } else {
        report = invalid_parameter_noinfo;
    }

    if (node == end)
        return false;

    if (!owner)
        report();

    Container* container = owner ? owner->container : 0;
    if (node == container->head)
        report();

    assign_string(output, node->value->text);
    return true;
}
