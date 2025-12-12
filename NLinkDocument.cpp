#include "NLinkDocument.h"
#include "NLinkAppUi.h"

CNLinkDocument* CNLinkDocument::NewL(CEikApplication& aApp) {
    CNLinkDocument* self = new (ELeave) CNLinkDocument(aApp);
    self->ConstructL();
    return self;
}

CNLinkDocument::CNLinkDocument(CEikApplication& aApp)
    : CAknDocument(aApp) {}

void CNLinkDocument::ConstructL() {}

CNLinkDocument::~CNLinkDocument() {}

CEikAppUi* CNLinkDocument::CreateAppUiL() {
    return new (ELeave) CNLinkAppUi();
}
