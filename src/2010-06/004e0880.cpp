// from server: 47% by atomic.potato
extern "C" void string_copy(void *, const void *);

struct Ray
{
    int value;
    void *name;
    Ray(const Ray &);
};

Ray::Ray(const Ray &other)
{
    name = 0;
    string_copy((void *)&name, other.name);
}
