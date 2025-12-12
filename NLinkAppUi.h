#include <aknappui.h>
class CNLinkAppView;


class CNLinkAppUi : public CAknAppUi {
public:
    void ConstructL();
    void HandleCommandL(TInt aCommand);
    void StartBluetoothAsServerL();
    void StartBluetoothAsClientL();
    ~CNLinkAppUi();
private:
    CNLinkAppView* iView;
};
