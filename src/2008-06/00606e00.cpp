// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Link {
    void update();
};

struct ContactConnector {
    unsigned char prefix[0x14];
    volatile int first;
    volatile int second;
    unsigned char middle[0x0c];
    float x;
    float y;
    float z;
    unsigned char tail[0x1c];

    ContactConnector(float, float, float);
    Link* attach(ContactConnector*);
    ContactConnector* create(int, int);
};

ContactConnector* ContactConnector::create(int a, int b)
{
    ContactConnector* result = new ContactConnector(x, y, z);
    result->first = a;
    result->second = b;
    attach(result)->update();
    return result;
}
