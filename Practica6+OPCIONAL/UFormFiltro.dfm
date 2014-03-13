object FormFiltro: TFormFiltro
  Left = 192
  Top = 124
  Width = 307
  Height = 394
  Caption = 'FormFiltro'
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
    Top = 24
    Width = 61
    Height = 27
    Caption = 'Filtro:'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object MemoFiltro: TMemo
    Left = 24
    Top = 56
    Width = 241
    Height = 289
    ReadOnly = True
    TabOrder = 0
  end
end
