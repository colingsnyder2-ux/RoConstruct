// from server: 100% by EspClaude
// from server: 82% by EspClaude
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-lib: openrbx-raknet roc_claude_9a45b9d2eecb27a9.cpp

// Candidate translation unit (score above; library headers required).
/// \file
/// \brief \b [Internal] Quicksort ordered list.
///
/// This file is part of RakNet Copyright 2003 Kevin Jenkins.
///
/// Usage of RakNet is subject to the appropriate license agreement.
/// Creative Commons Licensees are subject to the
/// license found at
/// http://creativecommons.org/licenses/by-nc/2.5/
/// Single application licensees are subject to the license found at
/// http://www.rakkarsoft.com/SingleApplicationLicense.html
/// Custom license users are subject to the terms therein.
/// GPL license users are subject to the GNU General Public
/// License as published by the Free
/// Software Foundation; either version 2 of the License, or (at your
/// option) any later version.

#include "DS_List.h"
#include "Export.h"

#ifndef __ORDERED_LIST_H
#define __ORDERED_LIST_H

/// The namespace DataStructures was only added to avoid compiler errors for commonly named data structures
/// As these data structures are stand-alone, you can use them outside of RakNet for your own projects if you wish.
namespace DataStructures
{
	template <class key_type, class data_type>
	int defaultOrderedListComparison(const key_type &a, const data_type &b)
	{
		if (a<b) return -1; if (a==b) return 0; return 1;
	}

