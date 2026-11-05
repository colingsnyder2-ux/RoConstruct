// from server: 71% by tajop
struct String { char b[28]; ~String(); };
struct Link { Link* next; };
struct Node { String name; int value; Link link; };
struct S { int a; int count; int c; int d; Link* buckets; void clear(); };

void S::clear() {
    int n = count;
    Link* b = buckets;
    Link* e = b + n;
    for (; b != e; ++b) {
        Link* p = b->next;
        while (p != b) {
            Link* next = p->next;
            Node* obj = (Node*)((char*)p - 0x20);
            obj->name.~String();
            operator delete(obj);
            p = next;
        }
    }
}
