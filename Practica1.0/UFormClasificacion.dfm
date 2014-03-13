object FormClasificacion: TFormClasificacion
  Left = 363
  Top = 118
  Width = 878
  Height = 346
  Caption = 'Clasificacion'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object GridClasificacion: TStringGrid
    Left = 8
    Top = 0
    Width = 721
    Height = 289
    ColCount = 11
    FixedCols = 0
    RowCount = 10
    TabOrder = 0
  end
  object ButtonAnyadirEquipo: TButton
    Left = 736
    Top = 8
    Width = 97
    Height = 33
    Caption = '&Añadir Equipo'
    TabOrder = 1
    OnClick = ButtonAnyadirEquipoClick
  end
  object ButtonBorraEquipo: TButton
    Left = 736
    Top = 48
    Width = 97
    Height = 33
    Caption = '&Borra Equipo'
    TabOrder = 2
    OnClick = ButtonBorraEquipoClick
  end
  object ButtonAnyadirPartido: TButton
    Left = 736
    Top = 88
    Width = 97
    Height = 33
    Caption = 'Añadir &Partido'
    TabOrder = 3
    OnClick = ButtonAnyadirPartidoClick
  end
  object ButtonBorraPartido: TButton
    Left = 736
    Top = 128
    Width = 97
    Height = 33
    Caption = 'B&orrar Partido'
    TabOrder = 4
    OnClick = ButtonBorraPartidoClick
  end
  object ButtonListadoPartidos: TButton
    Left = 736
    Top = 168
    Width = 97
    Height = 33
    Caption = '&Lista de Partidos'
    TabOrder = 5
    OnClick = ButtonListadoPartidosClick
  end
  object ButtonSalir: TButton
    Left = 736
    Top = 232
    Width = 97
    Height = 33
    Caption = '&Salir'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = ButtonSalirClick
  end
  object MainMenu1: TMainMenu
    Left = 840
    Top = 8
    object Archivo1: TMenuItem
      Caption = '&Archivo'
      object AbrirTorneo1: TMenuItem
        Caption = '&Abrir Torneo'
        OnClick = AbrirTorneo1Click
      end
      object GuardarTorneo1: TMenuItem
        Caption = '&Guardar Torneo'
        OnClick = GuardarTorneo1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Salir1: TMenuItem
        Caption = '&Salir'
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 840
    Top = 40
  end
  object SaveDialog1: TSaveDialog
    Left = 840
    Top = 72
  end
end
