// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
class DataBlockEncryptor
{
public:
	void SetKey( const unsigned char key[ 16 ] );
	void UnsetKey( void );
};
class ReliabilityLayer
{
	char exePad2009[0x1070];
	DataBlockEncryptor encryptor;
public:
	void SetEncryptionKey( const unsigned char* key );
};
void ReliabilityLayer::SetEncryptionKey( const unsigned char* key )
{
	if ( key )
		encryptor.SetKey( key );
	else
		encryptor.UnsetKey();
}
