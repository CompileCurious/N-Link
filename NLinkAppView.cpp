#include "NLinkAppView.h"
#include "ChatEngine.h"
#include <akntexteditor.h>
#include <akntextview.h>
#include <akntextquerydialog.h>

void CNLinkAppView::ConstructL() {
    iChatEngine = CChatEngine::NewL();

    CreateWindowL();

    iEditor = new (ELeave) CAknTextEditor();
    iEditor->SetContainerWindowL(*this);
    iEditor->SetRect(TRect(0, 150, 176, 200));
    iEditor->ActivateL();

    iLog = new (ELeave) CAknTextView();
    iLog->SetContainerWindowL(*this);
    iLog->SetRect(TRect(0, 0, 176, 150));
    iLog->ActivateL();

    SetRect(TRect(0, 0, 176, 200));
    ActivateL();
}

void CNLinkAppView::SendMessageL() {
    TBuf<64> msg;
    iEditor->GetText(msg);
    iChatEngine->SendMessageL(msg);

    iLog->AddTextL(_L("You: "));
    iLog->AddTextL(msg);
    iLog->AddTextL(_L("\n"));
    iEditor->Clear();
}

void CNLinkAppView::SetUsernameL() {
    TBuf<16> input;
    CAknTextQueryDialog* dlg = new (ELeave) CAknTextQueryDialog(input);
    if (dlg->ExecuteLD(R_TEXT_QUERY_DIALOG)) {
        iChatEngine->SetUsernameL(input);
    }
}
