object FormAnyadirPartido: TFormAnyadirPartido
  Left = 278
  Top = 216
  Width = 440
  Height = 228
  Caption = 'Añadir Partido'
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
    Top = 40
    Width = 32
    Height = 13
    Caption = 'Local :'
  end
  object Label2: TLabel
    Left = 40
    Top = 80
    Width = 46
    Height = 13
    Caption = 'Visitante :'
  end
  object Goles: TLabel
    Left = 280
    Top = 40
    Width = 33
    Height = 13
    Caption = 'Goles :'
  end
  object Label3: TLabel
    Left = 280
    Top = 80
    Width = 33
    Height = 13
    Caption = 'Goles :'
  end
  object ComboBoxEquipoCasa: TComboBox
    Left = 96
    Top = 40
    Width = 161
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = 'Elige equipo local'
  end
  object ComboBoxEquipoVisitante: TComboBox
    Left = 96
    Top = 80
    Width = 161
    Height = 21
    ItemHeight = 13
    TabOrder = 1
    Text = 'Elige equipo visitante'
  end
  object EditGolesCasa: TEdit
    Left = 328
    Top = 40
    Width = 65
    Height = 21
    TabOrder = 2
  end
  object EditGolesVisitante: TEdit
    Left = 328
    Top = 80
    Width = 65
    Height = 21
    TabOrder = 3
  end
  object ButtonAnyadir: TButton
    Left = 104
    Top = 136
    Width = 113
    Height = 33
    Caption = '&Añadir'
    TabOrder = 4
    OnClick = ButtonAnyadirClick
  end
  object ButtonCancelar: TButton
    Left = 248
    Top = 136
    Width = 113
    Height = 33
    Caption = '&Cancelar'
    TabOrder = 5
    OnClick = ButtonCancelarClick
  end
end
