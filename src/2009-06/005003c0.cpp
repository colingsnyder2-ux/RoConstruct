// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
#include <string.h>
typedef unsigned int RakNetTime;
namespace RakNet { RakNetTime GetTime( void ); }
extern void (*rakFree)(void*);

class SimpleMutex
{
public:
	void Lock(void);
	void Unlock(void);
	char pad[0x1c];
};

namespace DataStructures
{
	template <class list_type>
	class List
	{
	public:
		list_type& operator[] ( const unsigned int position ) const { return listArray[ position ]; }
		unsigned int Size( void ) const { return list_size; }
		void RemoveAtIndex( const unsigned int position );
		list_type* listArray;
		unsigned int list_size;
		unsigned int allocation_size;
	};
}

struct BanStruct
{
	char *IP;
	RakNetTime timeout;
};

class RakPeer
{
public:
	virtual ~RakPeer();
	virtual bool IsBanned( const char *IP );
	char pad0[0x594-4];
	SimpleMutex banListMutex;
	DataStructures::List<BanStruct*> banList;
};

bool RakPeer::IsBanned( const char *IP )
{
	unsigned banListIndex, characterIndex;
	RakNetTime time;
	BanStruct *temp;

	if ( IP == 0 || IP[ 0 ] == 0 || strlen( IP ) > 15 )
		return false;

	banListIndex = 0;

	if ( banList.Size() == 0 )
		return false; // Skip the mutex if possible

	time = RakNet::GetTime();

	banListMutex.Lock();

	while ( banListIndex < banList.Size() )
	{
		if (banList[ banListIndex ]->timeout>0 && banList[ banListIndex ]->timeout<time)
		{
			temp = banList[ banListIndex ];
			banList[ banListIndex ] = banList[ banList.Size() - 1 ];
			banList.RemoveAtIndex( banList.Size() - 1 );
			rakFree(temp->IP);
			delete temp;
		}
		else
		{
			characterIndex = 0;
			while ( true )
			{
				if ( banList[ banListIndex ]->IP[ characterIndex ] == IP[ characterIndex ] )
				{
					if ( IP[ characterIndex ] == 0 )
					{
						banListMutex.Unlock();
						return true;
					}
					characterIndex++;
				}
				else
				{
					if ( banList[ banListIndex ]->IP[ characterIndex ] == 0 || IP[ characterIndex ] == 0 )
						break;
					if ( banList[ banListIndex ]->IP[ characterIndex ] == '*' )
					{
						banListMutex.Unlock();
						return true;
					}
					break;
				}
			}
			banListIndex++;
		}
	}

	banListMutex.Unlock();
	return false;
}
