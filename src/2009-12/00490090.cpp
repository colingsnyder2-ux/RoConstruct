// from server: 13% by atomic.potato
struct RbxSubEntity_00490090
{
    char pad[288];
    char data[64];
    void f(char* destination);
};

void RbxSubEntity_00490090::f(char* destination)
{
    *(long*)destination = *(long*)data;
    *((long*)destination + 1) = *((long*)data + 1);
    *((long*)destination + 2) = *((long*)data + 2);
    *((long*)destination + 3) = *((long*)data + 3);
    *((long*)destination + 4) = *((long*)data + 4);
    *((long*)destination + 5) = *((long*)data + 5);
    *((long*)destination + 6) = *((long*)data + 6);
    *((long*)destination + 7) = *((long*)data + 7);
    *((long*)destination + 8) = *((long*)data + 8);
    *((long*)destination + 9) = *((long*)data + 9);
    *((long*)destination + 10) = *((long*)data + 10);
    *((long*)destination + 11) = *((long*)data + 11);
    *((long*)destination + 12) = *((long*)data + 12);
    *((long*)destination + 13) = *((long*)data + 13);
    *((long*)destination + 14) = *((long*)data + 14);
    *((long*)destination + 15) = *((long*)data + 15);
}
