// from server: 30% by atomic.potato
struct S_func_004ee380 {
    char pad0[0x10];
    struct Map {
        char pad0[8];
        unsigned int *m_data;
        unsigned int m_size;
        unsigned int m_capacity;
        unsigned int m_count;
    } m_map;
    int f(void *arg);
};

extern "C" int __stdcall sub_4ede10(void *, void *);
extern "C" void __stdcall sub_4ee220(void *, void *);
extern "C" void __stdcall sub_4ee290(void *, void *);
extern "C" void *__stdcall sub_72a080(void *, unsigned int);

extern double g_4ee380_a;

int S_func_004ee380::f(void *arg)
{
    unsigned int *p = (unsigned int *)arg;
    unsigned int v0 = p[0];
    unsigned short v1 = *(unsigned short *)((char *)p + 4);
    unsigned int edx = v0 - 0x61c88647;
    unsigned int eax = v1 + (edx << 6);
    eax = eax + (edx >> 2) - 0x61c88647;
    eax ^= edx;
    unsigned int hash = eax;

    unsigned int idx = hash % m_map.m_size;
    unsigned int *slot = m_map.m_data + idx;

    if (sub_4ede10(slot, arg) != 0)
        return (int)((char *)slot - 0x148);

    char local[0x148];
    *(void **)(local + 0) = &m_map;
    *(unsigned int *)(local + 4) = 0;
    local[8] = 0;
    local[9] = 0;

    *(double *)(local + 0xf0) = g_4ee380_a;
    *(double *)(local + 0xf8) = 0.0;
    *(double *)(local + 0x100) = 0.0;
    *(double *)(local + 0x108) = 0.0;
    *(double *)(local + 0x118) = g_4ee380_a;
    *(double *)(local + 0x120) = 0.0;
    *(double *)(local + 0x128) = 0.0;
    *(double *)(local + 0x130) = 0.0;

    *(unsigned int *)(local + 0x140) = p[0];
    *(unsigned int *)(local + 0x144) = p[1];
    local[0x110] = 1;
    local[0x138] = 1;

    sub_4ee220(local, local + 0x140);

    unsigned int count = m_map.m_count;
    unsigned int next = count + 1;
    if (next >= m_map.m_capacity) {
        unsigned int cap = count;
        unsigned int half = cap >> 1;
        cap += half;
        if (cap <= next)
            cap = next;
        void *r = sub_72a080(&m_map, cap);
        sub_4ee290(&m_map, r);
        unsigned int idx2 = hash % m_map.m_size;
        slot = m_map.m_data + idx2;
    } else {
        slot = (unsigned int *)(local + 0x10);
    }

    unsigned int *node = *(unsigned int **)(local + 0x18);
    if (node != 0)
        node = (unsigned int *)((char *)node + 0x148);
    else
        node = 0;

    *node = *slot;
    *slot = (unsigned int)node;
    m_map.m_count++;

    if ((unsigned int)slot < m_map.m_capacity)
        m_map.m_capacity = (unsigned int)slot;

    return (int)((char *)node - 0x148);
}
