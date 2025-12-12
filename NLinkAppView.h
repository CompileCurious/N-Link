#include <coecntrl.h>
class CAknTextEditor;
class CAknTextView;
class CChatEngine;

class CNLinkAppView : public CCoeControl {
public:
    void ConstructL();
    void SendMessageL();
    void SetUsernameL();
    void StartBluetoothDiscoveryL();
private:
    CAknTextEditor* iEditor;
    CAknTextView* iLog;
    CChatEngine* iChatEngine;
};
