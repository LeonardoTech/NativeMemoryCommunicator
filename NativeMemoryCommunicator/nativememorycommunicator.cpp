#include "nativememorycommunicator.h"

NativeMemoryCommunicator::NativeMemoryCommunicator()
{

}

NativeMemoryCommunicator::~NativeMemoryCommunicator()
{

}

void NativeMemoryCommunicator::SendMessages(const QString& msg)
{
	//m_communicator->sendMsg(msg.toStdWString());
}

void NativeMemoryCommunicator::EmitRecivedMsg(const QString& msg)
{
	//emit RecivedMessage(msg);
}