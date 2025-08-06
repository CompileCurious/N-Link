#include <eikstart.h>
#include "NLinkAppUi.h"

class CNLinkApplication : public CAknApplication {
public:
    TUid AppUid() const { return TUid::Uid(0xE1234567); }
    CApaDocument* CreateDocumentL() { return new (ELeave) CAknDocument(*this); }
};

LOCAL_C CApaApplication* NewApplication() {
    return new CNLinkApplication;
}

GLDEF_C TInt E32Main() {
    return EikStart::RunApplication(NewApplication);
}