	/// \note IMPORTANT! If you use defaultOrderedListComparison then call IMPLEMENT_DEFAULT_COMPARISON or you will get an unresolved external linker error.
	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)=defaultOrderedListComparison<key_type, data_type> >
	class RAK_DLL_EXPORT OrderedList
	{
	public:
		static void IMPLEMENT_DEFAULT_COMPARISON(void) {DataStructures::defaultOrderedListComparison<key_type, data_type>(key_type(),data_type());}

		OrderedList();
		~OrderedList();
		OrderedList( const OrderedList& original_copy );
		OrderedList& operator= ( const OrderedList& original_copy );

		/// comparisonFunction must take a key_type and a data_type and return <0, ==0, or >0
		/// If the data type has comparison operators already defined then you can just use defaultComparison
		bool HasData(const key_type &key) const;
		// GetIndexFromKey returns where the insert should go at the same time checks if it is there
		unsigned GetIndexFromKey(const key_type &key, bool *objectExists) const;
		data_type GetElementFromKey(const key_type &key);
		bool GetElementFromKey(const key_type &key, data_type &element);
		unsigned Insert(const key_type &key, const data_type &data);
		unsigned Remove(const key_type &key);
		unsigned RemoveIfExists(const key_type &key);
		data_type& operator[] ( const unsigned int position ) const;
		void RemoveAtIndex(const unsigned index);
		void InsertAtIndex(const data_type &data, const unsigned index);
		void InsertAtEnd(const data_type &data);
		void Del(const unsigned num=1);
		void Clear(void);		
		unsigned Size(void) const;

	protected:
		DataStructures::List<data_type> orderedList;
	};

	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	OrderedList<key_type, data_type, comparison_function>::OrderedList()
	{
	}

	// FUNCTION: WEBSERVICE 0x101c2070
	// DataStructures::OrderedList<SystemAddress,SystemAddressAndIndex,&SystemAddressAndIndexComp>::~OrderedList<SystemAddress,SystemAddressAndIndex,&SystemAddressAndIndexComp>
	// FUNCTION: WEBSERVICE 0x101bedb0
	// DataStructures::OrderedList<unsigned int,DataStructures::RangeNode<unsigned int>,&DataStructures::RangeNodeComp<unsigned int> >::~OrderedList<unsigned int,DataStructures::RangeNode<unsigned int>,&DataStructures::RangeNodeComp<unsigned int> >
	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	OrderedList<key_type, data_type, comparison_function>::~OrderedList()
	{
		Clear();
	}

	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	OrderedList<key_type, data_type, comparison_function>::OrderedList( const OrderedList& original_copy )
	{
		orderedList=original_copy.orderedList;
	}

	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	OrderedList<key_type, data_type, comparison_function>& OrderedList<key_type, data_type, comparison_function>::operator= ( const OrderedList& original_copy )
	{
		orderedList=original_copy.orderedList;
		return *this;
	}

	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	bool OrderedList<key_type, data_type, comparison_function>::HasData(const key_type &key) const
	{
		bool objectExists;
		unsigned index;
		index = GetIndexFromKey(key, &objectExists);
		return objectExists;
	}

	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	data_type OrderedList<key_type, data_type, comparison_function>::GetElementFromKey(const key_type &key)
	{
		bool objectExists;
		unsigned index;
		index = GetIndexFromKey(key, &objectExists);
		assert(objectExists);
		return orderedList[index];
	}
	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	bool OrderedList<key_type, data_type, comparison_function>::GetElementFromKey(const key_type &key, data_type &element)
	{
		bool objectExists;
		unsigned index;
		index = GetIndexFromKey(key, &objectExists);
		if (objectExists)
			element = orderedList[index];
		return objectExists;
	}
	// FUNCTION: WEBSERVICE 0x101b1c90
	// DataStructures::OrderedList<SystemAddress,SystemAddressAndIndex,&SystemAddressAndIndexComp>::GetIndexFromKey
	// FUNCTION: WEBSERVICE 0x101bb0f0
	// DataStructures::OrderedList<unsigned int,DataStructures::RangeNode<unsigned int>,&DataStructures::RangeNodeComp<unsigned int> >::GetIndexFromKey
	// FUNCTION: WEBSERVICE 0x101bc4c0
	// DataStructures::OrderedList<unsigned short,SplitPacketChannel *,&SplitPacketChannelComp>::GetIndexFromKey
	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	unsigned OrderedList<key_type, data_type, comparison_function>::GetIndexFromKey(const key_type &key, bool *objectExists) const
	{
		int index, upperBound, lowerBound;
		int res;

		if (orderedList.Size()==0)
		{
			*objectExists=false;
			return 0;
		}

		upperBound=(int)orderedList.Size()-1;
		lowerBound=0;
		index = (int)orderedList.Size()/2;

#ifdef _MSC_VER
	#pragma warning( disable : 4127 ) // warning C4127: conditional expression is constant
#endif
		while (1)
		{
			res = comparison_function(key,orderedList[index]);
			if (res==0)
			{
				*objectExists=true;
				return index;
			}
			else if (res<0)
			{
				upperBound=index-1;
			}
			else// if (res>0)
			{
				lowerBound=index+1;
			}

			index=lowerBound+(upperBound-lowerBound)/2;

			if (lowerBound>upperBound)
			{
				*objectExists=false;
				return lowerBound; // No match
			}
		}
	}

	// FUNCTION: WEBSERVICE 0x101bb330
	// DataStructures::OrderedList<int,DataStructures::Map<int,HuffmanEncodingTree *,&DataStructures::defaultMapKeyComparison<int> >::MapNode,&DataStructures::Map<int,HuffmanEncodingTree *,&DataStructures::defaultMapKeyComparison<int> >::NodeComparisonFunc>::Insert
	// FUNCTION: WEBSERVICE 0x101be020
	// DataStructures::OrderedList<unsigned int,DataStructures::RangeNode<unsigned int>,&DataStructures::RangeNodeComp<unsigned int> >::Insert
	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	unsigned OrderedList<key_type, data_type, comparison_function>::Insert(const key_type &key, const data_type &data)
	{
		bool objectExists;
		unsigned index;
		index = GetIndexFromKey(key, &objectExists);

		if (objectExists)
		{
			return (unsigned)-1;
		}

		if (index>=orderedList.Size())
		{
			orderedList.Insert(data);
			return orderedList.Size()-1;
		}
		else
		{
			orderedList.Insert(data,index);
			return index;
		}		
	}

	// FUNCTION: WEBSERVICE 0x101b4710
	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	unsigned OrderedList<key_type, data_type, comparison_function>::Remove(const key_type &key)
	{
		bool objectExists;
		unsigned index;
		index = GetIndexFromKey(key, &objectExists);

		// Can't find the element to remove if this assert hits
		assert(objectExists==true);
		if (objectExists==false)
			return 0;

		orderedList.RemoveAtIndex(index);
		return index;
	}

	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	unsigned OrderedList<key_type, data_type, comparison_function>::RemoveIfExists(const key_type &key)
	{
		bool objectExists;
		unsigned index;
		index = GetIndexFromKey(key, &objectExists);

		// Can't find the element to remove if this assert hits
		if (objectExists==false)
			return 0;

		orderedList.RemoveAtIndex(index);
		return index;
	}

	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	void OrderedList<key_type, data_type, comparison_function>::RemoveAtIndex(const unsigned index)
	{
		orderedList.RemoveAtIndex(index);
	}

	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
		void OrderedList<key_type, data_type, comparison_function>::InsertAtIndex(const data_type &data, const unsigned index)
	{
		orderedList.Insert(data, index);
	}

	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
		void OrderedList<key_type, data_type, comparison_function>::InsertAtEnd(const data_type &data)
	{
		orderedList.Insert(data);
	}

	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
		void OrderedList<key_type, data_type, comparison_function>::Del(const unsigned num)
	{
		orderedList.Del(num);
	}

	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	void OrderedList<key_type, data_type, comparison_function>::Clear(void)
	{
		orderedList.Clear();
	}

	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	data_type& OrderedList<key_type, data_type, comparison_function>::operator[]( const unsigned int position ) const
	{
		return orderedList[position];
	}

	template <class key_type, class data_type, int (*comparison_function)(const key_type&, const data_type&)>
	unsigned OrderedList<key_type, data_type, comparison_function>::Size(void) const
	{
		return orderedList.Size();
	}
}

