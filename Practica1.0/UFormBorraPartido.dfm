object FormBorrarPartido: TFormBorrarPartido
  Left = 192
  Top = 110
  Width = 430
  Height = 265
  Caption = 'Borrar Partidos'
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
    Left = 40
    Top = 56
    Width = 68
    Height = 13
    Caption = 'Equipo Local :'
  end
  object Label2: TLabel
    Left = 40
    Top = 96
    Width = 82
    Height = 13
    Caption = 'Equipo Visitante :'
  end
  object ComboBoxLocal: TComboBox
    Left = 136
    Top = 56
    Width = 217
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = 'Elige equipo local'
  end
  object ComboBoxVisitante: TComboBox
    Left = 136
    Top = 96
    Width = 217
    Height = 21
    ItemHeight = 13
    TabOrder = 1
    Text = 'Elige equipo visitante'
  end
  object ButtonBorrar: TButton
    Left = 64
    Top = 144
    Width = 121
    Height = 33
    Caption = '&Borrar'
    TabOrder = 2
    OnClick = ButtonBorrarClick
  end
  object ButtonCancelar: TButton
    Left = 200
    Top = 144
    Width = 121
    Height = 33
    Caption = '&Cancelar'
    TabOrder = 3
    OnClick = ButtonCancelarClick
  end
end
