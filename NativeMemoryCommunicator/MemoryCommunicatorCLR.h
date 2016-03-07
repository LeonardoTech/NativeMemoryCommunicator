#ifndef __MEMORY_COMMUNICATOR_H__
#define __MEMORY_COMMUNICATOR_H__

#include <string>
class NativeMemoryCommunicator;

namespace Memory
{
	using namespace System;
	using namespace System::Collections::Generic;
	//using namespace System::IO::MemoryMappedFiles;
	using namespace System::IO;
	using namespace System::Threading::Tasks;
	using namespace MemoryMappedFileManager;

	public ref class MemoryCommunicator
	{
	public:

		MemoryCommunicator(NativeMemoryCommunicator* native) :m_comm(native)
		{

		}

		void Communicate();

		void CommunicateTask();

		void communicator_DataReceived(Object^ sender, MemoryMappedDataReceivedEventArgs^ e);
		void sendMsg(std::wstring msg);
	private:
		NativeMemoryCommunicator* m_comm;
		MemoryMappedFileCommunicator^ communicator;
	};
}

#endif // __MEMORY_COMMUNICATOR_H__