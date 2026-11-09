/**
 @file pingtest/main.cpp
 
  pingtest {hostname|ip|--server}

 A simple demo of LightweightConduit and ReliableConduit that
 is also a good first-test for network problems.

 This does not use the protocol of the 'ping' program, but the
 idea is the same (there is no return message from the server,
 however).

 Two protocols are supported, reliable and lightweight.  The reliable
 global variable selects between them.  In each case:  

 1. client opens a Reliable|LightweightConduit
 2. client sends a PingMessage, "hello, server"
 3. server responds with a PingMessage, "hello, client"
 4. client disconnects (reliable only)

 @author Morgan McGuire, matrix@graphics3d.com
 */
#include <G3DAll.h>

/** Change this constant to build a test for ReliableConduit */
static const bool reliable = true;

static const std::string clientGreeting = "hello, server";
static const std::string serverResponse = "hello, client";

enum {PING_PORT=1201};
NetworkDevice networkDevice;

void lightweightServer();
void lightweightClient(const std::string& address);
void reliableServer();
void reliableClient(const std::string& address);
void printHelp();

int main(int argc, char** argv) {
    Log debugLog("log.txt");
    networkDevice.init(&debugLog);
    if ((argc == 2) && (std::string("--server") == argv[1])) {
        if (reliable) {
            reliableServer();
        } else {
            lightweightServer();
        }
    } else if ((argc == 2) && ! beginsWith(argv[1], "--")) {
        if (reliable) {
            reliableClient(argv[1]);
        } else {
            lightweightClient(argv[1]);
        }
    } else {
        printHelp();
    }
    networkDevice.cleanup();
    return 0;
}

// Arbitrary constant greater than 1000 to identify our messages
enum {PingMessage_MSG = 1008};

class PingMessage {
public:

    std::string      text;

    PingMessage() : text("") {}
    PingMessage(const std::string& s) : text(s) {}

    void serialize(BinaryOutput& b) const {
        b.writeString(text);
    }
 
    void deserialize(BinaryInput& b) {
        text = b.readString();
    }
};


void lightweightServer() {
    // Print our network address
 
   	Array<NetAddress> localAddr;
    networkDevice.localHostAddresses(localAddr);

    printf("Running lightweight G3D pingtest server on %s (%s)\n", 
           networkDevice.localHostName().c_str(), 
           localAddr[0].ipString().c_str());

    printf(" Press any key to quit.\n\n");
 
    LightweightConduitRef conduit =
        networkDevice.createLightweightConduit(PING_PORT, true);

    if (conduit.isNull()) {
        printf("Could not create conduit.  Shutting down server.\n");
        return;
    }

    while (! System::consoleKeyPressed()) {
        NetAddress clientAddress;
        switch (conduit->waitingMessageType()) {
        case 0:
            // No message
            System::sleep(0.05);
            break;

        case PingMessage_MSG:
            {
                PingMessage greeting;
                conduit->receive(clientAddress, greeting);
                debugAssert(conduit->ok());
                printf("  Received \"%s\" from %s\n",
                       greeting.text.c_str(),
                       clientAddress.toString().c_str());
                debugAssert(greeting.text == clientGreeting);

                printf("  Sending \"%s\" to %s...",
                       serverResponse.c_str(),
                       clientAddress.toString().c_str());
                debugAssert(conduit->ok());
                conduit->send(clientAddress, PingMessage_MSG, PingMessage(serverResponse));
                printf("sent.\n\n");
                debugAssert(conduit->ok());
            }
            break;

        default:
            // Ignore the message
            conduit->receive(clientAddress);
            printf("  Unknown message type received: %d\n",
                   conduit->waitingMessageType());
        }
    }
}


void reliableServer() {
    // Print our network address
    printf("Running reliable G3D pingtest server on %s\n",
           networkDevice.localHostName().c_str());

    printf(" Press any key to quit.\n\n");
 
    NetListenerRef listener =
        networkDevice.createListener(PING_PORT);

    while (! System::consoleKeyPressed()) {
        NetAddress clientAddress;

        if (listener.isNull() || ! listener->ok()) {
            printf("Listener crashed.  Shutting down server.\n");
            return;
        }

        if (listener->clientWaiting()) {
            ReliableConduitRef conduit =
                listener->waitForConnection();

            printf("  Received connection from %s\n",
                   conduit->address().toString().c_str());

            // Wait for the client to send its greeting
            printf("Waiting for client to send greeting");
            while (! conduit->messageWaiting()) {
                System::sleep(0.1);
                printf(".");
            }
            printf(" got it.\n");
            debugAssert(conduit->ok());
            debugAssert(conduit->waitingMessageType() == PingMessage_MSG);

            PingMessage greeting;
            conduit->receive(greeting);
            
            printf("Client sent \"%s\".\n", greeting.text.c_str());
            debugAssert(greeting.text == clientGreeting);

            printf("Sending \"%s\"...", serverResponse.c_str());
            conduit->send(PingMessage_MSG, PingMessage(serverResponse));
            printf("sent.\n");
            debugAssert(conduit->ok());
            printf("Dropping connection.\n\n");

            // Let the conduit go out of scope, so it 
            // is automatically freed.
        } else {
            System::sleep(0.05);
        }
    }
}


void lightweightClient(const std::string& server) {
    LightweightConduitRef conduit =
        networkDevice.createLightweightConduit();

    NetAddress serverAddress(server, PING_PORT);

    printf("  Sending \"%s\" to %s...", 
           clientGreeting.c_str(),
           serverAddress.toString().c_str());
    conduit->send(serverAddress, PingMessage_MSG, PingMessage(clientGreeting));
    printf("sent.\n");
    debugAssert(conduit->ok());
    
    printf("  Waiting for server response");
    while (! conduit->messageWaiting()) {
        System::sleep(0.1);
        printf(".");
    }
    debugAssert(conduit->waitingMessageType() == PingMessage_MSG);
    printf(" got it.\n");

    PingMessage response;
    NetAddress responseAddress;
    conduit->receive(responseAddress, response);
    debugAssert(serverAddress == responseAddress);

    printf("  Server responded with \"%s\".\n\n",
           response.text.c_str());
    debugAssert(response.text == serverResponse);
}


void reliableClient(const std::string& server) {

    NetAddress serverAddress(server, PING_PORT);

    printf("  Trying to connect to %s\n", serverAddress.toString().c_str());

    ReliableConduitRef conduit =
        networkDevice.createReliableConduit(serverAddress);
    
    if (conduit.isNull() || ! conduit->ok()) {
        printf("  Unable to connect.\n");
        return;
    }

    printf("  Connected successfully.\n\n");

    // Send a hello message
    printf("  Sending \"%s\"... ", clientGreeting.c_str()); 
    conduit->send(PingMessage_MSG, PingMessage(clientGreeting));
    debugAssert(conduit->ok());
    printf("sent.\n");

    // Wait for server response
    printf("  Waiting for server response");
    while (! conduit->messageWaiting()) {
        printf(".");
        System::sleep(0.1);
    }
    printf("got it.\n");
    
    debugAssert(conduit->waitingMessageType() == PingMessage_MSG);
    PingMessage response;
    conduit->receive(response);
    printf("  Server responded: \"%s\".\n", response.text.c_str());
    debugAssert(response.text == serverResponse);
    debugAssert(conduit->ok());
    printf("  Dropping connection.\n");
}


void printHelp() {
    printf("pingtest {machine|--server}\n");
    printf("\n");
    printf("  machine   Host name of the pingtest server.\n");
    printf("  --server  Run a server on this machine.\n");
    printf("\n");
}
