#include "NLinkAppUi.h"
#include "NLinkAppView.h"
#include "NLink.hrh"

void CNLinkAppUi::ConstructL() {
    BaseConstructL();
    iView = new (ELeave) CNLinkAppView();
    iView->SetRect(ClientRect());
    iView->ActivateL();
    AddToStackL(iView);
}

void CNLinkAppUi::HandleCommandL(TInt aCommand) {
    switch (aCommand) {
        case ECmdSend:
            iView->SendMessageL();
            break;
        case ECmdSetUsername:
            iView->SetUsernameL();
            break;
        case EAknSoftkeyExit:
            Exit();
            break;
    }
}