#endif

/// \file
/// \brief \b [Internal] Datagram reliable, ordered, unordered and sequenced sends.  Flow control.  Message splitting, reassembly, and coalescence.
///
/// This file is part of RakNet Copyright 2003 Kevin Jenkins.
///
/// Usage of RakNet is subject to the appropriate license agreement.
/// Creative Commons Licensees are subject to the
/// license found at
/// http://creativecommons.org/licenses/by-nc/2.5/
/// Single application licensees are subject to the license found at
/// http://www.rakkarsoft.com/SingleApplicationLicense.html
/// Custom license users are subject to the terms therein.
/// GPL license users are subject to the GNU General Public
/// License as published by the Free
/// Software Foundation; either version 2 of the License, or (at your
/// option) any later version.

#ifndef __RELIABILITY_LAYER_H
#define __RELIABILITY_LAYER_H

#include "MTUSize.h"
#include "DS_LinkedList.h"
#include "DS_List.h"
#include "SocketLayer.h"
#include "PacketPriority.h"
#include "DS_Queue.h"
#include "BitStream.h"
#include "InternalPacket.h"
#include "DS_MemoryPool.h"
#include "DataBlockEncryptor.h"
#include "RakNetStatistics.h"
#include "SHA1.h"
#include "DS_OrderedList.h"
#include "DS_RangeList.h"
#include "DS_BPlusTree.h"

class PluginInterface;

/// Sizeof an UDP header in byte
#define UDP_HEADER_SIZE 28

/// Number of ordered streams available. You can use up to 32 ordered streams
#define NUMBER_OF_ORDERED_STREAMS 32 // 2^5

#define RESEND_TREE_ORDER 32

#include "BitStream.h"

int SplitPacketIndexComp( SplitPacketIndexType const &key, InternalPacket* const &data );
struct SplitPacketChannel
{
	RakNetTimeNS lastUpdateTime;
	DataStructures::OrderedList<SplitPacketIndexType, InternalPacket*, SplitPacketIndexComp> splitPacketList;
};
int RAK_DLL_EXPORT SplitPacketChannelComp( SplitPacketIdType const &key, SplitPacketChannel* const &data );

/// Datagram reliable, ordered, unordered and sequenced sends.  Flow control.  Message splitting, reassembly, and coalescence.
class ReliabilityLayer
{
public:

	/// Constructor
	ReliabilityLayer();

	/// Destructor
	~ReliabilityLayer();

	/// Resets the layer for reuse
	void Reset( bool resetVariables );

	///Sets the encryption key.  Doing so will activate secure connections
	/// \param[in] key Byte stream for the encryption key
	void SetEncryptionKey( const unsigned char *key );

