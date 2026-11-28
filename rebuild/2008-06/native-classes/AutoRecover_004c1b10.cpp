// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: endThreads is volatile and located at offset 4.
class ProfiledRakPeer
{
    volatile bool endThreads;

public:
    virtual bool IsActive() const;
};

bool ProfiledRakPeer::IsActive() const
{
    return !endThreads;
}
