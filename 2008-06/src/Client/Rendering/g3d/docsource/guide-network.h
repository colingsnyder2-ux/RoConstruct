/** @page guidenetwork Networking with G3D

  \htmlonly
<TABLE BORDER=0 WIDTH=80%><TR><TD><I><FONT FACE="Arial">
<A HREF="guideopengl.html"><IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
Using OpenGL with G3D</A></I></FONT></TD><TD ALIGN=RIGHT><FONT FACE="Arial"><I>
<A HREF="guidevar.html">
Vertex Arrays <IMG SRC="forwardarrow.gif" BORDER=0 ALIGN=MIDDLE></A></I></FONT></TD></TR></TABLE>
\endhtmlonly

This manual section is intended to give a brief overview of networking in general, and then decribe how to use the concepts
within a G3D application, and the helper classes that are provided to the developer.

@section concepts Concepts in Networking

Before developing a networking application, it is important to understand a few basic concepts. This section will briefly
cover the important concepts that should be known. However, it is intended to be a "10,000 foot" view of networking, for a more
indepth view on networking and it's application to Games Development, it is recommended that the developer consult other textbooks
and resources as required.<br />
The main class used for networking in G3D is G3D::NetworkDevice, which wraps the low level sockets and provides easy access for
the programmer. <br />
<br />
<strong>Local Area Network vs Wide Area Network (LAN vs WAN)</strong><br />
This is perhaps the most important aspect of network development to take into consideration,
where the application will be deployed. <br />
A Local Area Network is a high bandwidth, low latency connection between nodes on the network.
This is usually created using ethernet connections, within the same building, such as a home network or an office infrastructure.
Such a connection is usually highly reliable, with low likelihood of missing data<br />
A Wide Area Network is usually characterised as having low bandwidth, high latency connections between nodes,
the exact opposite to the LAN. This type of connection usually has to be treated as highly unreliable, as the chance of missing
data in such a widespread and hetrogenous environment is quite high. <br />
<br />
<strong>Reliable vs Unreliable (TCP vs UDP)</strong><br />
Within a network, there are two types of protocol that can be used in carrying out network communications.<br>
TCP is the more reliable of the two, containing various methods to ensure that both data arrives, and that the data arrives
in the correct order. However, this creates extra overhead, and therefore is slightly slower in use.<br />
In G3D, TCP is used with the G3D::ReliableConduit class.
UDP is the least reliable of the two protocols, it simply transmits the data without caring about either it's arrival
or whether the data will arrive in the same order as it was transmitted. The main advantage of this type of transmission
is that it is faster than TCP, and simpler to implement.<br />
This is used with the G3D::LightweightConduit class. <br />
<br />
<strong>Messages</strong><br />
In network programming, the communications themselves that are transmitted over the network are called 'messages'.
Each message is broken down into packets, and transmitted over the appropriate protocol. In designing a network based program
it is important that the messages are agreed correctly, and all possible eventualities are covered.
<br />
<br />
<strong>Serialization</strong><br />
Serialization is a technique of converting objects into a form that can easily be transmitted,
either across a network or to disk. Obviously, this is useful in network programming as it allows for entire objects
to be easily transmitted across a network without a need for writing low level communication code.
With G3D, any object that can be seralized or deserialized can be used with the network serializers, converting the object
into messages that can be transmitted to another network node.<br />
<br />
<strong>Discovery</strong><br />
G3D supports automatic discovery of servers on the network. This is achieved using the G3D::DiscoveryClient and G3D::DiscoveryServer
 classes. The use of these classes is described below.<br />

@section codesamples Code Samples

<strong>Network Discovery</strong><br />
For much more indepth coverage and code sample, please see the Network Demo in the G3D directory.<br />
To use the network discovery with G3D, first a server must be created that listens for client connections:
<PRE>

    advertisement.name = app->networkDevice->localHostName();
    discoveryServer.init(app->networkDevice, &app->discoverySettings, &advertisement);
    listener = app->networkDevice->createListener(GAME_PORT);

</PRE>

Servers use the G3D::DiscoveryAdvertisement class to tell clients about themselves, this should be inherited
 from the base class, and the methods overidden.<br />

This code creates a G3D::DiscoveryServer, and a network listener on the given port. <br />
The listener will wait for clients to connect, and then deal with them, such as given in the code below.
This code is best places in an onNetwork() method of a GApp.
<PRE>

    discoveryServer.doNetwork();

    if (listener->clientWaiting()) {
		//if there is a client waiting to connect, deal with it
        acceptIncomingClient();
    }


</PRE>
<br />
To connect to a server, the G3D::DiscoveryClient must be used. Set up is fairly simple:
<PRE>
discoveryClient.init(app->networkDevice, &app->discoverySettings);
</PRE>
To discover servers, run discoveryClient.doNetwork(); <br />
The DiscoveryClient builds up a list of avaliable servers in the serverList array variable. These
can then be used to connect to (sample from the Network Demo):

<PRE>

	client.selectedServer = browse.selectedServer;
	client.selectedServer.address = NetAddress(client.selectedServer.address.ip(), GAME_PORT);

</PRE>
<br />

<strong>Network Communication</strong><br />
This part will cover using a ReliableConduit, although a LightweightConduit is very similar,
the only major difference in it's use is that it does not have to be disconnected, and LightweightConduit
 messages must be explicitly checked for type. (see contrib/pingtest)<br />
Creating a Server:
<PRE>

NetworkDevice networkDevice;
networkDevice.init();

NetListenerRef listener = networkDevice.createListener(PING_PORT);

        //main loop
        while (true)
        {
			NetAddress clientAddress;
			if (listener->clientWaiting())
			{
				ReliableConduitRef conduit = listener->waitForConnection();
			}
			//while there isn't a message
			while (! conduit->messageWaiting() )
			{
				System::sleep(0.1);
			}
			//receieve a message
			conduit->receive(messageID);
			//send a reply
			conduit->send(messageID, message);
			// Let the conduit go out of scope, so it
            // is automatically freed.
		}


</PRE>
This server code will create a listener and sit and wait for a client to connect and send a message.<br />
Creating a client:
<PRE>

NetAddress serverAddress(server, PING_PORT);
ReliableConduitRef conduit = networkDevice.createReliableConduit(serverAddress);

conduit->send(PingMessage_MSG, PingMessage(clientGreeting));

while (! conduit->messageWaiting())
{
       System::sleep(0.1);
}

conduit->receive(response);
</PRE>
*/