	/// Set the time, in MS, to use before considering ourselves disconnected after not being able to deliver a reliable packet
	/// Default time is 10,000 or 10 seconds in release and 30,000 or 30 seconds in debug.
	/// \param[in] time Time, in MS
	void SetTimeoutTime( RakNetTime time );

	/// Returns the value passed to SetTimeoutTime. or the default if it was never called
	/// \param[out] the value passed to SetTimeoutTime
	RakNetTime GetTimeoutTime(void);

	/// Packets are read directly from the socket layer and skip the reliability layer because unconnected players do not use the reliability layer
	/// This function takes packet data after a player has been confirmed as connected.
	/// \param[in] buffer The socket data
	/// \param[in] length The length of the socket data
	/// \param[in] systemAddress The player that this data is from
	/// \param[in] messageHandlerList A list of registered plugins
	/// \param[in] MTUSize maximum datagram size
	/// \retval true Success
	/// \retval false Modified packet
	bool HandleSocketReceiveFromConnectedPlayer( const char *buffer, int length, SystemAddress systemAddress, DataStructures::List<PluginInterface*> &messageHandlerList, int MTUSize );

	/// This allocates bytes and writes a user-level message to those bytes.
	/// \param[out] data The message
	/// \return Returns number of BITS put into the buffer
	int Receive( unsigned char**data );

	/// Puts data on the send queue
	/// \param[in] data The data to send
	/// \param[in] numberOfBitsToSend The length of \a data in bits
	/// \param[in] priority The priority level for the send
	/// \param[in] reliability The reliability type for the send
	/// \param[in] orderingChannel 0 to 31.  Specifies what channel to use, for relational ordering and sequencing of packets.
	/// \param[in] makeDataCopy If true \a data will be copied.  Otherwise, only a pointer will be stored.
	/// \param[in] MTUSize maximum datagram size
	/// \param[in] currentTime Current time, as per RakNet::GetTime()
	/// \return True or false for success or failure.
	bool Send( char *data, int numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, unsigned char orderingChannel, bool makeDataCopy, int MTUSize, RakNetTimeNS currentTime );

	/// Call once per game cycle.  Handles internal lists and actually does the send.
	/// \param[in] s the communication  end point
	/// \param[in] systemAddress The Unique Player Identifier who shouldhave sent some packets
	/// \param[in] MTUSize maximum datagram size
	/// \param[in] time current system time
	/// \param[in] messageHandlerList A list of registered plugins
	void Update(  SOCKET s, SystemAddress systemAddress, int MTUSize, RakNetTimeNS time, DataStructures::List<PluginInterface*> &messageHandlerList );

	/// If Read returns -1 and this returns true then a modified packetwas detected
	/// \return true when a modified packet is detected
	bool IsCheater( void ) const;

	/// Were you ever unable to deliver a packet despite retries?
	/// \return true means the connection has been lost.  Otherwise not.
	bool IsDeadConnection( void ) const;

	/// Causes IsDeadConnection to return true
	void KillConnection(void);

	/// Sets the ping, which is used by the reliability layer to determine how long to wait for resends.  Mostly for flow control.
	/// \param[in] The ping time.

	/// Get Statistics
	/// \return A pointer to a static struct, filled out with current statistical information.
	RakNetStatistics * const GetStatistics( void );

	///Are we waiting for any data to be sent out or be processed by the player?
	bool IsDataWaiting(void);
	bool AreAcksWaiting(void);

	// Set outgoing lag and packet loss properties
	void ApplyNetworkSimulator( double _maxSendBPS, RakNetTime _minExtraPing, RakNetTime _extraPingVariance );

	/// Returns if you previously called ApplyNetworkSimulator
	/// \return If you previously called ApplyNetworkSimulator
	bool IsNetworkSimulatorActive( void );

	void SetSplitMessageProgressInterval(int interval);
	RakNetTimeNS GetLastTimeBetweenPacketsIncrease(void) const;
	RakNetTimeNS GetLastTimeBetweenPacketsDecrease(void) const;
	RakNetTimeNS GetAckPing(void) const;
	/// True when the peer has not acknowledged anything within timeoutTime.
	bool AckTimeout( RakNetTimeNS curTime );
	/// True when anything is queued to send, awaiting acknowledgement or pending resend.
	bool IsOutgoingDataWaiting(void);
	void SetUnreliableTimeout(RakNetTime timeoutMS);

private:

