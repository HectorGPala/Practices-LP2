object FormListadoPartidos: TFormListadoPartidos
  Left = 492
  Top = 56
  Width = 389
  Height = 417
  Caption = 'Listado de Partidos'
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
  object ComboBoxEquipo: TComboBox
    Left = 16
    Top = 8
    Width = 265
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = 'Elige un equipo'
    OnChange = ComboBoxEquipoChange
  end
  object GridListadoPartidos: TStringGrid
    Left = 8
    Top = 48
    Width = 337
    Height = 249
    ColCount = 20
    FixedCols = 0
    RowCount = 20
    TabOrder = 1
  end
  object ButtonCancelar: TButton
    Left = 112
    Top = 320
    Width = 121
    Height = 25
    Caption = '&Cancelar'
    TabOrder = 2
    OnClick = ButtonCancelarClick
  end
end
