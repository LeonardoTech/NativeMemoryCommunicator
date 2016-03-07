#ifndef NATIVEMEMORYCOMMUNICATOR_H
#define NATIVEMEMORYCOMMUNICATOR_H


#include <QString>
#include <QObject>

class NativeMemoryCommunicator :public QObject
{
	Q_OBJECT
public:
	NativeMemoryCommunicator();
	~NativeMemoryCommunicator();


	void SendMessages(const QString& msg);

	void EmitRecivedMsg(const QString& msg);

signals:
	void RecivedMessage(const QString& message);

private:
	//gcroot<Memory::MemoryCommunicator^> m_communicator;
};

#endif // NATIVEMEMORYCOMMUNICATOR_H
