#include <aknappui.h>
class CNLinkAppView;


class CNLinkAppUi : public CAknAppUi {
public:
    void ConstructL();
    void HandleCommandL(TInt aCommand);
    ~CNLinkAppUi();
private:
    CNLinkAppView* iView;
};
