// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
#include <string.h>
class RakPeer {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual bool IsActive(void) const;
    virtual bool GetOutgoingFrequencyTable( unsigned int outputFrequencyTable[ 256 ] );
    char pad[0x5f4 - 4];
    unsigned int frequencyTable[256];
    char pad2[0xa50 - 0x9f4];
    bool trackFrequencyTable;
};
bool RakPeer::GetOutgoingFrequencyTable( unsigned int outputFrequencyTable[ 256 ] )
{
	if ( IsActive() )
		return false;

	if ( trackFrequencyTable == false )
		return false;

	memcpy( outputFrequencyTable, frequencyTable, sizeof( unsigned int ) * 256 );

	return true;
}
