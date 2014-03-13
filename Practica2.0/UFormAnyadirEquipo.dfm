object FormAnyadirEquipo: TFormAnyadirEquipo
  Left = 382
  Top = 222
  Width = 479
  Height = 194
  Caption = 'Añadir Equipo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 40
    Width = 93
    Height = 13
    Caption = 'Nombre del Equipo:'
  end
  object EditNombreEquipo: TEdit
    Left = 128
    Top = 40
    Width = 305
    Height = 21
    TabOrder = 0
  end
  object ButtonAnyadirEquipo: TButton
    Left = 104
    Top = 96
    Width = 113
    Height = 33
    Caption = '&Añadir'
    TabOrder = 1
    OnClick = ButtonAnyadirEquipoClick
  end
  object ButtonCancelar: TButton
    Left = 248
    Top = 96
    Width = 113
    Height = 33
    Caption = '&Cancelar'
    TabOrder = 2
    OnClick = ButtonCancelarClick
  end
end