	/// Generates a datagram (coalesced packets)
	/// \param[out] output The resulting BitStream
	/// \param[in] Current MTU size
	/// \param[out] reliableDataSent Set to true or false as a return value as to if reliable data was sent.
	/// \param[in] time Current time
	/// \param[in] systemAddress Who we are sending to
	/// \param[in] messageHandlerList A list of registered plugins
	/// \return The number of messages sent
	bool GenerateDatagram( RakNet::BitStream *output, int MTUSize, bool *reliableDataSent, RakNetTimeNS time, SystemAddress systemAddress, DataStructures::List<PluginInterface*> &messageHandlerList );

	/// Send the contents of a bitstream to the socket
	/// \param[in] s The socket used for sending data
	/// \param[in] systemAddress The address and port to send to
	/// \param[in] bitStream The data to send.
	void SendBitStream( SOCKET s, SystemAddress systemAddress, RakNet::BitStream *bitStream );

	///Parse an internalPacket and create a bitstream to represent this dataReturns number of bits used
	int WriteToBitStreamFromInternalPacket( RakNet::BitStream *bitStream, const InternalPacket *const internalPacket, RakNetTimeNS curTime );

	/// Parse a bitstream and create an internal packet to represent this data
	InternalPacket* CreateInternalPacketFromBitStream( RakNet::BitStream *bitStream, RakNetTimeNS time );

	/// Does what the function name says

	/// Acknowledge receipt of the packet with the specified messageNumber
	void SendAcknowledgementPacket( const MessageNumberType messageNumber, RakNetTimeNS time );

	/// This will return true if we should not send at this time
	bool IsSendThrottled( int MTUSize );

	/// We lost a packet
	void UpdateWindowFromPacketloss( RakNetTimeNS time );

	/// Increase the window size
	void UpdateWindowFromAck( RakNetTimeNS time );

	/// Parse an internalPacket and figure out how many header bits would be written.  Returns that number
	int GetBitStreamHeaderLength( const InternalPacket *const internalPacket );

	/// Get the SHA1 code
	void GetSHA1( unsigned char * const buffer, unsigned int nbytes, char code[ SHA1_LENGTH ] );

	/// Check the SHA1 code
	bool CheckSHA1( char code[ SHA1_LENGTH ], unsigned char * const buffer, unsigned int nbytes );

	/// Search the specified list for sequenced packets on the specified ordering channel, optionally skipping those with splitPacketId, and delete them
	void DeleteSequencedPacketsInList( unsigned char orderingChannel, DataStructures::List<InternalPacket*>&theList, int splitPacketId = -1 );

	/// Search the specified list for sequenced packets with a value less than orderingIndex and delete them
	void DeleteSequencedPacketsInList( unsigned char orderingChannel, DataStructures::Queue<InternalPacket*>&theList );

	/// Returns true if newPacketOrderingIndex is older than the waitingForPacketOrderingIndex
	bool IsOlderOrderedPacket( OrderingIndexType newPacketOrderingIndex, OrderingIndexType waitingForPacketOrderingIndex );

	/// Split the passed packet into chunks under MTU_SIZE bytes (including headers) and save those new chunks
	void SplitPacket( InternalPacket *internalPacket, int MTUSize );

	/// Insert a packet into the split packet list
	void InsertIntoSplitPacketList( InternalPacket * internalPacket, RakNetTimeNS time );

	/// Take all split chunks with the specified splitPacketId and try to reconstruct a packet. If we can, allocate and return it.  Otherwise return 0
	InternalPacket * BuildPacketFromSplitPacketList( SplitPacketIdType splitPacketId, RakNetTimeNS time );

	/// Delete any unreliable split packets that have long since expired
	void DeleteOldUnreliableSplitPackets( RakNetTimeNS time );

