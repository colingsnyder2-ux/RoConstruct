// from server: 58% by atomic.potato
struct Contact {
    char pad0[0xc];
    void* p0;
    void* p1;
};

struct ContactList {
    char pad0[0x98];
    int count;
    Contact* getContact(int i);
};

struct Block {
    char pad0[0xa0];
    int field_a0;
};

extern "C" int __stdcall sub_750f90(int);
extern "C" int __stdcall sub_972290(int, const char*);
extern "C" int (__stdcall *off_e5809c)(int, const char*, const char*);
extern "C" char byte_e580b3;

int Block_compare(Block* a, Block* b) {
    Block* least;
    Block* other;
    if (a->field_a0 < b->field_a0) {
        least = a;
        other = b;
    } else {
        least = b;
        if (b == a) {
            other = b;
        } else {
            other = a;
        }
    }
    int i = 0;
    if (least->field_a0 > 0) {
        ContactList* cl = (ContactList*)((char*)least + 0x98);
        do {
            Contact* c = cl->getContact(i);
            if (c == (Contact*)other) {
                if (byte_e580b3) {
                    Contact* c2 = cl->getContact(i);
                    if (!((c2->p0 == a && c2->p1 == b) || (c2->p0 == b && c2->p1 == a))) {
                        if (off_e5809c) {
                            if (off_e5809c(0x1e2, "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\v8world\\Primitive.cpp", "!leastContacts->getContact(i)->links(p0, p1)")) {
                                goto skip1;
                            }
                        }
                        sub_972290(byte_e580b3, "!leastContacts->getContact(i)->links(p0, p1) file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\v8world\\Primitive.cpp ");
                    }
                }
            skip1:
                return (int)cl->getContact(i);
            }
            if (byte_e580b3) {
                Contact* c2 = cl->getContact(i);
                if (!((c2->p0 == a && c2->p1 == b) || (c2->p0 == b && c2->p1 == a))) {
                    if (off_e5809c) {
                        if (off_e5809c(0x1e7, "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\v8world\\Primitive.cpp", "leastContacts->getContact(i)->links(p0, p1)")) {
                            goto skip2;
                        }
                    }
                    sub_972290(byte_e580b3, "leastContacts->getContact(i)->links(p0, p1) file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\v8world\\Primitive.cpp ");
                }
            }
        skip2:
            i++;
        } while (i < least->field_a0);
    }
    return 0;
}
