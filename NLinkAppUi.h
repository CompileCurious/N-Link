#include <aknappui.h>
class CNLinkAppView;

class CNLinkAppUi : public CAknAppUi {
public:
    void ConstructL();
    void HandleCommandL(TInt aCommand);
private:
    CNLinkAppView* iView;
};
