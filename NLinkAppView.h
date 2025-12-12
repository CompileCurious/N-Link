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
    void StartBluetoothServerL();
    void ShowStatus(const TDesC& aMsg);
    void ShowError(const TDesC& aMsg);
    void ShowPeerUsername(const TDesC& aPeer);
    TBool PromptPassphraseL();
private:
    CAknTextEditor* iEditor;
    CAknTextView* iLog;
    CChatEngine* iChatEngine;
    TBuf<32> iPassphrase;
};
