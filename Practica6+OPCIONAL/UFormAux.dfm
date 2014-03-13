object FormAux: TFormAux
  Left = 192
  Top = 124
  Width = 281
  Height = 187
  Caption = 'FormAux'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ButtonAceptar: TButton
    Left = 24
    Top = 72
    Width = 89
    Height = 33
    Caption = '&Aceptar'
    TabOrder = 1
    OnClick = ButtonAceptarClick
  end
  object ButtonCancelar: TButton
    Left = 128
    Top = 72
    Width = 89
    Height = 33
    Caption = '&Cancelar'
    TabOrder = 2
    OnClick = ButtonCancelarClick
  end
  object Edit: TEdit
    Left = 32
    Top = 32
    Width = 177
    Height = 21
    TabOrder = 0
  end
end
