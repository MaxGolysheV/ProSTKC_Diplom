object Form4: TForm4
  Left = 0
  Top = 0
  BorderIcons = []
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1075#1088#1072#1092#1080#1082#1086#1074' '#1056#1059
  ClientHeight = 256
  ClientWidth = 306
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OnActivate = FormActivate
  TextHeight = 13
  object btnAcceptSetting: TButton
    Left = 8
    Top = 223
    Width = 145
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 0
    OnClick = btnAcceptSettingClick
  end
  object btnCancelSettings: TButton
    Left = 159
    Top = 223
    Width = 138
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = btnCancelSettingsClick
  end
  object tbXStep: TLabeledEdit
    Left = 8
    Top = 104
    Width = 121
    Height = 21
    EditLabel.Width = 136
    EditLabel.Height = 13
    EditLabel.Caption = #1063#1072#1089#1090#1086#1090#1072' '#1074#1088#1077#1084#1077#1085#1085#1086#1081' '#1096#1082#1072#1083#1099
    NumbersOnly = True
    ReadOnly = True
    TabOrder = 2
    Text = ''
  end
  object etDelta: TLabeledEdit
    Left = 8
    Top = 196
    Width = 121
    Height = 21
    EditLabel.Width = 146
    EditLabel.Height = 13
    EditLabel.Caption = #1044#1077#1083#1100#1090#1072' '#1086#1090#1088#1080#1089#1086#1074#1082#1080' '#1075#1088#1072#1092#1080#1082#1086#1074
    NumbersOnly = True
    TabOrder = 3
    Text = ''
  end
  object rgrp: TRadioGroup
    Left = 8
    Top = 8
    Width = 280
    Height = 75
    Caption = #1050#1086#1084#1087#1086#1085#1074#1082#1072' '#1050#1040' '#1087#1088#1080' '#1087#1086#1084#1086#1097#1080' '#1094#1074#1077#1090#1072
    TabOrder = 4
  end
  object rbRu: TRadioButton
    Left = 16
    Top = 29
    Width = 201
    Height = 17
    Caption = #1055#1086' '#1087#1086#1088#1103#1076#1082#1091' '#1056#1059
    TabOrder = 5
  end
  object rbKa: TRadioButton
    Left = 16
    Top = 52
    Width = 201
    Height = 17
    Caption = #1055#1086' '#1085#1086#1084#1077#1088#1091' '#1050#1040
    TabOrder = 6
  end
  object sb1: TScrollBar
    Left = 8
    Top = 131
    Width = 121
    Height = 17
    Max = 4
    Min = 1
    PageSize = 0
    ParentShowHint = False
    Position = 1
    ShowHint = False
    TabOrder = 7
    OnChange = sb1Change
  end
end
