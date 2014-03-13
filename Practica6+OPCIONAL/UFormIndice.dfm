object FormIndice: TFormIndice
  Left = 611
  Top = 177
  Width = 427
  Height = 571
  Caption = 'Indice'
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
  object Label1: TLabel
    Left = 24
    Top = 16
    Width = 71
    Height = 27
    Caption = 'Indice:'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object MemoIndice: TMemo
    Left = 24
    Top = 56
    Width = 361
    Height = 457
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
  end
end
