#ifndef NLINKDOCUMENT_H
#define NLINKDOCUMENT_H

#include <akndoc.h>

class CAknApplication;

class CNLinkDocument : public CAknDocument {
public:
    static CNLinkDocument* NewL(CEikApplication& aApp);
    ~CNLinkDocument();
private:
    CNLinkDocument(CEikApplication& aApp);
    void ConstructL();
    CEikAppUi* CreateAppUiL();
};

#endif // NLINKDOCUMENT_H
