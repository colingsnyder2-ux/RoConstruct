// from server: 100% by colin
struct Inner;

struct Outer {
    char pad[0xa8];
    Inner* inner;
    Inner* SetItem(Inner* item);
};

struct Inner {
    Inner* SetItem(Inner* item);
};

Inner* Outer::SetItem(Inner* item)
{
    Inner* result = inner->SetItem(item);
    return item;
}
