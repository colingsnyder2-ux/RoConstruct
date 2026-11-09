// from server: 66% by colin
struct S {
    void f();
};

void S::f()
{
    unsigned char* p = (unsigned char*)(0x27e9044d + (unsigned int)this);
    *p = *p - 1;
}