	/// Creates a copy of the specified internal packet with data copied from the original starting at dataByteOffset for dataByteLength bytes.
	/// Does not copy any split data parameters as that information is always generated does not have any reason to be copied
	InternalPacket * CreateInternalPacketCopy( InternalPacket *original, int dataByteOffset, int dataByteLength, RakNetTimeNS time );

	/// Get the specified ordering list
	DataStructures::LinkedList<InternalPacket*> *GetOrderingListAtOrderingStream( unsigned char orderingChannel );

	/// Add the internal packet to the ordering list in order based on order index
	void AddToOrderingList( InternalPacket * internalPacket );

	/// Inserts a packet into the resend list in order
	void InsertPacketIntoResendList( InternalPacket *internalPacket, RakNetTimeNS time, bool makeCopyOfInternalPacket, bool firstResend );

	/// Memory handling
	void FreeMemory( bool freeAllImmediately );

	/// Memory handling
	void FreeThreadedMemory( void );

	/// Memory handling
	void FreeThreadSafeMemory( void );

	// Initialize the variables
	void InitializeVariables( void );

	/// Given the current time, is this time so old that we should consider it a timeout?
	bool IsExpiredTime(unsigned int input, RakNetTimeNS currentTime) const;

	// Make it so we don't do resends within a minimum threshold of time

	/// Does this packet number represent a packet that was skipped (out of order?)
	//unsigned int IsReceivedPacketHole(unsigned int input, RakNetTime currentTime) const;

	/// Skip an element in the received packets list
	//unsigned int MakeReceivedPacketHole(unsigned int input) const;

	/// How many elements are waiting to be resent?
	unsigned int GetResendListDataSize(void) const;

	/// Update all memory which is not threadsafe
	void UpdateThreadedMemory(void);

	void CalculateHistogramAckSize(void);

	DataStructures::List<DataStructures::LinkedList<InternalPacket*>*> orderingList;
	DataStructures::Queue<InternalPacket*> outputQueue;
	DataStructures::RangeList<MessageNumberType> acknowlegements;
	int splitMessageProgressInterval;
	RakNetTimeNS unreliableTimeout;
	
	DataStructures::BPlusTree<MessageNumberType, InternalPacket*, RESEND_TREE_ORDER> resendList;
	DataStructures::Queue<InternalPacket*> resendQueue;
	
	DataStructures::Queue<InternalPacket*> sendPacketSet[ NUMBER_OF_PRIORITIES ];
    DataStructures::OrderedList<SplitPacketIdType, SplitPacketChannel*, SplitPacketChannelComp> splitPacketChannelList;
	MessageNumberType sendMessageNumberIndex;
	//unsigned int windowSize;
	RakNetTimeNS lastAckTime;
	RakNet::BitStream updateBitStream;
	OrderingIndexType waitingForOrderedPacketWriteIndex[ NUMBER_OF_ORDERED_STREAMS ], waitingForSequencedPacketWriteIndex[ NUMBER_OF_ORDERED_STREAMS ];
	// Used for flow control (changed to regular TCP sliding window)
	// unsigned int maximumWindowSize, bytesSentSinceAck;
	// unsigned int outputWindowFullTime; // under linux if this last variable is on the line above it the delete operator crashes deleting this class!

	// STUFF TO NOT MUTEX HERE (called from non-conflicting threads, or value is not important)
	OrderingIndexType waitingForOrderedPacketReadIndex[ NUMBER_OF_ORDERED_STREAMS ], waitingForSequencedPacketReadIndex[ NUMBER_OF_ORDERED_STREAMS ];
	bool deadConnection, cheater;
	// unsigned int lastPacketSendTime,retransmittedFrames, sentPackets, sentFrames, receivedPacketsCount, bytesSent, bytesReceived,lastPacketReceivedTime;
	SplitPacketIdType splitPacketId;
	RakNetTime timeoutTime; // How long to wait in MS before timing someone out
	//int MAX_AVERAGE_PACKETS_PER_SECOND; // Name says it all
//	int RECEIVED_PACKET_LOG_LENGTH, requestedReceivedPacketLogLength; // How big the receivedPackets array is
//	unsigned int *receivedPackets;
	unsigned int blockWindowIncreaseUntilTime;
	unsigned int unknown_3e0; // 2007-08: dword at RL+0x3e0 (004c58a0), statistics at +0x3e8
	RakNetStatistics statistics;

