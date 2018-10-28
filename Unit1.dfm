object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Simple Ping VCL Example'
  ClientHeight = 299
  ClientWidth = 384
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 10
    Width = 26
    Height = 13
    Caption = 'Host:'
  end
  object EHost: TEdit
    Left = 45
    Top = 8
    Width = 252
    Height = 21
    TabOrder = 0
    Text = 'community.embarcadero.com'
  end
  object Button1: TButton
    Left = 303
    Top = 5
    Width = 75
    Height = 25
    Caption = 'Ping'
    TabOrder = 1
    OnClick = Button1Click
  end
  object ListBox1: TListBox
    Left = 0
    Top = 40
    Width = 384
    Height = 259
    Align = alBottom
    ItemHeight = 13
    TabOrder = 2
    ExplicitWidth = 635
  end
  object ICMP1: TIdIcmpClient
    Protocol = 1
    ProtocolIPv6 = 58
    IPVersion = Id_IPv4
    OnReply = ICMP1Reply
    Left = 328
    Top = 40
  end
end
