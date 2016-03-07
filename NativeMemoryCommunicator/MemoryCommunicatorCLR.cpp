// MemoryMappedFileManagerCLR.cpp : 定义 DLL 应用程序的导出函数。
//

#include "MemoryCommunicatorCLR.h"
#include "NativeMemoryCommunicator.h"
#include "StringUtil.h"

using namespace Memory;

void MemoryCommunicator::Communicate()
{
	System::Threading::Thread^ thread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &MemoryCommunicator::CommunicateTask));
	thread->Start();
}

void Memory::MemoryCommunicator::communicator_DataReceived(Object^ sender, MemoryMappedDataReceivedEventArgs^ e)
{
	System::Console::ForegroundColor = ConsoleColor::Red;
	System::Console::WriteLine(System::Text::Encoding::UTF8->GetString(e->Data));
	System::Console::ForegroundColor = ConsoleColor::Gray;
	std::wstring wstr = StringUtil::ToWstring(System::Text::Encoding::UTF8->GetString(e->Data));
	QString msg = QString::fromStdWString(wstr);
	Memory::MemoryCommunicator^ comm = static_cast<Memory::MemoryCommunicator^>(sender);
	comm->m_comm->EmitRecivedMsg(msg);
}

void Memory::MemoryCommunicator::CommunicateTask()
{
	communicator = gcnew MemoryMappedFileCommunicator("PrintEntityMemoryMappedShare", 4096);

	// This process reads data that begins in the position 2000 and writes starting from the position 0.
	communicator->ReadPosition = 2000;
	communicator->WritePosition = 0;

	// Creates an handler for the event that is raised when data are available in the
	// MemoryMappedFile.
	communicator->DataReceived += gcnew EventHandler<MemoryMappedDataReceivedEventArgs^>(this, &Memory::MemoryCommunicator::communicator_DataReceived);
	communicator->StartReader();

	//bool quit = false;
	//System::Console::WriteLine("Write messages and press ENTER to send (empty to terminate): ");
	//while (!quit)
	//{
	//	String^ message = System::Console::ReadLine();
	//	if (!String::IsNullOrEmpty(message))
	//	{
	//		auto data = System::Text::Encoding::UTF8->GetBytes(message);
	//		communicator->Write(data);
	//	}
	//	else
	//	{
	//		quit = true;
	//	}
	//}
}

void Memory::MemoryCommunicator::sendMsg(std::wstring msg)
{
	String^ message = StringUtil::ToClrString(msg.c_str());
	if (!String::IsNullOrEmpty(message))
	{
		auto data = System::Text::Encoding::UTF8->GetBytes(message);
		communicator->Write(data);
	}
}