	RakNetTimeNS histogramStart;
	unsigned histogramBitsSent;
	DataStructures::Queue<RakNetTimeNS> hasReceivedPacketQueue;
	MessageNumberType receivedPacketsBaseIndex;
	bool resetReceivedPackets;
	RakNetTimeNS lastUpdateTime;
	RakNetTimeNS timeBetweenPackets;
	RakNetTimeNS nextSendTime;
	RakNetTimeNS ackPing;
	unsigned remoteSystemTime;
	bool continuousSend;
	RakNetTimeNS lastTimeBetweenPacketsIncrease;
	RakNetTimeNS lastTimeBetweenPacketsDecrease;
	DataBlockEncryptor encryptor;
	unsigned sendPacketCount, receivePacketCount;
	RakNetTimeNS unknown_778; // 2007-08: qword at RL+0x778 (004c58a0)
	bool freeThreadedMemoryOnNextUpdate;

	/// Memory-efficient receivedPackets algorithm:
	/// receivedPacketsBaseIndex is the packet number we are expecting
	/// Everything under receivedPacketsBaseIndex is a packet we already got
	/// Everything over receivedPacketsBaseIndex is stored in hasReceivedPacketQueue
	/// It stores the time to stop waiting for a particular packet number, where the packet number is receivedPacketsBaseIndex + the index into the queue
	/// If 0, we got got that packet.  Otherwise, the time to give up waiting for that packet.
	/// If we get a packet number where (receivedPacketsBaseIndex-packetNumber) is less than half the range of receivedPacketsBaseIndex then it is a duplicate
	/// Otherwise, it is a duplicate packet (and ignore it).




	///This variable is so that free memory can be called by only the update thread so we don't have to mutex things so much

#ifndef _RELEASE
	struct DataAndTime
	{
		char data[ MAXIMUM_MTU_SIZE ];
		int length;
		RakNetTimeNS sendTime;
	};
	DataStructures::List<DataAndTime*> delayList;

	// Internet simulator
	double maxSendBPS;
	RakNetTime minExtraPing, extraPingVariance;
#endif

	// This has to be a member because it's not threadsafe when I removed the mutexes
	DataStructures::MemoryPool<InternalPacket> internalPacketPool;
};

#endif

/// \file
///
/// This file is part of RakNet Copyright 2003 Kevin Jenkins.
///
/// Usage of RakNet is subject to the appropriate license agreement.
/// Creative Commons Licensees are subject to the
/// license found at
/// http://creativecommons.org/licenses/by-nc/2.5/
/// Single application licensees are subject to the license found at
/// http://www.rakkarsoft.com/SingleApplicationLicense.html
/// Custom license users are subject to the terms therein.
/// GPL license users are subject to the GNU General Public
/// License as published by the Free
/// Software Foundation; either version 2 of the License, or (at your
/// option) any later version.

#include "ReliabilityLayer.h"
#include "GetTime.h"
#include "SocketLayer.h"
#include "PluginInterface.h"
#include "RakAssert.h"
#include "Rand.h"
#include "MessageIdentifiers.h"

// alloca
#ifdef _COMPATIBILITY_1
#elif defined(_WIN32)
#include <malloc.h>
#elif defined(_COMPATIBILITY_2)
#include "Compatibility2Includes.h"
#else
#include <stdlib.h>
#endif

static const int DEFAULT_HAS_RECEIVED_PACKET_QUEUE_SIZE=512;
static const float PACKETLOSS_TOLERANCE=.02f; // What percentile packetloss we are willing to accept as background noise.
static const double MINIMUM_SEND_BPS=14400.0; // Won't go below this send rate
static const double STARTING_SEND_BPS=28800.0; // What send rate to start at.
static const RakNetTimeNS TIME_TO_NEW_SAMPLE=500000; // How many ns to wait before starting a new sample.  This way buffers have time to overflow or relax at the new send rate, if they are indeed going to overflow.
static const RakNetTimeNS MAX_TIME_TO_SAMPLE=250000; // How many ns to sample the connection before deciding on a course of action(increase or decrease throughput). You must be at full send rate the whole time

