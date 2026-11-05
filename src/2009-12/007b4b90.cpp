// from server: 68% by atomic.potato
struct S
{
    S();
};

void helper(S*, int);

S::S()
{
    helper(this, 2);
    *(int*)this = 0x9ee02c;
    *(int*)((char*)this + 0x20) = 0x9ee00c;
}
