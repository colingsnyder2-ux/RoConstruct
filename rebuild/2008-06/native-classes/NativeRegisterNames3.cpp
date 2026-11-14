// Startup marshaller initialization body at 0041bc40.
class Marshaller;
Marshaller* acquireMarshaller();
extern Marshaller* htmlMarshaller;

void nativeRegisterNames3()
{
	htmlMarshaller = acquireMarshaller();
}
