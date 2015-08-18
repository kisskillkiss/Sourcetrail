#ifndef FEATURE_CONTROLLER_H
#define FEATURE_CONTROLLER_H

#include "utility/messaging/MessageListener.h"
#include "utility/messaging/type/MessageActivateEdge.h"
#include "utility/messaging/type/MessageActivateFile.h"
#include "utility/messaging/type/MessageActivateNode.h"
#include "utility/messaging/type/MessageActivateTokenLocation.h"
#include "utility/messaging/type/MessageSearch.h"
#include "utility/messaging/type/MessageSwitchColorScheme.h"
#include "utility/messaging/type/MessageZoom.h"

#include "component/controller/Controller.h"

class StorageAccess;

class FeatureController
	: public Controller
	, public MessageListener<MessageActivateEdge>
	, public MessageListener<MessageActivateFile>
	, public MessageListener<MessageActivateNode>
	, public MessageListener<MessageActivateTokenLocation>
	, public MessageListener<MessageSearch>
	, public MessageListener<MessageSwitchColorScheme>
	, public MessageListener<MessageZoom>
{
public:
	FeatureController(StorageAccess* storageAccess);
	~FeatureController();

private:
	virtual void handleMessage(MessageActivateEdge* message);
	virtual void handleMessage(MessageActivateFile* message);
	virtual void handleMessage(MessageActivateNode* message);
	virtual void handleMessage(MessageActivateTokenLocation* message);
	virtual void handleMessage(MessageSearch* message);
	virtual void handleMessage(MessageSwitchColorScheme* message);
	virtual void handleMessage(MessageZoom* message);

	StorageAccess* m_storageAccess;
};

#endif // FEATURE_CONTROLLER_H