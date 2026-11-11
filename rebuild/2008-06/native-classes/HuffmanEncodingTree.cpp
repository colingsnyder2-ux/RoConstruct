// native-flags: /O2 /EHsc /MD /GS- /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\raknet30\Source
// >>> native-status (generated) -- do not edit >>>
// HuffmanEncodingTree | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src b466922c | roc native-status --write
#include "../../../tools/rbxgs/Client/Network/raknet30/Source/DS_HuffmanEncodingTree.h"
#include "DS_Queue.h"
#include "BitStream.h"

void HuffmanEncodingTree::InsertNodeIntoSortedList( HuffmanEncodingTreeNode * node, DataStructures::LinkedList<HuffmanEncodingTreeNode *> *huffmanEncodingTreeNodeList ) const
{
	if ( huffmanEncodingTreeNodeList->Size() == 0 )
	{
		huffmanEncodingTreeNodeList->Insert( node );
		return ;
	}
	
	huffmanEncodingTreeNodeList->Beginning();
	
	unsigned counter = 0;
#ifdef _MSC_VER
#pragma warning( disable : 4127 ) // warning C4127: conditional expression is constant
#endif
	while ( 1 )
	{
		if ( huffmanEncodingTreeNodeList->Peek()->weight < node->weight )
			++( *huffmanEncodingTreeNodeList );
		else
		{
			huffmanEncodingTreeNodeList->Insert( node );
			break;
		}
		
		// Didn't find a spot in the middle - add to the end
		if ( ++counter == huffmanEncodingTreeNodeList->Size() )
		{
			huffmanEncodingTreeNodeList->End();
			
			huffmanEncodingTreeNodeList->Add( node )
			
			; // Add to the end
			break;
		}
	}
}
