object Form2: TForm2
  Left = 0
  Top = 0
  Caption = #1043#1088#1072#1092#1080#1082#1080' '#1056#1059
  ClientHeight = 674
  ClientWidth = 1119
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Position = poScreenCenter
  OnActivate = FormActivate
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  TextHeight = 13
  object img1: TImage
    Left = 8
    Top = 47
    Width = 1103
    Height = 560
    OnMouseDown = img1MouseDown
    OnMouseMove = img1MouseMove
  end
  object Label1: TLabel
    Left = 492
    Top = 0
    Width = 75
    Height = 13
    Caption = #1057#1091#1090#1082#1080' '#1088#1072#1089#1095#1077#1090#1072
  end
  object Label2: TLabel
    Left = 929
    Top = 613
    Width = 27
    Height = 19
    Alignment = taCenter
    Caption = #1047#1091#1084
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object img2: TImage
    Left = 8
    Top = 47
    Width = 1103
    Height = 560
    Enabled = False
    Transparent = True
  end
  object et1: TEdit
    Left = 464
    Top = 15
    Width = 129
    Height = 21
    NumbersOnly = True
    TabOrder = 0
    Text = '0'
  end
  object dayForwardBtn: TButton
    Left = 1085
    Top = 15
    Width = 26
    Height = 26
    Caption = '>>'
    TabOrder = 1
    OnClick = dayForwardBtnClick
  end
  object dayBackBtn: TButton
    Left = 8
    Top = 15
    Width = 25
    Height = 26
    Caption = '<<'
    TabOrder = 2
    OnClick = dayBackBtnClick
  end
  object et2: TLabeledEdit
    Left = 337
    Top = 15
    Width = 121
    Height = 21
    EditLabel.Width = 77
    EditLabel.Height = 13
    EditLabel.BiDiMode = bdRightToLeftReadingOnly
    EditLabel.Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1050#1040
    EditLabel.ParentBiDiMode = False
    ReadOnly = True
    TabOrder = 3
    Text = ''
  end
  object btnSave: TButton
    Left = 8
    Top = 613
    Width = 129
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1088#1090#1080#1085#1082#1091
    TabOrder = 4
    OnClick = btnSaveClick
  end
  object edtZoom: TEdit
    Left = 929
    Top = 638
    Width = 63
    Height = 21
    NumbersOnly = True
    ReadOnly = True
    TabOrder = 5
    Text = '0'
  end
  object btn2: TButton
    Left = 1054
    Top = 634
    Width = 57
    Height = 25
    Caption = '>>'
    TabOrder = 6
    OnClick = btn2Click
  end
  object btn1: TButton
    Left = 998
    Top = 634
    Width = 57
    Height = 25
    Caption = '<<'
    TabOrder = 7
    OnClick = btn1Click
  end
  object sb1: TScrollBar
    Left = 143
    Top = 613
    Width = 780
    Height = 17
    PageSize = 0
    TabOrder = 8
    OnChange = sb1Change
  end
  object spd1: TSavePictureDialog
    Filter = 'Portable Network Graphics|*.png'
    OnCanClose = spd1CanClose
    Left = 1048
  end
end
