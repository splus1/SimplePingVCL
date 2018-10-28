//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	ListBox1->Items->Clear();
	ICMP1->Host = EHost->Text;

	for (int i = 1; i <= 4; i++)
	try {
		ICMP1->Ping();
		Sleep(1000);
		Application->ProcessMessages();
	} catch (...) {
		ListBox1->Items->Add("Ping Failed!");
        Application->ProcessMessages();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ICMP1Reply(TComponent *ASender, TReplyStatus * const AReplyStatus)

{
    UnicodeString Result;
	//Result = "Received " + UnicodeString(AReplyStatus->BytesReceived) +
	//		" bytes from " + AReplyStatus->FromIpAddress +
	//		", time=" + UnicodeString(AReplyStatus->MsRoundTripTime) +
	//		"ms, TTL=" + UnicodeString(AReplyStatus->TimeToLive);
	// Make the output more like Windows CMD ping.exe
    Result = "Reply from " + AReplyStatus->FromIpAddress +
			":  bytes=" + UnicodeString(AReplyStatus->BytesReceived) +
			", time=" + UnicodeString(AReplyStatus->MsRoundTripTime) +
			"ms, TTL=" + UnicodeString(AReplyStatus->TimeToLive);
	ListBox1->Items->Add(Result);
}
//---------------------------------------------------------------------------
