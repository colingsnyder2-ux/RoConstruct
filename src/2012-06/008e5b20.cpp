// from server: 100% by atomic.potato
struct S
{
    void f();
    void *v0;
    void *v1;
    void *v2;
    void *v3;
    void *v4;
    void *v5;
    void *v6;
    void *v7;
    void *v8;
    void *v9;
    void *v10;
    void *v11;
    void *v12;
    void *v13;
    void *v14;
    void *v15;
    void *v16;
    void *v17;
    void *v18;
    void *v19;
    void *v20;
    void *v21;
    void *v22;
    void *v23;
    void *v24;
    void *v25;
    void *v26;
    void *v27;
    void *v28;
    void *v29;
    void *v30;
    void *v31;
    void *v32;
    void *v33;
};

extern "C" void continuation();

void S::f()
{
    v0 = (void *)0x00becba4;
    v1 = (void *)0x00becb9c;
    v6 = (void *)0x00becb90;
    v7 = (void *)0x00becb84;
    v32 = (void *)0x00becb74;
    v33 = (void *)0x00becb48;
    continuation();
}
