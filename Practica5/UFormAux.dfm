object FormAux: TFormAux
  Left = 355
  Top = 205
  Width = 353
  Height = 237
  Caption = 'FormAux'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 192
    Top = 72
    Width = 113
    Height = 33
    Caption = '&Aceptar'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 192
    Top = 120
    Width = 113
    Height = 33
    Caption = '&Cancelar'
    TabOrder = 1
    OnClick = Button2Click
  end
  object ComboBox: TComboBox
    Left = 24
    Top = 72
    Width = 113
    Height = 21
    ItemHeight = 13
    TabOrder = 2
  end
end
