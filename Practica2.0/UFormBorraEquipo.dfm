object FormBorrarEquipo: TFormBorrarEquipo
  Left = 192
  Top = 110
  Width = 341
  Height = 172
  Caption = 'Borrar Equipo'
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
    Left = 24
    Top = 24
    Width = 257
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = 'Elige equipo'
  end
  object ButtonBorrarEquipo: TButton
    Left = 24
    Top = 80
    Width = 105
    Height = 33
    Caption = '&Borrar Equipo'
    TabOrder = 1
    OnClick = ButtonBorrarEquipoClick
  end
  object ButtonCancelar: TButton
    Left = 168
    Top = 80
    Width = 105
    Height = 33
    Caption = '&Cancelar'
    TabOrder = 2
    OnClick = ButtonCancelarClick
  end
end
