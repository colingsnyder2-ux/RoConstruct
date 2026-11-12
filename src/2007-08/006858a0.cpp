// from server: 74% by EspClaude
// from server: 51% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: g3d-6.09 roc_claude_6bc3a7833d400ab3.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog for 2007-08 0x6858a0: acquire an item through vtable slot +0x68, hand it to a
// consumer's slot +8 inside try, swallow COleException* / CArchiveException* (MFC80 CException::Delete,
// ordinal 1917, reached through a thunk) and release the item through slot +0x6c.
class CException
{
public:
    void Delete();
};
class COleException : public CException {};
class CArchiveException : public CException {};

struct RocItem06858a0;

class RocProvider06858a0
{
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64();
    virtual RocItem06858a0 * acquire(unsigned long key);
    virtual void release(unsigned long key, RocItem06858a0 * item);
};

class RocConsumer06858a0
{
public:
    virtual void v00(); virtual void v04();
    virtual void consume(RocItem06858a0 * item);
};

int roc_consume_06858a0(RocProvider06858a0 * provider, unsigned long key, RocConsumer06858a0 * consumer)
{
    RocItem06858a0 * item = provider->acquire(key);
    if (item == 0)
        return 0;
    int result = 0;
    try
    {
        consumer->consume(item);
        result = 1;
    }
    catch (COleException * e)
    {
        e->Delete();
    }
    catch (CArchiveException * e)
    {
        e->Delete();
    }
    provider->release(key, item);
    return result;
}