#ifdef _MSC_VER
#pragma warning( push )
#endif

#ifdef _WIN32
	//#define _DEBUG_LOGGER
	#ifdef _DEBUG_LOGGER
	#include <windows.h>
	#endif
#endif

// FUNCTION: WEBSERVICE 0x101bcbd0
int SplitPacketChannelComp( SplitPacketIdType const &key, SplitPacketChannel* const &data )
{
	if (key < data->splitPacketList[0]->splitPacketId)
		return -1;
	if (key == data->splitPacketList[0]->splitPacketId)
		return 0;
	return 1;
}

//-------------------------------------------------------------------------------------------------------
// Take all split chunks with the specified splitPacketId and try to
//reconstruct a packet.  If we can, allocate and return it.  Otherwise return 0
// Optimized version
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bf6a0
InternalPacket * ReliabilityLayer::BuildPacketFromSplitPacketList( SplitPacketIdType splitPacketId, RakNetTimeNS time )
{
	unsigned i, j;
	unsigned byteProgress;
	InternalPacket * internalPacket;
	bool objectExists;

	i=splitPacketChannelList.GetIndexFromKey(splitPacketId, &objectExists);
#ifdef _DEBUG
	assert(objectExists);
#endif

	if (splitPacketChannelList[i]->splitPacketList.Size()==splitPacketChannelList[i]->splitPacketList[0]->splitPacketCount)
	{
		// Reconstruct
		internalPacket = CreateInternalPacketCopy( splitPacketChannelList[i]->splitPacketList[0], 0, 0, time );
		internalPacket->dataBitLength=0;
		for (j=0; j < splitPacketChannelList[i]->splitPacketList.Size(); j++)
			internalPacket->dataBitLength+=splitPacketChannelList[i]->splitPacketList[j]->dataBitLength;

		internalPacket->data = new unsigned char[ BITS_TO_BYTES( internalPacket->dataBitLength ) ];

		byteProgress=0;
		for (j=0; j < splitPacketChannelList[i]->splitPacketList.Size(); j++)
		{
			memcpy(internalPacket->data+byteProgress, splitPacketChannelList[i]->splitPacketList[j]->data, BITS_TO_BYTES(splitPacketChannelList[i]->splitPacketList[j]->dataBitLength));
			byteProgress+=BITS_TO_BYTES(splitPacketChannelList[i]->splitPacketList[j]->dataBitLength);
		}

		for (j=0; j < splitPacketChannelList[i]->splitPacketList.Size(); j++)
		{
			delete [] splitPacketChannelList[i]->splitPacketList[j]->data;
			internalPacketPool.Release(splitPacketChannelList[i]->splitPacketList[j]);
		}
		delete splitPacketChannelList[i];
		splitPacketChannelList.RemoveAtIndex(i);

		return internalPacket;
	}

	return 0;
}

//-------------------------------------------------------------------------------------------------------
// Creates a copy of the specified internal packet with data copied from the original starting at dataByteOffset for dataByteLength bytes.
// Does not copy any split data parameters as that information is always generated does not have any reason to be copied
//-------------------------------------------------------------------------------------------------------
InternalPacket * ReliabilityLayer::CreateInternalPacketCopy( InternalPacket *original, int dataByteOffset, int dataByteLength, RakNetTimeNS time )
{
	InternalPacket * copy = internalPacketPool.Allocate();
#ifdef _DEBUG
	// Remove accessing undefined memory error
	memset( copy, 255, sizeof( InternalPacket ) );
#endif
	// Copy over our chunk of data

	if ( dataByteLength > 0 )
	{
		copy->data = new unsigned char[ dataByteLength ];
		memcpy( copy->data, original->data + dataByteOffset, dataByteLength );
	}
	else
		copy->data = 0;

	copy->dataBitLength = dataByteLength << 3;
	copy->creationTime = time;
	copy->nextActionTime = 0;
	copy->orderingIndex = original->orderingIndex;
	copy->orderingChannel = original->orderingChannel;
	copy->messageNumber = original->messageNumber;
	copy->priority = original->priority;
	copy->reliability = original->reliability;

	return copy;
}

#ifdef _MSC_VER
#pragma warning( pop )
#endif
